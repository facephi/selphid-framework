
#ifndef FPhiSelphIDML_h
#define FPhiSelphIDML_h

#import <UIKit/UIKit.h>
#import "FPhiSelphIDOCRTextInfo.h"

@protocol FPhiSelphIDMLCallback <NSObject>
- (void) onSuccessResult:(NSString *)tagML ocr:(FPhiSelphIDOCRInfo *)ocrInfo;
- (void) onException:(NSString *)tagML error:(NSError *)e;
@end

@interface FPhiSelphIDML : NSObject

+(bool)isSupported;

-(id)initWithParams:(NSDictionary *)params;

-(void)extractOCRFromDocument:(UIImage *)imageToAnalyze tagML:(NSString *)tagML :(id<FPhiSelphIDMLCallback>)callback;

@end


#endif /* FPhiSelphIDML_h */
