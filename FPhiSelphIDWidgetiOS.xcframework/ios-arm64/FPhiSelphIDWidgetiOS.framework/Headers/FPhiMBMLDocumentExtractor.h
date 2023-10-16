#ifndef FPhiMBMLDocumentExtractor_h
#define FPhiMBMLDocumentExtractor_h

#import "IFPhiDocumentExtractor.h"
#import "FPhiSelphIDWidgetDocumentType.h"
#import "FPhiSelphIDWidgetDocumentSide.h"

// 3rd party library
#import <Microblink/Microblink.h>


@interface RecognizerExtractionData : NSObject
@property (nonatomic) MBRecognizerRunner *recognizerRunner;
@property (nonatomic) MBRecognizerCollection *recognizerBundle;
@property (nonatomic) MBImageReturnProcessor *irpFullDocument;

@property (nonatomic) bool faceRecognizerMandatory;
@property (nonatomic) bool mrtdRecognizerMandatory;
@property (nonatomic) bool pdf417RecognizerMandatory;
@property (nonatomic) bool barcodeRecognizerMandatory;
@property (nonatomic) bool documentRecognizerMandatory;

@property (nonatomic) bool faceRecognizerPresent;
@property (nonatomic) bool mrtdRecognizerPresent;
@property (nonatomic) bool pdf417RecognizerPresent;
@property (nonatomic) bool barcodeRecognizerPresent;
@property (nonatomic) bool documentRecognizerPresent;

@property (nonatomic) float timeoutOptionalData;

-(id)init;
@end

@interface FPhiMBMLDocumentExtractor : IFPhiDocumentExtractor <
    MBBlinkIdCombinedRecognizerDelegate,
    MBDetectionRecognizerRunnerDelegate,
    MBScanningRecognizerRunnerDelegate
>
// Input
@property (nonatomic) int width;
@property (nonatomic) int height;
@property (nonatomic) IFPhiDocumentExtractorImageRotation rotation;
@property (nonatomic) IFPhiDocumentExtractorImageFormat format;
@property (nonatomic) CGRect ROI;
@property (nonatomic) bool isStream;

// Results for every bundle
@property (nonatomic) NSMutableDictionary<NSString *, IFPhiDocumentExtractorResult *> *results;
@property (nonatomic) NSMutableDictionary<NSString *, RecognizerExtractionData *> *recognizerExtractionData;
@property (nonatomic) NSMutableArray<NSString *> *documentKeysToExtract;
@property (nonatomic) int nextDocumentKey;

// Microblink Objects
@property (nonatomic) MBBlinkIdCombinedRecognizer *blinkIdFrontRecognizer;
@property (nonatomic) MBBlinkCardRecognizer *blinkCardFrontRecognizer;
@property (nonatomic) bool blinkIdRecognizerMandatory;
@property (nonatomic) bool blinkCardRecognizerMandatory;

// Microblink results
@property (nonatomic) MBMrtdRecognizerResult *mrtdResult;
@property (nonatomic) MBPdf417RecognizerResult *pdfResult;
@property (nonatomic) MBBarcodeRecognizerResult *barcodeResult;
@property (nonatomic) MBBlinkIdCombinedRecognizerResult *blinkIdResult;
@property (nonatomic) MBBlinkCardRecognizerResult *blinkCardResult;

// Extraction data
@property (nonatomic) NSString *documentKey;
@property (nonatomic) NSString *documentVersionKey;
@property (nonatomic) NSString *documentCountry;
@property (nonatomic) NSString *documentVersion;
@property (nonatomic) FPhiSelphIDWidgetDocumentType docType;
@property (nonatomic) FPhiSelphIDWidgetDocumentSide docSide;

@property (nonatomic) bool matchesCountry;
@property (nonatomic) bool matchesDocumentType;
@property (nonatomic) NSString *mbCountry;
@property (nonatomic) FPhiSelphIDWidgetDocumentType mbDocType;
@property (nonatomic) NSString *mbDocModel;
@property (nonatomic) NSString *detectedIsoCountry3;
@property (nonatomic) double timeStampFirstDetection;
@property (nonatomic) double timeStampFirstLaunch;

// Extraction results
@property (nonatomic) NSMutableDictionary<NSString *, NSString *> *blinkCardFrontOcrData;
@property (nonatomic) NSMutableDictionary<NSString *, NSString *> *blinkCardBackOcrData;
@property (nonatomic) NSMutableDictionary<NSString *, NSString *> *blinkIdFrontOcrData;
@property (nonatomic) NSMutableDictionary<NSString *, NSString *> *blinkIdBackOcrData;

// Control flow flags
@property (nonatomic) bool needsVizInformation;
@property (nonatomic) bool documentNotExpected;

// Temporary images;
@property (nonatomic) UIImage *cameraImageFull;
@property (nonatomic) UIImage *cameraImageCropped;

//@Important: We store them as "MBImage" format because we don't want to convert to UIImage all of them. Just one!
@property (nonatomic) MBImage *imageFromBlinkID;
@property (nonatomic) MBImage *imageFromDocumentFace;
@property (nonatomic) MBImage *imageFromMrtd;
@property (nonatomic) MBImage *imageFromCrop;
@property (nonatomic) MBImage *faceFromBlinkID;
@property (nonatomic) MBImage *faceFromDocumentFace;

// Data for extract method (Not used in Android)
@property (nonatomic) double timeStamp;
@property (nonatomic, copy) onResultBlock onResultBlock;
@property (nonatomic, copy) onExceptionBlock onExceptionBlock;
@end
#endif /* FPhiMBMLDocumentExtractor_h */
