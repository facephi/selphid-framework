/*
 #ifndef FPhiRegulaDocumentExtractor_h
 #define FPhiRegulaDocumentExtractor_h
 
 #import "IFPhiDocumentExtractor.h"
 #import "FPhiSelphIDWidgetDocumentType.h"
 #import "FPhiSelphIDWidgetDocumentSide.h"
 #import "FPhiSelphIDCountry.h"
 
 // 3rd party library
 #import "DocumentReader/DocumentReader.h"
 
 
 @interface FPhiRegulaDocumentExtractor : IFPhiDocumentExtractor
 // Input
 @property (nonatomic) int width;
 @property (nonatomic) int height;
 @property (nonatomic) IFPhiDocumentExtractorImageRotation rotation;
 @property (nonatomic) IFPhiDocumentExtractorImageFormat format;
 @property (nonatomic) CGRect ROI;
 @property (nonatomic) bool isStream;
 
 // Control flow
 @property (atomic) int creatingProgress;
 
 // Temporary images;
 @property (nonatomic) UIImage *cameraImageFull;
 @property (nonatomic) UIImage *cameraImageCropped;
 
 // Results for each documentVarsion
 @property (nonatomic) NSMutableDictionary<NSString *, IFPhiDocumentExtractorResult *> *results;
 
 // Extraction data
 @property (nonatomic) NSString *documentKey;
 @property (nonatomic) NSString *documentVersionKey;
 @property (nonatomic) NSString *documentCountry;
 @property (nonatomic) NSString *documentVersion;
 @property (nonatomic) FPhiSelphIDWidgetDocumentType docType;
 @property (nonatomic) FPhiSelphIDWidgetDocumentSide docSide;
 
 @property (nonatomic) double timeStampFirstDetection;
 @property (nonatomic) double timeStampFirstLaunch;
 
 @property (nonatomic) bool faceMandatory;
 @property (nonatomic) bool mrzMandatory;
 @property (nonatomic) bool pdfMandatory;
 @property (nonatomic) bool barcodeMandatory;
 @property (nonatomic) bool fullScanMandatory;
 @property (nonatomic) bool creditCardMandatory;
 
 @property (nonatomic) bool facePresent;
 @property (nonatomic) bool mrzPresent;
 @property (nonatomic) bool pdfPresent;
 @property (nonatomic) bool barcodePresent;
 @property (nonatomic) bool fullScanPresent;
 @property (nonatomic) bool creditCardPresent;
 
 @property (nonatomic) double timeoutOptionalData;
 
 @property (nonatomic) FPhiSelphIDCountry *countriesDatabase;
 
 // Data for extract method (Not used in Android)
 @property (nonatomic) double timeStamp;
 @property (nonatomic, copy) onResultBlock onResultBlock;
 @property (nonatomic, copy) onExceptionBlock onExceptionBlock;
 @end
 #endif
 */
