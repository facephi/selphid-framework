#ifndef IFPhiDocumentExtractor_h
#define IFPhiDocumentExtractor_h

#import <UIKit/UIKit.h>
#import "FPhiSelphIDWidgetDocumentType.h"

typedef NS_ENUM(NSInteger, IFPhiDocumentExtractorDiagnostic) {
    DIAGNOSTIC_NONE,
    DIAGNOSTIC_OK,
    DIAGNOSTIC_NOT_RATED,
    DIAGNOSTIC_UNCERTAIN,
    DIAGNOSTIC_UNABLE_TO_CAPTURE,
    DIAGNOSTIC_DOCUMENT_NOT_DETECTED,
    DIAGNOSTIC_DOCUMENT_NOT_CLASSIFIED,
    DIAGNOSTIC_DOCUMENT_NOT_AVAILABLE,
    DIAGNOSTIC_DOCUMENT_BLURRED,
    DIAGNOSTIC_DOCUMENT_NOT_EXPECTED,
    DIAGNOSTIC_MANDATORY_RESULT_MISSING,
    DIAGNOSTIC_MANDATORY_DOCUMENT_MISSING,
    DIAGNOSTIC_MANDATORY_FACE_MISSING,
    DIAGNOSTIC_MANDATORY_MRZ_MISSING,
    DIAGNOSTIC_MANDATORY_PDF417_MISSING,
    DIAGNOSTIC_MANDATORY_BARCODE_MISSING,
    DIAGNOSTIC_OPTIONAL_RESULT_MISSING,
    DIAGNOSTIC_VERIFICATION_FAILED,
};

typedef NS_ENUM(NSInteger, IFPhiDocumentExtractorImageFormat) {
    IMAGEFORMAT_YUV21,
    IMAGEFORMAT_YUV12,
    IMAGEFORMAT_RGB,
    IMAGEFORMAT_BGR,
    IMAGEFORMAT_RGBA,
    IMAGEFORMAT_ABGR,
    IMAGEFORMAT_ARGB,
};

typedef NS_ENUM(NSInteger, IFPhiDocumentExtractorImageRotation) {
    IMAGEROTATION_UP,
    IMAGEROTATION_LEFT,
    IMAGEROTATION_DOWN,
    IMAGEROTATION_RIGHT,
};

typedef NS_ENUM(NSInteger, IFPhiDocumentExtractorStatusResult) {
    STATUSRESULT_OK,
    STATUSRESULT_LICENSE_ERROR,
    STATUSRESULT_BAD_CONFIGURATION,
    STATUSRESULT_UNSUPPORTED_CONFIGURATION,
    STATUSRESULT_UNEXPECTED_ERROR,
};

@interface IFPhiDocumentExtractorStatus : NSObject
@property (nonatomic) IFPhiDocumentExtractorStatusResult s;
@property (nonatomic) NSString *message;
-(id)initWithStatus:(IFPhiDocumentExtractorStatusResult)s andMessage:(NSString *)m;
@end

@interface IFPhiDocumentExtractorIqa : NSObject
@property (nonatomic) float overExposure;
@property (nonatomic) float underExposure;
@property (nonatomic) float sharpness;
@property (nonatomic) float readability;
-(id)init;
@end

@interface IFPhiDocumentExtractorResult : NSObject
@property (nonatomic) IFPhiDocumentExtractorDiagnostic diagnostic;
@property (nonatomic) NSString *message;
@property (nonatomic) IFPhiDocumentExtractorIqa *iqa;
@property (nonatomic) NSMutableDictionary<NSString *, NSString *> *ocrData;
@property (nonatomic) NSMutableDictionary<NSString *, UIImage *> *imgData;
@property (nonatomic) NSString *documentCountry;
@property (nonatomic) FPhiSelphIDWidgetDocumentType documentType;
@property (nonatomic) NSString *documentVersion;
@property (nonatomic) NSString *documentCaptured;
@property (nonatomic) NSString *documentClass;
@property (nonatomic) bool morePagesAvailable;
@property (nonatomic) bool finished;
@property (nonatomic) bool applyRemapping;
-(id)init;
@end

#define DOCUMENTEXTRACTOR_SOURCE_MRZ @"MRZ"
#define DOCUMENTEXTRACTOR_SOURCE_PDF417 @"PDF417"
#define DOCUMENTEXTRACTOR_SOURCE_BARCODE @"BARCODE"
#define DOCUMENTEXTRACTOR_SOURCE_VIZ @"ML"

// Definitions for Blocks (Lambda/Closure types for Obj-C)
typedef void(^onStatusBlock)(IFPhiDocumentExtractorStatus *status);
typedef void(^onResultBlock)(NSString *documentKey, IFPhiDocumentExtractorResult *result);
typedef void(^onExceptionBlock)(NSString *documentKey, NSString *message);

@interface IFPhiDocumentExtractor : NSObject

-(void)create:(NSMutableDictionary<NSString *, NSObject *> *)params onStatus:(onStatusBlock)onStatus;
-(void)destroy;

-(bool)isReady;
-(int)creationProgress;

-(void)setupInput:(int)width :(int)height :(IFPhiDocumentExtractorImageRotation)rotation :(IFPhiDocumentExtractorImageFormat)imageFormat :(CGRect)ROI isStream:(bool)isStream;
-(IFPhiDocumentExtractorStatus *)setupExtraction:(NSMutableDictionary<NSString *, NSObject *> *)params;

-(void)startExtraction;
-(void)resetExtraction;
-(bool)hasFullResetOnly;

-(bool)isAbleToScanSidesIndependently;

-(void)extract:(UIImage *)image :(double)timeStamp onResult:(onResultBlock)onResult onException:(onExceptionBlock)onException;

@end

#endif /* IFPhiDocumentExtractor_h */
