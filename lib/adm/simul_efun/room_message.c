//Wrapper for messages meant to appear in a room
//By specifying the actor and audible, we can determine if it needs to be 
//modified for people who may not be in the same realm

#include <mudlib.h>;



void room_message(string msg, string replaceableName, int audible, object environment, mixed exclude) {
	object *audience;
	object actor;
	string maskedmessage;
	int i;

	if (msg[strlen(msg)-1..strlen(msg)] != "\n")
		msg = msg + "\n";
	
	//If actor was specified, then we'll use it, otherwise it's this player
	actor = this_player();
	
	//If no environment is sent, it's the current environment of the actor
	if (!environment) {
		environment = environment(actor);		
	}

	if (actor->query("realm"))
		maskedmessage = replace_string(msg,"{N}","Someone");
	msg = replace_string(msg,"{N}",replaceableName);

	//basic exclude, make sure this player is in the list, and make sure that we carry over any of the exclude list
	if(objectp(exclude))
		exclude = ({ actor, exclude });
	else if(pointerp(exclude))
		exclude += ({ actor });
	else if (!exclude)
		exclude = ({ actor });

	//Ok, now we do the hard work. We go through each living and determine if or how to display the message to them
	if (environment) {
		audience = all_inventory(environment);
		i = sizeof (audience);
		while (i--) {
			if (userp(audience[i]) && audience[i] != actor) {
				//If they aren't visble, then they are completely excluded
				if (!visible(actor, audience[i])) {	
					exclude += ({ audience[i] });
				}
				//If they are a medium, and it's audible we'll give the masked message					
				if (actor->query("realm") && audience[i]->query("medium") && audible == 1) {
					if (maskedmessage)
						message("say", maskedmessage, audience[i]);
					else
						message("say", msg, audience[i]);
				}					
			}
		}
	}
	message("say", msg, environment, exclude);
}