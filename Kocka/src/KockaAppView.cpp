/*
============================================================================
 Name        : KockaAppView.cpp
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : Application view implementation
============================================================================
*/

// INCLUDE FILES
#include <coemain.h>
#include "KockaAppView.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CKockaAppView::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CKockaAppView* CKockaAppView::NewL( const TRect& aRect )
    {
    CKockaAppView* self = CKockaAppView::NewLC( aRect );
    CleanupStack::Pop( self );
    return self;
    }

// -----------------------------------------------------------------------------
// CKockaAppView::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CKockaAppView* CKockaAppView::NewLC( const TRect& aRect )
    {
    CKockaAppView* self = new ( ELeave ) CKockaAppView;
    CleanupStack::PushL( self );
    self->ConstructL( aRect );
    return self;
    }

// -----------------------------------------------------------------------------
// CKockaAppView::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CKockaAppView::ConstructL( const TRect& aRect )
    {
    // Create a window for this application view
    CreateWindowL();

    // Set the windows size
    SetRect( aRect );

    iLastRect = &aRect;
    iNegyzet = new TRect;
    iNegyzet->SetRect(iX,iY,WIDTH,HEIGHT);
    iKockaRajzolo = CKockaRajzolo::NewL(this);

    // Activate the window, which makes it ready to be drawn
    ActivateL();
    }

// -----------------------------------------------------------------------------
// CKockaAppView::CKockaAppView()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CKockaAppView::CKockaAppView()
    {
    // No implementation required
    }


// -----------------------------------------------------------------------------
// CKockaAppView::~CKockaAppView()
// Destructor.
// -----------------------------------------------------------------------------
//
CKockaAppView::~CKockaAppView()
    {
    // No implementation required
    }


// -----------------------------------------------------------------------------
// CKockaAppView::Draw()
// Draws the display.
// -----------------------------------------------------------------------------
//
void CKockaAppView::Draw( const TRect& /*aRect*/ ) const
    {
    // Get the standard graphics context
    CWindowGc& gc = SystemGc();

    // Gets the control's extent
//    TRect drawRect( Rect());

    // Clears the screen
//    gc.Clear( drawRect );

    gc.Clear();
    gc.DrawRect(*iNegyzet);   
  	}

// -----------------------------------------------------------------------------
// CKockaAppView::SizeChanged()
// Called by framework when the view size is changed.
// -----------------------------------------------------------------------------
//
void CKockaAppView::SizeChanged()
    {  
    DrawNow();
    }
    
const TRect * CKockaAppView::Rect(){return iLastRect;}

void CKockaAppView::SetNegyzet(TRect * aNegyzet){iNegyzet = aNegyzet;}

TRect * CKockaAppView::Negyzet(){return iNegyzet;}

TInt CKockaAppView::x(){return iX;}
TInt CKockaAppView::y(){return iY;}
void CKockaAppView::SetX(TInt aX){iX = aX;}
void CKockaAppView::SetY(TInt aY){iY = aY;}

// End of File
