#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreVideo/CoreVideo.h>
#import <CoreMedia/CoreMedia.h>
#import <CoreText/CoreText.h>

#import "FPhiSelphIDWidgetExtractionData.h"
#import "FPhiSelphIDGraphProtocol.h"
#import "FPhiSelphIDWidgetDocumentSide.h"
#import "FPhiSelphIDWidgetDocumentType.h"

#import "IFPhiDocumentExtractor.h"


typedef NS_ENUM(NSUInteger, FPhiSelphIDWidgetScanMode) {
    SMGeneric,
    SMSpecific,
    SMSearch,
};


typedef NS_ENUM(NSUInteger, FPhiSelphIDWidgetTimeout) {
    TShort,
    TMedium,
    TLong,
    TVeryLong,
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

// Front documentExtractor
@property (nonatomic) IFPhiDocumentExtractor *documentExtractor;

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

@property (nonatomic) NSString *translationsContent;
@property (nonatomic) NSString *viewsContent;

/**
 Filename of the video from the capture process
 */
@property (nonatomic) NSString *videoFilename;

/**
 Whether we generate the uncropped inage of the document
 */
@property (nonatomic) BOOL generateRawImages;

/**
 Generates an encrypted token with the string parameter
 */
- (NSString *)tokenize:(NSString *)data;

/**
 Initialize a new user control object.
 param backCameraIfAvailable: By default rear camera used. If device's back camera is available and backCameraIfAvailable is true, back camera is used, and include credentials for initialize firebase.
 */
- (id)initWithBackCameraIfAvailable:(bool)backCameraIfAvailable resources:(NSString *)resourcesPath delegate:(id)delegate license:(NSString *)license error:(NSError **)error credentials:(NSDictionary *)firCredentials;

/**
 Initialize a new user control object.
 param backCameraIfAvailable: By default rear camera used. If device's back camera is available and backCameraIfAvailable is true, back camera is used.
 */
- (id)initWithBackCameraIfAvailable:(bool)backCameraIfAvailable resources:(NSString *)resourcesPath delegate:(id)delegate license:(NSString *)license error:(NSError **)error;

/**
 Start a full extraction process. When process was finished ExtractionFinished method from protocol FPhiUCProtocol is executed.
 */
- (void)StartExtraction;

/**
 Stops a extraction process.
 */
- (void)StopExtraction;


/**
 Sets a generic parameter to the widget
 */
- (void)setParam:(NSString *)key withValue:(NSString *)value;

/**
 Return byte buffer representation of img in PNG Format
 */
+(NSData *)PNGRepresentationFromImage :(UIImage *)img;

/**
 Return byte byffer representation of img in JPEG Format.
 Parameter compressionQuality: Range [0..1]
 */
+(NSData *)JPGRepresentationFromImage :(UIImage *)img :(CGFloat)compressionQuality;

/**
 It retrieves the widget's version
*/
+(NSString *)widgetVersion;


@end
