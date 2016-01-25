// Fireball spell. Mobydick, 11-1-92. May be changed in the future.

#include <mudlib.h>
#include <commands.h>

object query_attacker() ;
object *query_attackers() ;

inherit DAEMON ;

varargs int cast_fireball(object target)
{
	this_player()->block_attack(2);
	call_out("fireball_effect",2) ;
}

varargs int cmd_fireball (string str) {

	object target ;
	int sp, cost, skill ;

	if (str!="NONE") {
		target = present(str,environment(this_player())) ;
		if (!target) {
			write ("You are not in combat with anyone.\n") ;
			return 1 ;
		}
		if (target==this_player()) {
			write ("That seems like a pretty bad idea.\n") ;
			return 1 ;
		}
		if (!living(target)) {
			write("Please don't damage the furniture.\n") ;
			return 1 ;
		}
		if ((int)target->query("no_attack")==1) {
			write ("You cannot attack that.\n") ;
			return 1 ;
		}
	}
// If obj==1, it means the call came from an object, not the cast command,
// and we don't want to charge spell point cost.
	sp = this_player()->query("spell_points") ;
	skill = this_player()->query_skill("Combat spells") ;
		cost = 300/(skill+10) ;
		if (sp<cost) {
				write ("You haven't got enough spell points to cast it.\n") ;
				return 1 ;
	}
		this_player()->set ("spell_points", sp-cost) ;
	if (str!="NONE") {
		write ("You attack "+str+"!\n") ;
		this_player()->kill_ob(target) ;
	}
	cast_fireball(target);
	//this_player()->fireball_cast(target) ;
	this_player()->improve_skill("Combat spells", 10) ;
	return 1 ;
}

void fireball_effect() {

int damage, skill, i , hp, flag ;
	object *attackers ;
	object *blocked_obs ;

	attackers = query_attackers() ;
	skill = this_object()->query_skill("Combat spells") ;
	for (i=0;i<sizeof(attackers);i++) {
		if (!present(attackers[i],environment(this_object())) || attackers[i]->query("hit_points")<0) {
			continue ;
		}
		flag = 1 ;
		damage = random(9+skill/6)+8+skill/3 ;
		if(damage) attackers[i]->set("last_attacker");
		attackers[i]->receive_damage(damage) ;
		tell_object(attackers[i],"Suddenly you are hit by a fireball!\n") ;
	}
	blocked_obs = (attackers ? attackers : ({ }) ) + ({ this_object() }) ;
	if (flag==1) {
		tell_object(this_object(),"You cast a fireball!\n") ;
	} else {
		tell_object(this_object(),"You cast a fireball, but it doesn't hit anything.\n") ;
	}
	tell_room(environment(this_object()),this_object()->query("cap_name")+" casts a fireball! But you are outside the effect.\n", blocked_obs) ;
}
