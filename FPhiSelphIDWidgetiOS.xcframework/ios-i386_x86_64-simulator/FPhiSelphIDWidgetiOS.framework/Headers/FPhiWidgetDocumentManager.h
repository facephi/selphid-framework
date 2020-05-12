
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface FPhiWidgetDocumentManager : NSObject<NSXMLParserDelegate>

- (id)init :(NSString *)documentsPath;


// setup-configuration api
- (NSString *) getDocumentNode:(NSString *)nodePath;
- (NSString *) getDocumentNode:(NSString *)nodePath isOptional:(bool)optional;
- (NSArray<NSString *> *) getDocumentNodes:(NSString *)nodePath;

@end
