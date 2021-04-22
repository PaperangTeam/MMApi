//
//  MMCommonCheckRecordBoxModel.h
//  Paperang
//
//  Created by mb on 2020/7/9.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import "MMCommonBaseAlertRequestModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface MMCommonCheckRecordBoxRequestModel : MMCommonBaseAlertRequestModel

/**
 * 类似不再提醒按钮的文字展示
 */
@property (nonatomic, copy) NSString *mm_checkRecordText;
/**
 * 类似不再提醒按钮的文字展示, 选中状态
 */
@property (nonatomic, copy) NSString *mm_checkRecordSelectedText;
/**
 * 类似不再提醒按钮的文字字体
 */
@property (nonatomic, strong) UIFont *mm_checkRecordFont;
/**
 * 类似不再提醒按钮的文字字体, 选中状态
 */
@property (nonatomic, strong) UIFont *mm_checkRecordSelectedFont;
/**
 * 类似不在提醒按钮的文字颜色
 */
@property (nonatomic, strong) UIColor *mm_checkRecordColor;
/**
 * 类似不在提醒按钮的文字颜色, 选中状态
 */
@property (nonatomic, strong) UIColor *mm_checkRecordSelectedColor;
/**
 * 当前模式下允许标题多行
 */
@property (nonatomic, assign) CGFloat mm_titleNumberOfLines;
/**
 * 多行下标题的高度
 */
@property (nonatomic, assign, readonly) CGFloat mm_titleMoreThanHeight;

@end

NS_ASSUME_NONNULL_END
