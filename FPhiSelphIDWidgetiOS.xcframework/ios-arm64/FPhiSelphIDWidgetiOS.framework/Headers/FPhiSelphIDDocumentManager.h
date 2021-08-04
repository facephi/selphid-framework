
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface FPhiSelphIDDocumentManager : NSObject<NSXMLParserDelegate>

@property (nonatomic) bool initedWithString;


- (id)init :(NSString *)documentsPath :(NSString *)filename;
- (id)initWithString :(NSString *)str;

- (BOOL) isInitialized;

// setup-configuration api
- (NSString *) getDocumentNode:(NSString *)nodePath;
- (NSString *) getDocumentNode:(NSString *)nodePath isOptional:(bool)optional;
- (NSArray<NSString *> *) getDocumentNodes:(NSString *)nodePath;
- (NSArray<NSString *> *) getDocumentNodes:(NSString *)nodePath isOptional:(bool)optional;

@end
