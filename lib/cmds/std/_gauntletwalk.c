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

#define SYNTAX	"Syntax: gauntletwalk [status | realm | umbra]\n"

varargs int cmd_gauntletwalk(string str) {
	object act_ob;
	string olprompt;
	int i, realm;
   
	act_ob = previous_object();
 
	notify_fail( SYNTAX );
	realm = (int)act_ob->query("realm");
	//No parameter just shift to opposite
	if (!str || str == "") {
		if(realm == 0) {
			act_ob->set("realm", 1);
			write("You step into the umbra.\n");
		}
		else if(realm == 1) {
			act_ob->set("realm", 0);
			write("You step into the realm.\n");
		}
		return 1;
	} 
	//Status just print where they are
	else if (str == "status") {
		if(realm == 0)
			write("You are presently in the realm.\n");
		else if(realm == 1) 
			write("You are presently in the umbra.\n");
		return 1;
	}
	//Specify realm, don't allow if they're already there
	else if (str == "realm")
	{
		if(realm == 0)
			write("You are already in the realm.\n");
		else {
			act_ob->set("realm", 0);
			write("You step into the realm.\n");
		}		
		return 1;
	}
	//specify umbra, don't allow if they're already there
	else if (str == "umbra")
	{
		if(realm == 1)
			write("You are already in the umbra.\n");
		else {
			act_ob->set("realm", 1);
			write("You step into the umbra.\n");
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
 
