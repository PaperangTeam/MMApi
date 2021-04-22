//
//  MMCommonBaseAlertRequestModel.h
//  Paperang
//
//  Created by mb on 2020/6/5.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import "MMCommonBaseAlertModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface MMCommonBaseAlertRequestModel : MMCommonBaseAlertModel

/**
 * alert type
 */
@property (nonatomic, assign) MMCommonAlertType mm_type;
/**
 * 标题
 */
@property (nonatomic, copy) NSString *mm_title;
/**
 * 标题字体
 */
@property (nonatomic, strong) UIFont *mm_titleFont;
/**
 * 标题颜色
 */
@property (nonatomic, strong) UIColor *mm_titleColor;
/**
 * 内容
 */
@property (nonatomic, copy) NSString *mm_content;
/**
 * 内容行数, 默认 2 行
 */
@property (nonatomic, assign) NSInteger mm_contentNumberOfLines;
/**
 * 内容超过两行的高度, 现版本需求默认不超过两行内容
 */
@property (nonatomic, assign, readonly) CGFloat mm_contentMoreThanHeight;
/**
 * 内容字体
 */
@property (nonatomic, strong) UIFont *mm_contentFont;
/**
 * 内容颜色
 */
@property (nonatomic, strong) UIColor *mm_contentColor;
/**
 * 确认功能的按钮名称
 */
@property (nonatomic, copy) NSString *mm_confirmName;
/**
 * 确认字体
 */
@property (nonatomic, strong) UIFont *mm_confirmFont;
/**
 * 确认颜色
 */
@property (nonatomic, strong) UIColor *mm_confirmTextColor;
/**
 * 确认背景颜色
 */
@property (nonatomic, strong) UIColor *mm_confirmBgColor;
/**
 * 确认背景图片名称
 */
@property (nonatomic, copy) NSString *mm_confirmBgImageName;
/**
 * 确认边框颜色
 */
@property (nonatomic, strong) UIColor *mm_confirmBorderColor;
/**
 * 确认边框宽度
 */
@property (nonatomic, assign) CGFloat mm_confirmBorderWidth;
/**
 * 取消功能的按钮名称
 */
@property (nonatomic, copy) NSString *mm_cancelName;
/**
 * 取消字体
 */
@property (nonatomic, strong) UIFont *mm_cancelFont;
/**
 * 取消颜色
 */
@property (nonatomic, strong) UIColor *mm_cancelTextColor;
/**
 * 取消背景颜色
 */
@property (nonatomic, strong) UIColor *mm_cancelBgColor;
/**
 * 取消边框颜色
 */
@property (nonatomic, strong) UIColor *mm_cancelBorderColor;
/**
 * 取消边框宽度
 */
@property (nonatomic, assign) CGFloat mm_cancelBorderWidth;
/**
 * 取消背景图片名称
 */
@property (nonatomic, copy) NSString *mm_cancelBgImageName;
/**
 * 图片名称或者 URL
 */
@property (nonatomic, copy) NSString *mm_imageName;
/**
 * 占位图名称
 */
@property (nonatomic, copy) NSString *mm_placeHolderName;
/**
 * 是否有圆角
 */
@property (nonatomic, assign) BOOL mm_hasCornerRadius;
/**
 * 背景颜色
 */
@property (nonatomic, strong) UIColor *mm_bgColor;

/**
 * 点击取消回调
 */
@property (nonatomic, copy) MMCommonAlertResponseBlock mm_cancel;
/**
 * 点击确定回调
 */
@property (nonatomic, copy) MMCommonAlertResponseBlock mm_confirm;

@property (nonatomic, assign) BOOL mm_hasOnlyCancelBtn;
/**
 * 只有在 RectangleImage 下有效, 并且设置 down 是无效的
 * 修改这个边距只能修改这个 image 距离上左右的间距
 */
@property (nonatomic, assign) UIEdgeInsets rectangleImageInsets;

@end

NS_ASSUME_NONNULL_END
