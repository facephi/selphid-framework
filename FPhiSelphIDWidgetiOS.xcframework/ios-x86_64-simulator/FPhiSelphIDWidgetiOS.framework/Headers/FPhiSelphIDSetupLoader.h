
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface FPhiSelphIDSetupNode:NSObject

@property (nonatomic) FPhiSelphIDSetupNode *parent;
@property (nonatomic) NSMutableDictionary<NSString *,FPhiSelphIDSetupNode *> *childs;
@property (nonatomic) NSMutableDictionary<NSString *,NSString *> *attributes;

@end


@interface FPhiSelphIDSetupLoader : NSObject<NSXMLParserDelegate>

+(FPhiSelphIDSetupNode *)loadSetup:(NSInputStream *)is;

+(UIColor *) getColorFromString:(NSString *)string;

@end


