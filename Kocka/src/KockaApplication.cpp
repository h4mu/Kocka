/*
============================================================================
 Name        : KockaApplication.cpp
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : Main application class
============================================================================
*/

// INCLUDE FILES
#include "Kocka.hrh"
#include "KockaDocument.h"
#include "KockaApplication.h"

// ============================ MEMBER FUNCTIONS ===============================

// UID for the application;
// this should correspond to the uid defined in the mmp file
const TUid KUidKockaApp = { _UID3 };

// -----------------------------------------------------------------------------
// CKockaApplication::CreateDocumentL()
// Creates CApaDocument object
// -----------------------------------------------------------------------------
//
CApaDocument* CKockaApplication::CreateDocumentL()
    {
    // Create an Kocka document, and return a pointer to it
    return (static_cast<CApaDocument*>
                    ( CKockaDocument::NewL( *this ) ) );
    }

// -----------------------------------------------------------------------------
// CKockaApplication::AppDllUid()
// Returns application UID
// -----------------------------------------------------------------------------
//
TUid CKockaApplication::AppDllUid() const
    {
    // Return the UID for the Kocka application
    return KUidKockaApp;
    }

// End of File
