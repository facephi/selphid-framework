//
//  FPhiWidgetLicenseInfo.h
//  FPhiSelphIDWidgetiOS
//

#ifndef FPhiWidgetLicenseInfo_h
#define FPhiWidgetLicenseInfo_h

@interface FPhiWidgetLicenseInfo : NSObject

-(bool)isLicenseDocument;
-(bool)isLicenseFacial;
-(bool)isLicenseTokenDocument;

-(void)setLicenseDocument:(bool)v;
-(void)setLicenseFacial:(bool)v;
-(void)setLicenseTokenDocument:(bool)v;

@end


#endif /* FPhiWidgetLicenseInfo_h */
