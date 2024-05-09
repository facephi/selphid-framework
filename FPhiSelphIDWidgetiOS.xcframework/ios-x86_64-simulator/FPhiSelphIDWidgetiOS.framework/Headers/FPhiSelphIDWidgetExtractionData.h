
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#include "FPhiSelphIDWidgetDocumentSide.h"

/**
 Data provided by the extraction process
 */
@interface FPhiSelphIDWidgetExtractionData : NSObject<NSCopying>

// Name of the document detected when in SMSearch mode
@property (nonatomic) NSString *documentCaptured;

// Last action before the widget closed
@property (nonatomic) NSString *lastActionBeforeClose;
@property (nonatomic) int captureProgress;
@property (nonatomic) NSString *timeoutDiagnostic;

// Data from scanned document (open)
@property (nonatomic) UIImage *frontDocument;
@property (nonatomic) UIImage *backDocument;
@property (nonatomic) UIImage *faceImage;
@property (nonatomic) UIImage *rawFrontDocument;
@property (nonatomic) UIImage *rawBackDocument;

@property (nonatomic) UIImage *signatureImage;
@property (nonatomic) UIImage *fingerprintImage;

@property (nonatomic) FPhiSelphIDWidgetDocumentSide faceImageSide;

@property (nonatomic) NSMutableDictionary<NSString *, NSString *> *ocrResults;

// Tokenized data from scanned document
@property (nonatomic) NSString *tokenOCR;
@property (nonatomic) NSString *tokenFrontDocument;
@property (nonatomic) NSString *tokenBackDocument;
@property (nonatomic) NSString *tokenFaceImage;
@property (nonatomic) NSString *tokenRawFrontDocument;
@property (nonatomic) NSString *tokenRawBackDocument;

@property (nonatomic) NSString *tokenSignatureImage;
@property (nonatomic) NSString *tokenFingerprintImage;

// Validation data
@property (nonatomic) float matchingSidesScore;

@end
