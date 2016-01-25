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

#define SYNTAX	"Syntax: gauntletwalk\n"

varargs int cmd_medium(string str) {
	object act_ob;
	string olprompt;
	int i, medium;
   
	act_ob = previous_object();
 
	notify_fail( SYNTAX );
	medium = (int)act_ob->query("medium");
	//No parameter just shift to opposite
	if (!str || str == "") {
		if(medium == 0) {
			act_ob->set("medium", 1);
			write("You can hear spirits.\n");
		}
		else if(medium == 1) {
			act_ob->set("medium", 0);
			write("You no longer can hear spirits.\n");
		}
		return 1;
	} 
	return 0;
}

int help() {

   write( SYNTAX + "\n" +
     "The gauntletwalk command allows a user to change the realm that they\n" +
     "are currently in. You can specify the realm \(\"umbra\", \"realm\"\),\n" +
     "get the \"status\" of the realm you're in, or just use \"gauntletwalk\" to\n"+
     "simply shift into the opposite realm.\n");
 
return 1; }
 
