//
//  FPhiWidgetOCRLineInfo.h
//  FPhiSelphIDWidgetiOS
//
//  Created by Javier Leal on 4/4/19.
//  Copyright © 2019 Facephi Biometria S.A. All rights reserved.
//

#ifndef FPhiWidgetOCRLineInfo_h
#define FPhiWidgetOCRLineInfo_h


@interface FPhiWidgetOCRLineInfo : NSObject

@property float left;
@property float top;
@property float right;
@property float bottom;

@property NSString *text;


@end

#endif /* FPhiWidgetOCRLineInfo_h */
