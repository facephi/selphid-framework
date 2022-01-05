
#ifndef FPhiSelphIDOCRInfo_h
#define FPhiSelphIDOCRInfo_h


@interface FPhiSelphIDOCRTextInfo : NSObject

@property float left;
@property float top;
@property float right;
@property float bottom;

@property NSString *text;

@end

@interface FPhiSelphIDOCRElementInfo : NSObject

@property float left;
@property float top;
@property float right;
@property float bottom;

@property NSString *text;

@end

@interface FPhiSelphIDOCRLineInfo : NSObject

@property float left;
@property float top;
@property float right;
@property float bottom;

@property NSString *text;

@property NSMutableArray<FPhiSelphIDOCRElementInfo *> *elements;

@end


@interface FPhiSelphIDOCRBlockInfo : NSObject

@property float left;
@property float top;
@property float right;
@property float bottom;

@property NSString *text;

@property NSMutableArray<FPhiSelphIDOCRLineInfo *> *lines;

@end

@interface FPhiSelphIDOCRInfo : NSObject

@property NSString *text;
@property UIImage *image;

@property NSMutableArray<FPhiSelphIDOCRBlockInfo *> *blocks;

@end

#endif /* FPhiSelphIDOCRInfo_h */
