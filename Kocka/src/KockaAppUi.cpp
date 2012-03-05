/*
============================================================================
 Name        : KockaAppUi.cpp
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : CKockaAppUi implementation
============================================================================
*/

// INCLUDE FILES
#include <avkon.hrh>
#include <aknnotewrappers.h>
#include <stringloader.h>
#include <Kocka.rsg>
#include <f32file.h>
#include <s32file.h>

#include "Kocka.pan"
#include "KockaAppUi.h"
#include "KockaAppView.h"
#include "Kocka.hrh"

_LIT( KFileName, "C:\\private\\E66CF47D\\Kocka.txt" );
_LIT( KText, "H4MU rox!");

// ============================ MEMBER FUNCTIONS ===============================


// -----------------------------------------------------------------------------
// CKockaAppUi::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CKockaAppUi::ConstructL()
    {
    // Initialise app UI with standard value.
    BaseConstructL();

	// Create view object
	iAppView = CKockaAppView::NewL( ClientRect() );

	// Create a file to write the text to
	RFs fsSession;
	User::LeaveIfError(fsSession.Connect());
	CleanupClosePushL( fsSession );

	TInt err = fsSession.MkDirAll(KFileName);
	if ( (KErrNone != err) && (KErrAlreadyExists != err) )
		{
		CleanupStack::PopAndDestroy(1); //  fsSession
		return;
		}
	
	RFile file;
	err = file.Replace(fsSession, KFileName, EFileWrite );
	CleanupClosePushL( file );
	if ( KErrNone != err )
		{
		CleanupStack::PopAndDestroy(2); // file, fsSession
		return;
		}
	
	RFileWriteStream outputFileStream( file );
	CleanupClosePushL( outputFileStream );
	outputFileStream << KText;

	CleanupStack::PopAndDestroy(3); // outputFileStream, file, fsSession

	}
// -----------------------------------------------------------------------------
// CKockaAppUi::CKockaAppUi()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CKockaAppUi::CKockaAppUi()
    {
    // No implementation required
    }

// -----------------------------------------------------------------------------
// CKockaAppUi::~CKockaAppUi()
// Destructor.
// -----------------------------------------------------------------------------
//
CKockaAppUi::~CKockaAppUi()
    {
    if ( iAppView )
        {
        delete iAppView;
        iAppView = NULL;
        }

    }

// -----------------------------------------------------------------------------
// CKockaAppUi::HandleCommandL()
// Takes care of command handling.
// -----------------------------------------------------------------------------
//
void CKockaAppUi::HandleCommandL( TInt aCommand )
    {
    switch( aCommand )
        {
        case EEikCmdExit:
        case EAknSoftkeyExit:
            Exit();
            break;

        case ECommand1:
            {
            
            // Load a string from the resource file and display it
            HBufC* textResource = StringLoader::LoadLC( R_COMMAND1_TEXT );
            CAknInformationNote* informationNote;

            informationNote = new ( ELeave ) CAknInformationNote;

            // Show the information Note with
            // textResource loaded with StringLoader.
            informationNote->ExecuteLD( *textResource);

            // Pop HBuf from CleanUpStack and Destroy it.
            CleanupStack::PopAndDestroy( textResource );
            }
            break;
		case ECommand2:
			{
			
			RFs fsSession;
			RFile rFile;
			
			// Connects a client process to the fileserver
			User::LeaveIfError(fsSession.Connect());
			CleanupClosePushL(fsSession);
			
			//Open file where the stream text is
			User::LeaveIfError(rFile.Open(fsSession,KFileName, EFileStreamText));//EFileShareReadersOnly));// EFileStreamText));
			CleanupClosePushL(rFile);
			
			// copy stream from file to RFileStream object
			RFileReadStream inputFileStream(rFile);
    		CleanupClosePushL(inputFileStream);
    		
    		// HBufC descriptor is created from the RFileStream object.
    		HBufC* fileData = HBufC::NewLC(inputFileStream, 32);

            CAknInformationNote* informationNote;

            informationNote = new ( ELeave ) CAknInformationNote;
            // Show the information Note
            informationNote->ExecuteLD( *fileData);			
			
			// Pop loaded resources from the cleanup stack
			CleanupStack::PopAndDestroy(4); // filedata, inputFileStream, rFile, fsSession
			fsSession.Close();
			}
			break;
        default:
            Panic( EKockaUi );
            break;
        }
    }
// -----------------------------------------------------------------------------
//  Called by the framework when the application status pane
//  size is changed.  Passes the new client rectangle to the
//  AppView
// -----------------------------------------------------------------------------
//
void CKockaAppUi::HandleStatusPaneSizeChange()
{
	iAppView->SetRect( ClientRect() );
	
} 

// End of File
