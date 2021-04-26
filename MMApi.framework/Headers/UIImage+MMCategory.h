//
//  UIImage+MMCategory.h
//  MMApi
//
//  Created by mb on 2020/8/4.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    MMGradientTypeTopToBottomimage,//从上到小
    MMGradientTypeLeftToRightimage,//从左到右
    MMGradientTypeUpleftToLowrightimage,//左上到右下
    MMGradientTypeUprightToLowleftimage,//右上到左下
} MMGradientTypeimage;

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (MMCategory)

/// 设置渐变颜色
+ (UIImage *)gradientColorImageFromColors:(NSArray*)colors gradientType:(MMGradientTypeimage)gradientType imgSize:(CGSize)imgSize;

/// 获取 framework 内的图片, name 对应的 image 会做缓存, 所以名字相同的换了图片不生效
+ (UIImage *)imageWithBundleNamed:(NSString *)name;

/// 给图片绘制居中文字
- (UIImage *)imageWithCenterText:(NSString *)centerText textColor:(UIColor *)color font:(UIFont *)font insets:(UIEdgeInsets)insets;
@end

NS_ASSUME_NONNULL_END
