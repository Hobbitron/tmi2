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
	set ("short", "Old Town") ;
	set ("long",
	"A small collection of older homes surround a small open space\n"
	"with some tables and a fire pit. Crafters are known to work\n"
	"their trades here during the day and the community gathers to\n"
	"socialize in the evening.\n");
	set("light", 1);
	set ("exits", ([
		"road" : "/d/seatoncarew/mainroad1"
	]) ) ;
}