#include <mudlib.h>

inherit ROOM ;

void create() {
	::create();
	seteuid(getuid()) ;
	set ("short", "Golden Horn Porch") ;
	set ("long",
	"This is the parking lot outside of game. It's an OOG area so you\n"+
	"can feel free to break character here. There are cars spread\n"+
	"throughout the parking lot, and at one end people are smoking\n") ;
	set("light", 1);
	set ("exits", ([
		"tavern" : "/d/seatoncarew/goldenhorn",
		"road" : "/d/seatoncarew/mainroad2"
	]) ) ;
}
