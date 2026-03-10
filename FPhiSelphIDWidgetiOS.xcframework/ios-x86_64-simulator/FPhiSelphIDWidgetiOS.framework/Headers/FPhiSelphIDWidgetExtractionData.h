
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#include "FPhiSelphIDWidgetDocumentSide.h"
#include "FPhiSelphIDWidgetDocumentType.h"

/**
 Data provided by the extraction process
 */
@interface FPhiSelphIDWidgetExtractionData : NSObject

@property (nonatomic) BOOL finished;
@property (nonatomic) BOOL applyRemapping;

// Name of the document detected when in SMSearch mode
@property (nonatomic) NSString * _Nullable documentCaptured;
@property (nonatomic) NSString * _Nullable countryCaptured;
@property (nonatomic) FPhiSelphIDWidgetDocumentType documentTypeCaptured;

// Last action before the widget closed
@property (nonatomic) NSString * _Nullable lastActionBeforeClose;
@property (nonatomic) int captureProgress;
@property (nonatomic) NSString * _Nullable timeoutDiagnostic;

// Statistics
@property (nonatomic) NSString * _Nullable statistics;

// Data from scanned document (open)
@property (nonatomic) UIImage * _Nullable frontDocument;
@property (nonatomic) UIImage * _Nullable backDocument;
@property (nonatomic) UIImage * _Nullable faceImage;
@property (nonatomic) UIImage * _Nullable rawFrontDocument;
@property (nonatomic) UIImage * _Nullable rawBackDocument;

@property (nonatomic) UIImage * _Nullable signatureImage;
@property (nonatomic) UIImage * _Nullable fingerprintImage;

@property (nonatomic) FPhiSelphIDWidgetDocumentSide faceImageSide;

@property (nonatomic) NSMutableDictionary<NSString *, NSString *> * _Nullable ocrResults;

// Tokenized data from scanned document
@property (nonatomic) NSString * _Nullable tokenOCR;
@property (nonatomic) NSString * _Nullable tokenFrontDocument;
@property (nonatomic) NSString * _Nullable tokenBackDocument;
@property (nonatomic) NSString * _Nullable tokenFaceImage;
@property (nonatomic) NSString * _Nullable tokenRawFrontDocument;
@property (nonatomic) NSString * _Nullable tokenRawBackDocument;

@property (nonatomic) NSString * _Nullable tokenSignatureImage;
@property (nonatomic) NSString * _Nullable tokenFingerprintImage;

// Validation data
@property (nonatomic) float matchingSidesScore;
@property (nonatomic) float matchingFrontScore;
@property (nonatomic) float matchingBackScore;

@end
