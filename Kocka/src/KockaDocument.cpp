/*
============================================================================
 Name        : KockaDocument.cpp
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : CKockaDocument implementation
============================================================================
*/


// INCLUDE FILES
#include "KockaAppUi.h"
#include "KockaDocument.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CKockaDocument::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CKockaDocument* CKockaDocument::NewL( CEikApplication&
                                                          aApp )
    {
    CKockaDocument* self = NewLC( aApp );
    CleanupStack::Pop( self );
    return self;
    }

// -----------------------------------------------------------------------------
// CKockaDocument::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CKockaDocument* CKockaDocument::NewLC( CEikApplication&
                                                           aApp )
    {
    CKockaDocument* self =
        new ( ELeave ) CKockaDocument( aApp );

    CleanupStack::PushL( self );
    self->ConstructL();
    return self;
    }

// -----------------------------------------------------------------------------
// CKockaDocument::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CKockaDocument::ConstructL()
    {
    // No implementation required
    }

// -----------------------------------------------------------------------------
// CKockaDocument::CKockaDocument()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CKockaDocument::CKockaDocument( CEikApplication& aApp )
    : CAknDocument( aApp )
    {
    // No implementation required
    }

// ---------------------------------------------------------------------------
// CKockaDocument::~CKockaDocument()
// Destructor.
// ---------------------------------------------------------------------------
//
CKockaDocument::~CKockaDocument()
    {
    // No implementation required
    }

// ---------------------------------------------------------------------------
// CKockaDocument::CreateAppUiL()
// Constructs CreateAppUi.
// ---------------------------------------------------------------------------
//
CEikAppUi* CKockaDocument::CreateAppUiL()
    {
    // Create the application user interface, and return a pointer to it;
    // the framework takes ownership of this object
    return ( static_cast <CEikAppUi*> ( new ( ELeave )
                                        CKockaAppUi ) );
    }

// End of File
