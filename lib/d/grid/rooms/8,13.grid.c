// A basic grid room, with non-grid exits.
// Mobydick@TMI-2, 9-3-92

#include <mudlib.h>

inherit ROOM ;

void create () {
	::create() ;
	set_outside("Fooland") ;
	set ("short", "In the hills near a cave.") ;
	set ("long",
	"You are walking through rising hills. There is a small cave mouth\n"+
	"here, and a foul smell emanates from within.\n") ;
	set ("exits", ([
	"east" : "/d/grid/rooms/8,14.grid",
	"south" : "/d/grid/rooms/9,13.grid",
	"west" : "/d/grid/rooms/8,12.grid",
	"north" : "/d/grid/rooms/7,13.grid",
	"down" : "/d/Fooland/orccave"
	]) ) ;
}
