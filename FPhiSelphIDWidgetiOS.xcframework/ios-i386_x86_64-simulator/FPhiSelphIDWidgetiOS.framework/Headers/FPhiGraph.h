//
//  FPhiGraph.h
//  FPhiUCios
//
//  Created by Ruben Leal on 16/5/17.
//  Copyright © 2017 Facephi Biometria S.A. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "FPhiGraphState.h"
#import "FPhiGraphTransition.h"

typedef NS_ENUM(NSUInteger, FPhiGraphStatus) {
    
    FGSUnknown = 0,
    FGSLoaded = 1,
    FGSRunning = 2,
};

@protocol FPhiGraphProtocol <NSObject>

-(FPhiGraphState *)GetState :(NSString *)stateName;
-(void)doCancelByUser;
-(void)doTimeout;
-(void)doFinish;
-(void)doError:(NSError *)error;
-(void)doChangeCamera :(bool)frontCameraIfAvailable;

@end


@interface FPhiGraph : NSObject<NSXMLParserDelegate>

@property(nonatomic,assign)id delegate;
@property (nonatomic) NSMutableDictionary<NSString *,FPhiGraphState *> *states;
@property (nonatomic) NSMutableDictionary<NSString *,FPhiGraphTransition *> *transitions;
@property (nonatomic) NSMutableDictionary<NSString *,NSObject *> *vars;
@property (nonatomic) FPhiGraphStatus status;

@property (nonatomic) NSDate *previousTime;
@property (nonatomic) NSDate *actualTime;

-(void)draw:(CGContextRef)context :(CGSize)canvasSize;
-(void)execute:(CGSize)canvasSize;
-(void)onTap:(CGPoint)position :(CGSize)canvasSize;
-(void)onTouchesBegan:(NSSet<UITouch *> *)touches :(UIView *)view;
-(void)onTouchesEnded:(NSSet<UITouch *> *)touches :(UIView *)view;
-(void)setInitialState:(NSString *)stateName :(CGSize)canvasSize;
-(void)onSwipe:(UISwipeGestureRecognizer *)swipe;
-(void)onPlayerDidReachEnd:(NSNotification *)notification;

//-(BOOL)jump:(NSString *)transitionName;
-(void)sendMessage:(NSString *)message;
-(void)raiseCancelByUser;
-(void)raiseTimeout;
-(void)raiseFinish;
-(void)raiseError :(NSError *)error;
-(void)raiseChangeCamera :(bool)frontCameraIfAvailable;

-(double) getTotalVideoTimeFromStart;
-(NSBundle *)getBundle;
- (void)focusWithMode:(AVCaptureFocusMode)focusMode exposeWithMode:(AVCaptureExposureMode)exposureMode atDevicePoint:(CGPoint)point monitorSubjectAreaChange:(BOOL)monitorSubjectAreaChange;
+(FPhiGraph *)loadFromFile:(NSString *)url :(id)delegateState;
+(FPhiGraph *)loadFromString:(NSString *)str :(id)delegateState;

@end
