/*
============================================================================
 Name        : Kocka.pan
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : This file contains panic codes.
============================================================================
*/

#ifndef __KOCKA_PAN__
#define __KOCKA_PAN__

/** Kocka application panic codes */
enum TKockaPanics
    {
    EKockaUi = 1
    // add further panics here
    };

inline void Panic(TKockaPanics aReason)
    {
    _LIT(applicationName,"Kocka");
    User::Panic(applicationName, aReason);
    }

#endif // __KOCKA_PAN__
