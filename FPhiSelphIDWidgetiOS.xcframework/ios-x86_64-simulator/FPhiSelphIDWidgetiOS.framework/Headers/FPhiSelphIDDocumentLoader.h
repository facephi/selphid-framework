#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface FPhiSelphIDDocumentNode:NSObject

@property (nonatomic) FPhiSelphIDDocumentNode *parent;
@property (nonatomic) NSMutableDictionary<NSString *,FPhiSelphIDDocumentNode *> *childs;
@property (nonatomic) NSMutableDictionary<NSString *,NSString *> *attributes;
@property (nonatomic) NSMutableArray<NSString *> *childsSorted;

@end


@interface FPhiSelphIDDocumentLoader : NSObject<NSXMLParserDelegate>

+(FPhiSelphIDDocumentNode *)loadDocument:(NSInputStream *)is;
+(FPhiSelphIDDocumentNode *)loadDocumentFromString:(NSString *)str;

@end


