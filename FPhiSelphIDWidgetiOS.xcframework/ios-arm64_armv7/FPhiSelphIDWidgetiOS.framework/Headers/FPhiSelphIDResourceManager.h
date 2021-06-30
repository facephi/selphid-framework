
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define FPHIUCSETUPITEM_TEXT_ID     1
#define FPHIUCSETUPITEM_RESOURCE_ID 2

#define FPHIUCSETUPALIGN_LEFT 1
#define FPHIUCSETUPALIGN_RIGHT 2
#define FPHIUCSETUPALIGN_CENTER 3

@interface FPhiSelphIDResourceManager : NSObject<NSXMLParserDelegate>

- (id)init :(NSString *)resourcesPath;
- (void)setLocale:(NSString *)locale;


// localize api
-(NSString *)translate:(NSString *)string;
-(NSString *)translate:(NSString *)string :(NSString *)locale;

// setup-configuration api
- (int) getSetupVersion;
- (UIColor *) getSetupColor:(NSString *)nodePath;
- (UIColor *) getSetupColor:(NSString *)nodePath isOptional:(bool)optional;
- (float) getSetupFloatOrDefault:(NSString *)nodePath :(float)defaultValue;
- (int) getSetupContentType:(NSString *)nodePath;
- (int) getSetupAlign:(NSString *)nodePath;
- (NSString *) getSetupNode:(NSString *)nodePath;
- (NSString *) getSetupNode:(NSString *)nodePath isOptional:(bool)optional;
- (bool) setupNodeExists:(NSString *)nodePath;
- (bool)isAttribute:(NSString *)nodePath;

// load resources api
-(void) clearResourcesCache;
-(UIImage *)getImage:(NSString *)resourceName;
-(NSString *)getVideoUrl:(NSString *)resourceName;
- (NSString *) getFontName:(NSString *)nodePath;

@end
