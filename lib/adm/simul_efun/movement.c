// This is to wrap movement messages in so that they can be 

#include <ansi.h>
#include <messages.h>

varargs void movement(string msg, object environment) {	
	object me;
	object *contents;
	mixed exclude;
	int i;
	
	if (this_player()) me = this_player();
	else me = previous_object();

	if(objectp(exclude))
		exclude = ({ me, exclude });
	else if(pointerp(exclude))
		exclude += ({ me });
	else if (!exclude)
		exclude = ({ me });
	//Let's make sure any movement messages only appear to people who can see them
	if (me->query("invisible") || me->query("realm")) {
		contents = all_inventory(environment);
		i = sizeof (contents);
		while (i--) {
			if (userp(contents[i])) {
				if (!visible(me, contents[i])) {											
					exclude += ({ contents[i] });
				}
			}
		}
	}
	message(MSG_MOVEMENT, msg, environment, exclude);
}
