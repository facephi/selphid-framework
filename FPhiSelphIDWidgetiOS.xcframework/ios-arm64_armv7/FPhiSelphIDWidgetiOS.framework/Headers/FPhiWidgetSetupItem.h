
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define FPHIUCSETUPITEM_COLOR       0
#define FPHIUCSETUPITEM_TEXT_ID     1
#define FPHIUCSETUPITEM_RESOURCE_ID 2
#define FPHIUCSETUPITEM_FLOAT       3
#define FPHIUCSETUPITEM_ALIGN       4

#define FPHIUCSETUPITEM_ALIGN_LEFT   0
#define FPHIUCSETUPITEM_ALIGN_RIGHT  1
#define FPHIUCSETUPITEM_ALIGN_CENTER 2

@interface FPhiUCSetupItem : NSObject

-(id) init:(NSString *)name withColor:(UIColor *)color;
-(id) init:(NSString *)name withResourceId:(NSString *)resourceId;
-(id) init:(NSString *)name withTextId:(NSString *)textId;
-(id) init:(NSString *)name withFloat:(float)floatValue;
-(id) init:(NSString *)name withAlign:(int)intValue;

-(NSInteger) getType;
-(NSString *)getName;

-(UIColor *) asColor;
-(NSString *)asTextId;
-(NSString *)asResourceId;
-(float) asFloat;
-(int) asAlign;

@end
