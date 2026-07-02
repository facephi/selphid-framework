
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreGraphics/CoreGraphics.h>


/**
 Object to paint with over camera preview.
 */
@interface FPhiSelphIDFrameObj : NSObject


/**
 A Quartz 2D drawing environment.
 */
@property (nonatomic) CGContextRef context;

/**
 A structure that contains the location and dimensions of a rectangle.
 */
@property (nonatomic) CGRect bounds;

@end
