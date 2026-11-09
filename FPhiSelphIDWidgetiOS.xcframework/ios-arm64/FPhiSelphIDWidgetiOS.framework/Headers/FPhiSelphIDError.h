
#ifndef FPhiUCError_h
#define FPhiUCError_h

/**
	User control error.
 */
typedef NS_ENUM(NSUInteger, FPhiSelphIDWidgetError)
{
    /**
     * No error.
     */
    FWMENone = 0,
    
    /**
     * Unexpected error.
     */
    FWMEUnknown,

    /**
     * License error.
     */
    FWMEExtractionLicenseError, // -1

    /**
     * Unexpected capture error.
     */
    FWMEUnexpectedCaptureError, // -2

    /**
     * Control not initialized correctly.
     */
    FWMEControlNotInitializedError, //-3

    /**
        * Unexpected error related to the hardware.
        */
    FWMEHardwareError,  // -4

    /**
        * The configuration of the extractor is not valid.
        */
    FWMEBadExtractorConfiguration,
    
    /**
     * The user stopped the process manually.
     */
    FWMEStoppedManually,
    
    /**
     * Time out.
     */
    FWMETimeout,
    
    /**
     * Camera Permission denied.
     */
    FWMECameraPermission,
    
    /**
     * Write Settings Permission denied.
     */
    FWMESettingsPermissionDenied,

    /**
     * Bad parameter supplied to the widget.
     */
    FWMEBadConfiguration
};


#endif /* FPhiUCError_h */
