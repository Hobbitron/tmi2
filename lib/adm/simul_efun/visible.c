/*
// File:	visible.c
// Mudlib:	TMI-II
// Author:	Pallando
// Real Name:	Douglas Reay
// Syntax:      varargs int visible( object detectee, object detector )
// Returns:     1 if detector may be allowed to know that the detectee exists
//		0 if detector may not penetrate detectee's invisibility.
// Purpose:	Should be called by any command that might let one user know
//              whether another user is logged on.
// Date V1.0:   1992 December 22
//      V1.1:   Ideas about generality from Mobydick.
// Date V2.0:   1994 August 28 - Pallando allows objects to see themselves
*/

#include <uid.h>

varargs int visible( object detectee_obj, object detector_obj )
{

	string detector_euid;
	int detector_rank, detector_realmsight;
	int detectee_vis, detectee_realm;

	if( !detectee_obj ) return 0;
	if( !detector_obj )	{
		detector_euid = "TEMP";
	} else {
		// An object can always find itself.
		if( detector_obj == detectee_obj ) return 1;
		detector_euid = geteuid( detector_obj );
	}

	// Find the detector's rank
	if( detector_obj ) {
		if (wizardp( detector_obj ))
			detector_rank = 2;
		else if (adminp( detector_obj ))
			detector_rank = 3;
		else if (detector_obj->query("cloaksight"))
			detector_rank = 1;
		else
			detector_rank = 0;
	} 

	// Find the detector's realm	
	if( detector_obj ) {
		detector_realmsight = 0;
		if (detector_obj->query("realm"))
			detector_realmsight = detector_obj->query("realm");
		else if (detector_obj->query("umbrasight"))
			detector_realmsight = 1;
		else if (wizardp(detector_obj))
			detector_realmsight = 1;
	} 

// Find the detectee's visibility
	if( objectp( detectee_obj ) ) {
		detectee_vis = detectee_obj-> query( "invisible" );
		//determine realm of detectee
		detectee_realm = detectee_obj->query("realm");
	}
	
	if( hiddenp( detectee_obj ) ) detectee_vis = 4;

// Compare them
  if( detectee_vis > detector_rank) return 0; // detector can't see detectee.
  if (detector_realmsight == 0 && detectee_realm == 1) return 0; //detector is in the realm, and can't see the umbra
  return 1; // detector can see detectee.
}
