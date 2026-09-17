//
//  FPhiSelphIDEncodedDataResult.h
//  FPhiSelphIDWidgetiOS
//

#ifndef FPhiSelphIDEncodedDataResult_h
#define FPhiSelphIDEncodedDataResult_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FPhiSelphIDWidgetDocumentSide.h"

@interface FPhiSelphIDEncodedDataResult : NSObject

@property (nonatomic) UIImage *image;
@property (nonatomic) NSString *format;
@property (nonatomic) FPhiSelphIDWidgetDocumentSide side;

@end

#endif

