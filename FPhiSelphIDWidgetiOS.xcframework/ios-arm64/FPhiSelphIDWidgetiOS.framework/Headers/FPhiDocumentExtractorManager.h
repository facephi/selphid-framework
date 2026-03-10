#ifndef FPhiDocumentExtractorManager_h
#define FPhiDocumentExtractorManager_h

#import "IFPhiDocumentExtractor.h"


@interface ExtractorData : NSObject
@property (nonatomic) IFPhiDocumentExtractor *extractor;
@property (nonatomic) float initTime;
@property (nonatomic) float endTime;
@property (nonatomic) bool active;
@end


@interface FPhiDocumentExtractorManager : IFPhiDocumentExtractor

-(id)initWithExtractorNames:(NSArray<NSString *> *)extractorNames andExtractorTimes:(NSArray<NSNumber *> *)extractorTimes;
+(bool)isAvailable:(NSString *)name;
-(void)setCurrentExtractorActive:(bool)value;
-(void)setAllExtractorsActive:(bool)value;
-(void)setCurrentExtractorAsPrimary;
-(void)updateExtractorByTime:(float)elapsedSeconds;

@end

#endif /* FPhiDocumentExtractorManager_h */
