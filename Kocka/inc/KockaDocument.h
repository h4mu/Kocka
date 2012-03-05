/*
============================================================================
 Name        : KockaDocument.h
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : Declares document class for application.
============================================================================
*/

#ifndef __KOCKADOCUMENT_h__
#define __KOCKADOCUMENT_h__

// INCLUDES
#include <akndoc.h>

// FORWARD DECLARATIONS
class CKockaAppUi;
class CEikApplication;


// CLASS DECLARATION

/**
* CKockaDocument application class.
* An instance of class CKockaDocument is the Document part of the
* AVKON application framework for the Kocka example application.
*/
class CKockaDocument : public CAknDocument
    {
    public: // Constructors and destructor

        /**
        * NewL.
        * Two-phased constructor.
        * Construct a CKockaDocument for the AVKON application aApp
        * using two phase construction, and return a pointer
        * to the created object.
        * @param aApp Application creating this document.
        * @return A pointer to the created instance of CKockaDocument.
        */
        static CKockaDocument* NewL( CEikApplication& aApp );

        /**
        * NewLC.
        * Two-phased constructor.
        * Construct a CKockaDocument for the AVKON application aApp
        * using two phase construction, and return a pointer
        * to the created object.
        * @param aApp Application creating this document.
        * @return A pointer to the created instance of CKockaDocument.
        */
        static CKockaDocument* NewLC( CEikApplication& aApp );

        /**
        * ~CKockaDocument
        * Virtual Destructor.
        */
        virtual ~CKockaDocument();

    public: // Functions from base classes

        /**
        * CreateAppUiL
        * From CEikDocument, CreateAppUiL.
        * Create a CKockaAppUi object and return a pointer to it.
        * The object returned is owned by the Uikon framework.
        * @return Pointer to created instance of AppUi.
        */
        CEikAppUi* CreateAppUiL();

    private: // Constructors

        /**
        * ConstructL
        * 2nd phase constructor.
        */
        void ConstructL();

        /**
        * CKockaDocument.
        * C++ default constructor.
        * @param aApp Application creating this document.
        */
        CKockaDocument( CEikApplication& aApp );

    };

#endif // __KOCKADOCUMENT_h__

// End of File
