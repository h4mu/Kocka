/*
============================================================================
 Name        : KockaRajzolo.pan
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : Panic codes
============================================================================
*/

#ifndef __KOCKARAJZOLO_PAN__
#define __KOCKARAJZOLO_PAN__


//  Data Types

enum TKockaRajzoloPanic
    {
    EKockaRajzoloNullPointer
    };


//  Function Prototypes

GLREF_C void Panic(TKockaRajzoloPanic aPanic);


#endif  // __KOCKARAJZOLO_PAN__


