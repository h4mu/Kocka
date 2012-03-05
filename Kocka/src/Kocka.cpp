/*
============================================================================
 Name        : Kocka.cpp
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : Main application class
============================================================================
*/

// INCLUDE FILES
#include <eikstart.h>
#include "KockaApplication.h"


LOCAL_C CApaApplication* NewApplication()
	{
	return new CKockaApplication;
	}

GLDEF_C TInt E32Main()
	{
	return EikStart::RunApplication( NewApplication );
	}

