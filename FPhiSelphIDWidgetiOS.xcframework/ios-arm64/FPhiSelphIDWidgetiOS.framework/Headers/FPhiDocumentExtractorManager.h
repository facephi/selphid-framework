#ifndef FPhiDocumentExtractorManager_h
#define FPhiDocumentExtractorManager_h

#import "IFPhiDocumentExtractor.h"


@interface FPhiDocumentExtractorManager : NSObject

+(BOOL)isAvailable:(NSString *)name;

-(id)initWithName:(NSString *)name;
-(IFPhiDocumentExtractor *)getExtractor;

@end

#endif /* FPhiDocumentExtractorManager_h */
