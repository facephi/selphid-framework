//
//  FPhiSelphIDOCRVM.h
//  FPhiSelphIDWidgetiOS
//
//  Copyright © 2021 Facephi Biometria S.A. All rights reserved.
//

#ifndef FPhiSelphIDOCRVM_h
#define FPhiSelphIDOCRVM_h

#import "FPhiSelphIDDocumentManager.h"
#import "FPhiSelphIDOCRTextInfo.h"

@interface FPhiSelphIDOCRVM : NSObject

-(id)initWithDocumentManager:(FPhiSelphIDDocumentManager *)DM substitutionCosts:(NSMutableDictionary<NSString *, NSNumber *> *)substitutionCosts;

-(NSString *)extractDataFromOCR:(FPhiSelphIDOCRInfo *)result documentCaptured:(NSString *)documentCaptured side:(NSString *)documentSide tagML:(NSString *)tagML ocrResults:(NSMutableDictionary<NSString *, NSString *> *)ocrResults;


@end

#endif /* FPhiSelphIDOCRVM_h */
