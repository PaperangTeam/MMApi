//
//  MMShareVC.h
//  MMApi
//
//  Created by mb on 2020/8/12.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^MMShareMarketingBlock)(void);

@interface MMShareVC : NSObject

@property (nonatomic, copy, class) MMShareMarketingBlock _Nullable marketingBlock;

/// 前往设备连接页面
/// @param naviViewController 一个 navigationcontroller 目的是 push
/// @param isFromMarketing 是否从营销页进入设备连接页面
+ (void)gotoDeviceListVCFrom:(UINavigationController * _Nullable)naviViewController isFromMarketing:(BOOL)isFromMarketing;

/// 前往打印预览页面
/// @param naviViewController 一个 navigationcontroller 目的是 push
/// @param flag                                 需要预览的数据结构 标志, 用于回调给主端
/// @param renderBlock                 当渲染准备完成时操作, 用于拿数据
+ (void)gotoPrintPreviewVCFrom:(UINavigationController * _Nullable)naviViewController dataFlag:(NSString *)flag renderBlock:(void (^)(NSString *flag))renderBlock;

/// 打印预览页刷新数据
/// @param printData 一个渲染需要的 data json 数据结构
+ (void)reloadPrintData:(NSString *)printData;


/// 前往喵宝营销页
/// @param naviViewController 一个 navigationcontroller 目的是 push
/// @return     返回跳转成功或者失败
+ (BOOL)gotoMBMarketingVCFrom:(UINavigationController * _Nullable)naviViewController;
@end

NS_ASSUME_NONNULL_END
