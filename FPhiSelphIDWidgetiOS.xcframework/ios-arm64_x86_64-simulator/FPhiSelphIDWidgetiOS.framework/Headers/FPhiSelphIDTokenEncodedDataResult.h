//
//  FPhiSelphIDTokenEncodedDataResult.h
//  FPhiSelphIDWidgetiOS
//

#ifndef FPhiSelphIDTokenEncodedDataResult_h
#define FPhiSelphIDTokenEncodedDataResult_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FPhiSelphIDWidgetDocumentSide.h"

@interface FPhiSelphIDTokenEncodedDataResult : NSObject

@property (nonatomic) NSString *token;
@property (nonatomic) NSString *format;
@property (nonatomic) FPhiSelphIDWidgetDocumentSide side;

@end

#endif

