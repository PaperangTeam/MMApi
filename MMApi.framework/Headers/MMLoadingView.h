//
//  MMLoadingView.h
//  MMApi
//
//  Created by mb on 2020/8/7.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MMLoadingView : UIView

@property (nonatomic, assign, class) BOOL isLoading;

+ (instancetype)loadingView;

/// 加载 2s
+ (BOOL)loading;
/// 超过 100s 就不自动隐藏
+ (BOOL)loadingAfter:(NSTimeInterval)timeInterval;
/// 超过 100s 就不自动隐藏, 展示在特定的 view 上
+ (BOOL)loadingAfter:(NSTimeInterval)timeInterval inView:(UIView * _Nullable)view;
+ (BOOL)remove;
@end

NS_ASSUME_NONNULL_END
