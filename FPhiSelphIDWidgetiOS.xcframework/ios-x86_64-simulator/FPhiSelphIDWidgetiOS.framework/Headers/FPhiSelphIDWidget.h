#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreVideo/CoreVideo.h>
#import <CoreMedia/CoreMedia.h>
#import <CoreText/CoreText.h>
#import "FPhiSelphIDWidgetExtractionData.h"

#import "FPhiGraph.h"

typedef NS_ENUM(NSUInteger, FPhiSelphIDWidgetDocumentType) {
    
    DTIDCard,

    DTPassport,
    
    DTDriversLicense,

    DTForeignCard,
    
    DTCreditCard,

    DTCustom,
};

typedef NS_ENUM(NSUInteger, FPhiSelphIDWidgetDocumentSide) {
    
    DSFront,

    DSBack,
};


typedef NS_ENUM(NSUInteger, FPhiSelphIDWidgetScanMode) {
    
    SMGeneric,
    
    SMSpecific,

    SMSearch,
};


typedef NS_ENUM(NSUInteger, FPhiSelphIDWidgetTimeout) {
    
    TShort,
    
    TMedium,

    TLong,
};


/**
 User control object. Manages ipad and iphone cameras and delivery results from a extraction process.
*/
@interface FPhiSelphIDWidget : UIViewController <AVCaptureVideoDataOutputSampleBufferDelegate,AVCaptureMetadataOutputObjectsDelegate, FPhiSelphIDGraphProtocol, NSXMLParserDelegate>

// Widget Modes
@property (nonatomic) FPhiSelphIDWidgetDocumentType scanType;
@property (nonatomic) FPhiSelphIDWidgetDocumentSide scanSide;
@property (nonatomic) FPhiSelphIDWidgetScanMode scanMode;
@property (nonatomic) NSString* specificData;

// Widget flags
@property (nonatomic) bool wizardMode;
@property (nonatomic) bool showAfterCapture;
@property (nonatomic) bool showTutorial;
@property (nonatomic) bool showTutorialOnly;

/**
 Debug mode property. This property is only for debugging purposes. False by default.
 */
@property (nonatomic) bool debugMode;


// Widget configurations
@property (nonatomic) NSString *tokenPreviousCaptureData;

@property (nonatomic) FPBSelphIDDocumentRawData *tokenizer;

@property (nonatomic) NSString* license;

@property (nonatomic) float tokenImageQuality;


/**
 Capture timeout property. This property sets the timeout for capturing the document.
*/
@property (nonatomic) FPhiSelphIDWidgetTimeout timeout;

/**
 Image to test
 */
@property (nonatomic) UIImage *testImage;

/**
 Results of a extraction process.
 */
@property (nonatomic) FPhiSelphIDWidgetExtractionData *results;

/**
 optional locale used to programatically force widget locale.
 */
@property (nonatomic) NSString *locale;


/**
 Sets the definition of the document models that the widget will be able to scan.
 This property overrides the definition inside resourcesBundle zip
 */
@property (nonatomic) NSString *documentModels;


/**
 Filename of the video from the capture process
 */
@property (nonatomic) NSString *videoFilename;


/**
 Initialize a new user control object.
 param frontCameraIfAvailable: By default rear camera used. If device's front camera is available and frontCameraIfAvailable is true, front camera is used, and include credentials for initialize firebase.
 */
- (id)initWithFrontCameraIfAvailable:(bool)frontCameraIfAvailable resources:(NSString *)resourcesPath delegate:(id)delegate license:(NSString *)license error:(NSError **)error credentials:(NSDictionary *)firCredentials;

/**
 Initialize a new user control object.
 param frontCameraIfAvailable: By default rear camera used. If device's front camera is available and frontCameraIfAvailable is true, front camera is used.
 */
- (id)initWithFrontCameraIfAvailable:(bool)frontCameraIfAvailable resources:(NSString *)resourcesPath delegate:(id)delegate license:(NSString *)license error:(NSError **)error;

/**
 Start a full extraction process. When process was finished ExtractionFinished method from protocol FPhiUCProtocol is executed.
 */
- (void)StartExtraction;

/**
 Stops a extraction process.
 */
- (void)StopExtraction;

/**
 Transform rectangle from camera image space to display space.
 Extractor returns face and eyes information in image space. Use this method to calculate in display space in order to paint in the correct place.
 */
//-(CGRect)TransformToDisplaySpace:(CGRect)imageSpaceRectangle;

/**
 Return byte buffer representation of img in PNG Format
 */
+(NSData *)PNGRepresentationFromImage :(UIImage *)img;

/**
 Return byte byffer representation of img in JPEG Format.
 Parameter compressionQuality: Range [0..1]
 */
+(NSData *)JPGRepresentationFromImage :(UIImage *)img :(CGFloat)compressionQuality;

@end
