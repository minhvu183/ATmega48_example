#ifndef MAIN_H
#define MAIN_H

# define F_CPU 8000000UL

#include <xc.h>
#include <util/delay.h> 
#include "lib_io.h"

//FUSES = {
//	.low = 0xE2, // LOW {SUT_CKSEL=INTRCOSC_8MHZ_6CK_14CK_65MS_DEFAULT, CKOUT=CLEAR, CKDIV8=CLEAR}
//	.high = 0xDF, // HIGH {BODLEVEL=DISABLED, EESAVE=CLEAR, WDTON=CLEAR, SPIEN=SET, DWEN=CLEAR, RSTDISBL=CLEAR}
//	.extended = 0xFF, // EXTENDED {SELFPRGEN=CLEAR}
//};
//
//LOCKBITS = 0xFF; // {LB=NO_LOCK}


#endif