/*
============================================================================
 Name        : KockaApplication.h
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : Declares main application class.
============================================================================
*/

#ifndef __KOCKAAPPLICATION_H__
#define __KOCKAAPPLICATION_H__

// INCLUDES
#include <aknapp.h>

// CLASS DECLARATION

/**
* CKockaApplication application class.
* Provides factory to create concrete document object.
* An instance of CKockaApplication is the application part of the
* AVKON application framework for the Kocka example application.
*/
class CKockaApplication : public CAknApplication
    {
    public: // Functions from base classes

        /**
        * From CApaApplication, AppDllUid.
        * @return Application's UID (KUidKockaApp).
        */
        TUid AppDllUid() const;

    protected: // Functions from base classes

        /**
        * From CApaApplication, CreateDocumentL.
        * Creates CKockaDocument document object. The returned
        * pointer in not owned by the CKockaApplication object.
        * @return A pointer to the created document object.
        */
        CApaDocument* CreateDocumentL();
    };

#endif // __KOCKAAPPLICATION_H__

// End of File
