/*
============================================================================
 Name        : KockaAppUi.h
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : Declares UI class for application.
============================================================================
*/

#ifndef __KOCKAAPPUI_h__
#define __KOCKAAPPUI_h__

// INCLUDES
#include <aknappui.h>


// FORWARD DECLARATIONS
class CKockaAppView;


// CLASS DECLARATION
/**
* CKockaAppUi application UI class.
* Interacts with the user through the UI and request message processing
* from the handler class
*/
class CKockaAppUi : public CAknAppUi
    {
    public: // Constructors and destructor

        /**
        * ConstructL.
        * 2nd phase constructor.
        */
        void ConstructL();

        /**
        * CKockaAppUi.
        * C++ default constructor. This needs to be public due to
        * the way the framework constructs the AppUi
        */
        CKockaAppUi();

        /**
        * ~CKockaAppUi.
        * Virtual Destructor.
        */
        virtual ~CKockaAppUi();

    private:  // Functions from base classes

        /**
        * From CEikAppUi, HandleCommandL.
        * Takes care of command handling.
        * @param aCommand Command to be handled.
        */
        void HandleCommandL( TInt aCommand );

        /**
        *  HandleStatusPaneSizeChange.
        *  Called by the framework when the application status pane
 		*  size is changed.
        */

		void HandleStatusPaneSizeChange();
        
    private: // Data

        /**
        * The application view
        * Owned by CKockaAppUi
        */
        CKockaAppView* iAppView;
        
        
    };

#endif // __KOCKAAPPUI_h__

// End of File
