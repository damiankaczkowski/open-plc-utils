/*====================================================================*
 *   
 *   Copyright (c) 2011 by Qualcomm Atheros.
 *   
 *   Permission to use, copy, modify, and/or distribute this software 
 *   for any purpose with or without fee is hereby granted, provided 
 *   that the above copyright notice and this permission notice appear 
 *   in all copies.
 *   
 *   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL 
 *   WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED 
 *   WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  
 *   THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR 
 *   CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM 
 *   LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, 
 *   NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN 
 *   CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *   
 *--------------------------------------------------------------------*/

/*====================================================================*
 *
 *   signed PLCSelect (struct plc * plc, signed old (struct plc *), signed new (struct plc *));
 *
 *   plc.h
 *
 *   wait for device to start in order to determine chipset then call
 *   the approproate function based on chipset; unfortunately, chipset
 *   detection and selection may not be this simple in the future;
 *
 *.  Atheros Powerline Toolkit for HomePlug AV; 
 *:  Published 2007 by Intellon Corp. ALL RIGHTS RESERVED;
 *;  For demonstration; Not for production use;
 *
 *   Contributor(s):
 *      Charles Maier <cmaier@qualcomm.com>
 *
 *--------------------------------------------------------------------*/

#ifndef PLCSELECT_SOURCE
#define PLCSELECT_SOURCE

#include <stdlib.h>

#include "../plc/plc.h"

signed PLCSelect (struct plc * plc, signed old (struct plc *), signed new (struct plc *)) 

{
	char firmware [PLC_VERSION_STRING];
	if (WaitForStart (plc, firmware, sizeof (firmware))) 
	{
		Failure (plc, PLC_NODETECT);
		exit (1);
	}
	return ((plc->hardwareID < CHIPSET_AR7400)? old (plc): new (plc));
}


#endif
