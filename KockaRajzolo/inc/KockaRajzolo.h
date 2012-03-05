/*
============================================================================
 Name        : KockaRajzolo.h
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : KockaRajzolo.h - CKockaRajzolo class header
============================================================================
*/

// This file defines the API for KockaRajzolo.dll

#ifndef __KOCKARAJZOLO_H__
#define __KOCKARAJZOLO_H__


//  Include Files

#include <e32base.h>    // CBase
#include <e32std.h>     // TBuf


//  Constants

const TInt KKockaRajzoloBufferLength = 15;
typedef TBuf<KKockaRajzoloBufferLength> TKockaRajzoloExampleString;


//  Class Definitions
class CKockaAppView;

class CKockaRajzolo : public CBase
    {
    public:     // new functions
        IMPORT_C static CKockaRajzolo* NewL(CKockaAppView*);
        IMPORT_C static CKockaRajzolo* NewLC(CKockaAppView*);
        IMPORT_C ~CKockaRajzolo();

    public:     // new functions, example API
        IMPORT_C TVersion Version() const;
        IMPORT_C void ExampleFuncAddCharL(const TChar& aChar);
        IMPORT_C void ExampleFuncRemoveLast();
        IMPORT_C const TPtrC ExampleFuncString() const;
        IMPORT_C void Rajzol();
        

    private:    // new functions
        CKockaRajzolo();
        void ConstructL(CKockaAppView*);
        static TInt Callback(TAny* aPtr);

    private:    // data
        TKockaRajzoloExampleString* iString;
        CPeriodic* iPeriodic;
        CKockaAppView* iView;
        TInt iX;
        TInt iY;
        TInt iIncX;
        TInt iIncY;
    };

#include "KockaAppView.h"


#endif  // __KOCKARAJZOLO_H__


