// hall.c
// The basic start room. Players begin here, and this is where they can find
// out what quests they haven't yet done. Also, people will probably get
// into the habit of hanging out here. Lord knows all the TMI wizards do.
// Created by Mobydick, September 1992.

#include <mudlib.h>

inherit ROOM ;

void create() {
	::create();
	seteuid(getuid()) ;
	set ("short", "The Church") ;
	set ("long",
	"This is the parking lot outside of game. It's an OOG area so you\n"+
	"can feel free to break character here. There are cars spread\n"+
	"throughout the parking lot, and at one end people are smoking\n") ;
	set("light", 1);
	set ("exits", ([
	]) ) ;
}
