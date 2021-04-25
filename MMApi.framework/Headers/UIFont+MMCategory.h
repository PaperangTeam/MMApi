//
//  UIFont+MMCategory.h
//  MMApi
//
//  Created by mb on 2020/8/7.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 常规体
UIKIT_EXTERN NSString * const _Nonnull MMRegularFontName;

/// 页面title
UIKIT_EXTERN CGFloat const MMTitleFontSize;

/// 标题栏选中tab
UIKIT_EXTERN CGFloat const MMTitleTabSelectFontSize;

UIKIT_EXTERN CGFloat const MMTitleTabNormalFontSize;

/// 二级信息：正文、行间距20px 
UIKIT_EXTERN CGFloat const MMContentFontSize;

NS_ASSUME_NONNULL_BEGIN

@interface UIFont (MMCategory)

+ (UIFont *)mm_regularFontWithFontSize:(CGFloat)fontSize;
+ (UIFont *)mm_mediumFontWithFontSize:(CGFloat)fontSize;
+ (UIFont *)mm_semiboldFontWithFontSize:(CGFloat)fontSize;
@end

NS_ASSUME_NONNULL_END
