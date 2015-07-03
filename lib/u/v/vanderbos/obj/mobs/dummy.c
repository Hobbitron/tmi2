// orc.c
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c
// Mobydick, 10-2-92.

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "a dummy") ;
	set ("long", "A wooden training dummy\n") ;
	set ("id", ({ "dummy" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_name ("dummy") ;
	set ("gender", "neuter") ;
	enable_commands() ;
	set_living_name("dummy") ;
	set ("hit_points", 999999) ;
	set ("max_hp",999999) ;
	set ("attack_strength", 1) ;
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "paws") ;
	set ("stat/strength", 0) ;
	set ("stat/dexterity", 0) ;
	set_skill("attack", 0, "strength") ;
	set_skill("defense", 10, "dexterity") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
}
