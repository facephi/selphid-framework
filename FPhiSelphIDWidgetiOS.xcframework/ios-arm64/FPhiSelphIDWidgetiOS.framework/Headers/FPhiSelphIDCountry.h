//
//  FPhiSelphIDCountry.h
//  FPhiSelphIDWidgetiOS
//

#ifndef FPhiSelphIDCountry_h
#define FPhiSelphIDCountry_h

@interface FPhiSelphIDCountry : NSObject

-(id)init;

-(NSString *)getIso3:(NSString *)iso;
-(NSString *)getIso2:(NSString *)iso;
-(NSString *)getName:(NSString *)iso;
-(int)getNumeric:(NSString *)iso;

@end

#endif /* FPhiSelphIDCountry_h */
