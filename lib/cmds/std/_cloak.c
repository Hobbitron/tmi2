// _invis.c
// Command to allow wizards to become invisible.
// Two levels of invisibility are offered: invisibility to player and
// invisibility to wizards. Admins can always see you regardless of you
// invisibility level
// Written by Mobydick@TMI-2, 10-3-92. Loosely based on an existing
// version whose original author is unknown.
// Modified by Wark@TMI-2, 12-4-92 to allow saving of prompts.
// Modified by Pallando 93-02-13 to delete oldprompt when not needed and
// 				 to include your oldprompt in the new one.
// Modified by Watcher 93-03-27 to allow number arguments, adding in
//	mvis and minvis display messages, and doing a general cleanup.

#include <mudlib.h>

inherit DAEMON;

#define SYNTAX	"Syntax: cloak\n"

varargs int cmd_cloak(string str) {
	object act_ob;
	string olprompt;
	int i, cloak;
   
	act_ob = previous_object();
 
	notify_fail( SYNTAX );
	cloak = (int)act_ob->query("invisible");
	//No parameter just shift to opposite
	if(cloak == 0) {
		write("You cloak yourself.\n");
		say(sprintf("%s vanishes from sight\n", act_ob->query("cap_name")));
		act_ob->set("invisible", 1);		
	}
	else if(cloak == 1) {
		act_ob->set("invisible", 0);
		say(sprintf("%s appears fron nothing\n", act_ob->query("cap_name")));
		write("You remove your cloak.\n");
	}
	else {
		write("You are already hidden more than cloak will offer.\n");
	}
	return 1;
}

int help() {

   write( SYNTAX + "\n" +
     "The cloak command allows a user to hide themselves from sight\n");
 
return 1; }
 
