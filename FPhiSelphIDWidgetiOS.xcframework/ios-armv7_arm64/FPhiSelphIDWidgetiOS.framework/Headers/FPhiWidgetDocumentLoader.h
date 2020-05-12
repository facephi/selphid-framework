#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface FPhiWidgetDocumentNode:NSObject

@property (nonatomic) FPhiWidgetDocumentNode *parent;
@property (nonatomic) NSMutableDictionary<NSString *,FPhiWidgetDocumentNode *> *childs;
@property (nonatomic) NSMutableDictionary<NSString *,NSString *> *attributes;
@property (nonatomic) NSMutableArray<NSString *> *childsSorted;

@end


@interface FPhiWidgetDocumentLoader : NSObject<NSXMLParserDelegate>

+(FPhiWidgetDocumentNode *)loadDocument:(NSInputStream *)is;

@end


