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
	set ("short", "The Main Road") ;
	set ("long",
	"A quiet road that leads through town. Here is oldtown. Farther\n"+
	"north are the Golden Horn and Tipsy Chicken. It then continues\n"+
	"on down the hill towards the beach.\n") ;
	set("light", 1);
	set ("exits", ([
		"north" : "/d/seatoncarew/mainroad2",
		"oldtown" : "/d/seatoncarew/oldtown"
	]) ) ;
}
