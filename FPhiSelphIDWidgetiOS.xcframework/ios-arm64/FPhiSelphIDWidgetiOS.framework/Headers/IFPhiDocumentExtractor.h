#ifndef IFPhiDocumentExtractor_h
#define IFPhiDocumentExtractor_h

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, IFPhiDocumentExtractorDiagnostic) {
    DIAGNOSTIC_NONE,
    DIAGNOSTIC_OK,
    DIAGNOSTIC_NOT_RATED,
    DIAGNOSTIC_UNCERTAIN,
    DIAGNOSTIC_UNABLE_TO_CAPTURE,
    DIAGNOSTIC_DOCUMENT_NOT_DETECTED,
    DIAGNOSTIC_DOCUMENT_NOT_CLASSIFIED,
    DIAGNOSTIC_DOCUMENT_BLURRED,
    DIAGNOSTIC_DOCUMENT_NOT_EXPECTED,
    DIAGNOSTIC_MANDATORY_RESULT_MISSING,
    DIAGNOSTIC_OPTIONAL_RESULT_MISSING,
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
    STATUSRESULT_UNEXPECTED_ERROR,
};

@interface IFPhiDocumentExtractorStatus : NSObject
@property (nonatomic) IFPhiDocumentExtractorStatusResult s;
@property (nonatomic) NSString *message;
-(id)initWithStatus:(IFPhiDocumentExtractorStatusResult)s andMessage:(NSString *)m;
@end

@interface IFPhiDocumentExtractorResult : NSObject
@property (nonatomic) IFPhiDocumentExtractorDiagnostic diagnostic;
@property (nonatomic) NSMutableDictionary<NSString *, NSString *> *ocrData;
@property (nonatomic) NSMutableDictionary<NSString *, UIImage *> *imgData;
@property (nonatomic) NSString *country;
@property (nonatomic) NSString *version;
@property (nonatomic) NSString *documentCaptured;
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

-(void)setupInput:(int)width :(int)height :(IFPhiDocumentExtractorImageRotation)rotation :(IFPhiDocumentExtractorImageFormat)imageFormat :(CGRect)ROI isStream:(bool)isStream;
-(IFPhiDocumentExtractorStatus *)setupExtraction:(NSMutableDictionary<NSString *, NSObject *> *)params;

-(void)startExtraction;
-(void)resetExtraction;

-(void)extract:(UIImage *)image :(double)timeStamp onResult:(onResultBlock)onResult onException:(onExceptionBlock)onException;

@end

#endif /* IFPhiDocumentExtractor_h */
