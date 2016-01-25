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
	set ("short", "The King's Trust") ;
	set ("long",
	"A large building partway down the hill. Outside there is a covered\n"
	"porch that looks out towards the Harbor. Inside is a comfortable\n"
	"sitting room and dining area. In the back are several rooms for\n"
	"travelers to rest.n");
	set("light", 1);
	set ("exits", ([
	]) ) ;
}
