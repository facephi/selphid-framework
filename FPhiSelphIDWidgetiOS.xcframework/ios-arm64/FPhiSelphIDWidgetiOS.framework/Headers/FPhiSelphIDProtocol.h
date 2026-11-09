
#import <Foundation/Foundation.h>
#import "FPhiSelphIDFrameObj.h"
/**
    Set of behavior that is expected of an object in a given situation
 */
@protocol FPhiSelphIDWidgetProtocol

/**
    Invoked when the extraction process is finished.
    - Mandatory method
 */
-(void)CaptureFinished;


@optional

/**
 Invoked when the extraction process fail.
 - Optional method
 */
-(void)CaptureFailed:(NSError *) error;

/**
 Invoked when extraction process is cancelled by user.
 - Optional method
 */
-(void)CaptureCancelled;

/**
 Invoked when extraction process is aborted by timeout.
 - Optional method
 */
-(void)CaptureTimeout;

/**
  Invoked everytime there is an important event in the process
 - Optional method
 */
-(void)onEvent:(NSDate *)time type:(NSString *)type info:(NSString *)info;


@end
