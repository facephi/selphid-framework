
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//#import "FPhiUCSetupItem.h"

@interface FPhiWidgetSetupNode:NSObject

@property (nonatomic) FPhiWidgetSetupNode *parent;
@property (nonatomic) NSMutableDictionary<NSString *,FPhiWidgetSetupNode *> *childs;
@property (nonatomic) NSMutableDictionary<NSString *,NSString *> *attributes;

@end


@interface FPhiWidgetSetupLoader : NSObject<NSXMLParserDelegate>

+(FPhiWidgetSetupNode *)loadSetup:(NSInputStream *)is;

+(UIColor *) getColorFromString:(NSString *)string;

@end


