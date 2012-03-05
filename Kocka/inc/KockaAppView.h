/*
============================================================================
 Name        : KockaAppView.h
 Author      : Hamor Tamas
 Copyright   : Your copyright notice
 Description : Declares view class for application.
============================================================================
*/

#ifndef __KOCKAAPPVIEW_h__
#define __KOCKAAPPVIEW_h__

// INCLUDES
#include <coecntrl.h>
#include "KockaRajzolo.h"

#define WIDTH 10
#define HEIGHT 10

//class CKockaRajzolo;

// CLASS DECLARATION
class CKockaAppView : public CCoeControl
    {
    public: // New methods
    	virtual TRect * Negyzet();
    	virtual void SetNegyzet(TRect * aNegyzet);
    	virtual TInt x();
    	virtual TInt y();
    	void SetX(TInt aX);
    	void SetY(TInt aY);
		virtual const TRect * Rect();
	private:
		const TRect * iLastRect;
		TRect* iNegyzet;
		TInt iX, iY;
	    CKockaRajzolo * iKockaRajzolo;
		

	public:
        /**
        * NewL.
        * Two-phased constructor.
        * Create a CKockaAppView object, which will draw itself to aRect.
        * @param aRect The rectangle this view will be drawn to.
        * @return a pointer to the created instance of CKockaAppView.
        */
        static CKockaAppView* NewL( const TRect& aRect );

        /**
        * NewLC.
        * Two-phased constructor.
        * Create a CKockaAppView object, which will draw itself
        * to aRect.
        * @param aRect Rectangle this view will be drawn to.
        * @return A pointer to the created instance of CKockaAppView.
        */
        static CKockaAppView* NewLC( const TRect& aRect );

        /**
        * ~CKockaAppView
        * Virtual Destructor.
        */
        virtual ~CKockaAppView();

    public:  // Functions from base classes

        /**
        * From CCoeControl, Draw
        * Draw this CKockaAppView to the screen.
        * @param aRect the rectangle of this view that needs updating
        */
        void Draw( const TRect& aRect ) const;

        /**
        * From CoeControl, SizeChanged.
        * Called by framework when the view size is changed.
        */
        virtual void SizeChanged();

    private: // Constructors

        /**
        * ConstructL
        * 2nd phase constructor.
        * Perform the second phase construction of a
        * CKockaAppView object.
        * @param aRect The rectangle this view will be drawn to.
        */
        void ConstructL(const TRect& aRect);

        /**
        * CKockaAppView.
        * C++ default constructor.
        */
        CKockaAppView();

    };

#endif // __KOCKAAPPVIEW_h__

// End of File
