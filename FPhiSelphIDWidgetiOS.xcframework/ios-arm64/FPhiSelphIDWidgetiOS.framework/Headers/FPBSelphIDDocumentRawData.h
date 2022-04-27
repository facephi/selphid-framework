
#import <Foundation/Foundation.h>

/**
 
 */
@interface FPBSelphIDDocumentRawData : NSObject<NSCopying>

/**
 Sets license.
 */
-(int)setLicense:(NSString*)licenseContent;

/**
 Gets license status.
 */
@property (nonatomic, readonly) int licenseStatus;

/**
 Gets document license.
 */
@property (nonatomic, readonly) NSString* licenseDocument;

/**
 Gets or sets valid data.
 */
@property (nonatomic) bool validData;

/**
 Gets document data.
 */
@property (nonatomic, readonly) NSDictionary<NSString*, NSString*>* documentData;

/**
 Adds document data.
 */
-(void)addDocumentData:(NSDictionary<NSString*, NSString*>*) documentData;

/**
 Removes document data with starting key;
 */
-(int)removeDocumentDataWithKeyStartedByKey:(NSString*)startingKey;

/**
 Gets document extra data.
 */
@property (nonatomic, readonly) NSDictionary<NSString*, NSString*>* extraData;

/**
 Adds extra data.
 */
-(void)addExtraData:(NSDictionary<NSString*, NSString*>*) extraData;

/**
 Gets document model.
 */
@property (nonatomic, readonly) NSArray<NSArray<NSString*>*>* documentModel;

/**
 Adds document model.
 */
-(void)addDocumentModel:(NSArray<NSArray<NSString*>*>*) documentModel;

/**
 Gets image data.
 */
@property (nonatomic, readonly) NSDictionary<NSString*, NSData*>* imageData;

/**
 Adds image data.
 */
-(void)addImageData:(NSDictionary<NSString*, NSData*>*) imageData;

/**
 Clear all data.
 */
-(void)clear;

/**
 Formats raw data.
 */
-(bool)formatRawData;

/**
 Gets binary raw formatted.
 */
-(NSData*)getFormattedRawBinary;

/**
 Gets Base 64 string raw formatted
 */
-(NSString*)getFormattedRawBase64;

/**
 Deformat selphIDDocumentRawData from binary buffer.
 */
-(int)deFormatRawDataBinary:(NSData*) data;

/**
 Deformat selphIDDocumentRawData from base64 string.
 */
-(int)deFormatRawDataBase64:(NSString*) data;


@end
