//
//  MMCommonAlertPublic.h
//  Paperang
//
//  Created by mb on 2020/6/5.
//  Copyright © 2020 Hoho. All rights reserved.
//

#ifndef MMCommonAlertPublic_h
#define MMCommonAlertPublic_h

#import "MMMacro.h"

/**
 * Block
 */
@class MMCommonBaseAlertResponseModel;
typedef void(^MMCommonAlertVoidBlock)(void);
//typedef void(^MMCommonAlertSenderBlock)(id sender);
//typedef void(^MMAlertSenderParamBlock)(id sender, id param);
//typedef void(^MMAlertSenderParam2Block)(id sender, id param1, id param2);
typedef void(^MMCommonAlertResponseBlock)(__kindof MMCommonBaseAlertResponseModel *response);


/**
 * Enumeration
 */
typedef NS_ENUM(NSUInteger, MMCommonAlertType) {
    /**
     * 标题--内容--取消--确认
     */
    MMCommonAlertTypeDefault,
    /**
     * 标题--内容--确认
     */
    MMCommonAlertTypeSingleButton,
    /**
     * 圆形图片--标题--内容--取消--确认
     */
    MMCommonAlertTypeCircleImage,
    /**
     * 长形图片--标题--内容--取消--确认
     */
    MMCommonAlertTypeRectangleImage,
    /**
     * 带有一个打钩的 alert, 场景
     */
    MMCommonAlertTypeCheckRecordBox,
    /**
     * 更新进度条
     */
    MMCommonAlertTypeProgress,
};


/**
 * Contants
 */
/// 类前缀
static NSString * const mm_alertPerfixConst                                         = @"MMCommonAlert";
/// 按照枚举写的常量
static NSString * const mm_alertXibNameDefault                                      = @"Default";
static NSString * const mm_alertXibNameSingleButton                                 = @"SingleButton";
static NSString * const mm_alertXibNameCircleImage                                  = @"CircleImage";
static NSString * const mm_alertXibNameRectangleImage                               = @"RectangleImage";
static NSString * const mm_alertXibNameCheckRecordBox                               = @"CheckRecordBox";
static NSString * const mm_alertXibNameProgress                               = @"Progress";

/**
 * Macro
 */

/// 加载 nib
#define MMAlertLoadNib(name) [[[NSBundle mmapiBundle] loadNibNamed:name owner:self options:nil] firstObject]

/// string 拼接
#define MMAlertString(fmt, ...) [NSString stringWithFormat:(fmt), ##__VA_ARGS__]
#define MMAlertString2(str1,str2) [NSString stringWithFormat:@"%@%@",str1,str2]
#define MMAlertStringWithOBJ(obj) [NSString stringWithFormat:@"%@",obj]
/// color
#define MMAlertColorHex(_hex_)   [UIColor colorWithRed:(((_hex_ & 0xFF0000) >> 16)) / 255.0 green:(((_hex_ & 0xFF00) >> 8)) / 255.0 blue:((_hex_ & 0xFF)) / 255.0 alpha:1.f]


#endif /* MMCommonAlertPublic_h */
