
#ifndef FPhiUCError_h
#define FPhiUCError_h

/**
	User control error.
 */
typedef NS_ENUM(NSUInteger, FPhiSelphIDWidgetError)
{
    /**
     Nothing.
     */
    FWMENoError = 0,
    
	/**
	 Unknown error.
	*/
    FWMEUnknown = 1,
    
	/**
	 Camera permission error.
	*/
    FWMECameraPermission = 2
};


#endif /* FPhiUCError_h */
