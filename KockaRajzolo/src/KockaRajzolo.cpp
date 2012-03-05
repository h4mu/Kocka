/*
============================================================================
 Name        : KockaRajzolo.cpp
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : CKockaRajzolo DLL source
============================================================================
*/

//  Include Files  

#include "KockaRajzolo.h"	// CKockaRajzolo
#include "KockaRajzolo.pan"      	// panic codes


//  Member Functions

EXPORT_C CKockaRajzolo* CKockaRajzolo::NewLC(CKockaAppView* aView)
    {
    CKockaRajzolo* self = new (ELeave) CKockaRajzolo;
    CleanupStack::PushL(self);
    self->ConstructL(aView);
    return self;
    }


EXPORT_C CKockaRajzolo* CKockaRajzolo::NewL(CKockaAppView* aView)
    {
    CKockaRajzolo* self = CKockaRajzolo::NewLC(aView);
    CleanupStack::Pop(self);
    return self;
    }


CKockaRajzolo::CKockaRajzolo()
// note, CBase initialises all member variables to zero
    {
    }


void CKockaRajzolo::ConstructL(CKockaAppView* aView)
    {
    // second phase constructor, anything that may leave must be constructed here
    iString = new (ELeave) TKockaRajzoloExampleString;
    
    iPeriodic = CPeriodic::NewL(CActive::EPriorityLow);
    iPeriodic->Start(100000, 200000, TCallBack(CKockaRajzolo::Callback, this));
    iView = aView;
    iIncX=iIncY=1;
    
    }


void CKockaRajzolo::Rajzol()
{
	if(iView->Rect()->Width() <= iView->x() + iView->Negyzet()->Width() || iView->x() < 0)
		iIncX *= -1;
	else if(iView->Rect()->Height() <= iView->y() + iView->Negyzet()->Height() || iView->y() < 0)
		iIncY *= -1;
	iView->Negyzet()->Move(iIncX, iIncY);
	iView->DrawNow();
}

TInt CKockaRajzolo::Callback(TAny * aPtr)
{
	((CKockaRajzolo*)aPtr)->Rajzol();
	return ETrue;
}

EXPORT_C CKockaRajzolo::~CKockaRajzolo()
    {
    iPeriodic->Cancel();
    delete iString;
    delete iPeriodic;
    }


EXPORT_C TVersion CKockaRajzolo::Version() const
    {
    // Version number of example API
    const TInt KMajor = 1;
    const TInt KMinor = 0;
    const TInt KBuild = 1;
    return TVersion(KMajor, KMinor, KBuild);
    }


EXPORT_C void CKockaRajzolo::ExampleFuncAddCharL(const TChar& aChar)
    {
    __ASSERT_ALWAYS(iString != NULL, Panic(EKockaRajzoloNullPointer));

    if (iString->Length() >= KKockaRajzoloBufferLength)
        {
        User::Leave(KErrTooBig);
        }

    iString->Append(aChar);
    }


EXPORT_C void CKockaRajzolo::ExampleFuncRemoveLast()
    {
    __ASSERT_ALWAYS(iString != NULL, Panic(EKockaRajzoloNullPointer));

    if (iString->Length() > 0)
        {
        iString->SetLength(iString->Length() - 1);
        }
    }


EXPORT_C const TPtrC CKockaRajzolo::ExampleFuncString() const
    {
    __ASSERT_ALWAYS(iString != NULL, Panic(EKockaRajzoloNullPointer));
    return *iString;
    }



