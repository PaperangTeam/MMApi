//
//  MMNavigationBar.h
//  Paperang
//
//  Created by mb on 2020/6/4.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MMNaviRightBtn.h"

@class MMNavigationBar;
// 主要处理导航条
@protocol  MMNavigationBarDataSource<NSObject>

@optional

/**头部标题*/
- (NSMutableAttributedString*)mm_navigationBarTitle:(MMNavigationBar *)navigationBar;

/** 背景图片 */
- (UIImage *)mm_navigationBarBackgroundImage:(MMNavigationBar *)navigationBar;
/** 背景色 */
- (UIColor *)mm_navigationBackgroundColor:(MMNavigationBar *)navigationBar;
/** 是否显示底部黑线 */
- (BOOL)mm_navigationIsHideBottomLine:(MMNavigationBar *)navigationBar;
/** 导航条的高度 */
- (CGFloat)mm_navigationHeight:(MMNavigationBar *)navigationBar;


/** 导航条的左边的 view */
- (UIView *)mm_navigationBarLeftView:(MMNavigationBar *)navigationBar;
/** 导航条右边的 view */
- (UIView *)mm_navigationBarRightView:(MMNavigationBar *)navigationBar;
/** 导航条中间的 View */
- (UIView *)mm_navigationBarTitleView:(MMNavigationBar *)navigationBar;
/** 导航条左边的按钮 */
- (UIImage *)mm_navigationBarLeftButtonImage:(UIButton *)leftButton navigationBar:(MMNavigationBar *)navigationBar;
/** 导航条右边的按钮 */
- (MMRightBtnModel *)mm_navigationBarRightButton:(UIButton *)rightButton navigationBar:(MMNavigationBar *)navigationBar;
@end


@protocol MMNavigationBarDelegate <NSObject>

@optional
/** 左边的按钮的点击 */
-(void)mm_leftButtonEvent:(UIButton *)sender navigationBar:(MMNavigationBar *)navigationBar;
/** 右边的按钮的点击 */
-(void)mm_rightButtonEvent:(UIButton *)sender navigationBar:(MMNavigationBar *)navigationBar;
/** 中间如果是 label 就会有点击 */
-(void)mm_titleClickEvent:(UILabel *)sender navigationBar:(MMNavigationBar *)navigationBar;
@end


@interface MMNavigationBar : UIView

/** 底部的黑线 */
@property (nonatomic, weak) UIView *mm_bottomBlackLineView;

/** titleView 需要实现协议 mm_navigationBarTitleView */
@property (nonatomic, strong) UIView *mm_titleView;

/** == leftBarButtonItem 实现协议 mm_navigationBarLeftView */
@property (nonatomic, weak) UIView *mm_leftView;

/** == rightBarButtonItem 实现协议 mm_navigationBarRightView*/
@property (nonatomic, weak) UIView *mm_rightView;

/** 标题, 如果实现 titleView 此属性无效, 协议对应 mm_navigationBarTitle*/
@property (nonatomic, copy) NSAttributedString *mm_title;

/** 数据源 */
@property (nonatomic, weak) id<MMNavigationBarDataSource> mm_dataSource;

/** 代理 */
@property (nonatomic, weak) id<MMNavigationBarDelegate> mm_delegate;

/** 背景图 */
@property (nonatomic, weak) UIImage *mm_backgroundImage;

@end

