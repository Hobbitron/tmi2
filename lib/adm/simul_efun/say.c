// Mobydick added an ANSI reset to this, 12-17-94.
// The idea is to prevent people from screwing up the color schemes of
// others with their text. I'm not sure if this is going to work. Feel
// free to remove it if it doesn't, as long as you install something
// else that works Better.

#include <ansi.h>
#include <mudlib.h>
#include <uid.h>
#include <config.h>
#include <writef.h>

varargs void say(string msg, mixed exclude, int audible) {
	object me, env;
	object *contents;
	int i;

	if (this_player()) me = this_player();
	else me = previous_object();
	if (!env) env = environment(me);
  // msg+= NOR;  // This gave lots of ansi chars,
  // for people with no ansi handling.
 
	if(objectp(exclude))
		exclude = ({ me, exclude });
	else if(pointerp(exclude))
		exclude += ({ me });
	else if (!exclude)
		exclude = ({ me });	
	//Let's make sure any say messages only appear to people who can see them
	if (env && me->query("realm") == 1) {
		contents = all_inventory(env);
		i = sizeof (contents);
		if (i > 2) {
			while (i--) {
				if (userp(contents[i])) {
					if (!visible(me, contents[i])) {											
						exclude += ({ contents[i] });
					}
				}
			}
		}
	}
	message("say", msg, env, exclude);
}
