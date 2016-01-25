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

#define SYNTAX	"Syntax: cloaksight\n"

varargs int cmd_cloaksight(string str) {
	object act_ob;
	string olprompt;
	int i, cloaksight;
   
	act_ob = previous_object();
 
	notify_fail( SYNTAX );
	cloaksight = (int)act_ob->query("cloaksight");
	//No parameter just shift to opposite
	if(cloaksight == 0) {
		act_ob->set("cloaksight", 1);
		write("You can see cloaked creatures.\n");
	}
	else if(cloaksight == 1) {
		act_ob->set("cloaksight", 0);
		write("You can no longer see cloaked creatures.\n");
	}
	return 1;	
}

int help() {

   write( SYNTAX + "\n" +
     "The cloaksight command allows a user to see cloaked creatures\n");
 
return 1; }
 
