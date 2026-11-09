#ifndef FPhiSelphIDGraphProtocol_h
#define FPhiSelphIDGraphProtocol_h

@class FPhiGraphState;

@protocol FPhiSelphIDGraphProtocol

-(FPhiGraphState *)GetState :(NSString *)stateName;
-(void)doCancelByUser;
-(void)doTimeout;
-(void)doFinish;
-(void)doError:(NSError *)error;
-(void)doChangeCamera :(bool)frontCameraIfAvailable;

@end

#endif /* FPhiSelphIDGraphProtocol_h */
