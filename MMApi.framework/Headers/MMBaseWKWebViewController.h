//
//  MMBaseWKWebViewController.h
//  Paperang
//
//  Created by 王明阳 on 2019/10/31.
//  Copyright © 2019 Hoho. All rights reserved.
//  网页浏览的基类(WKWebView)

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "MMBaseWKWebView.h"
#import "JSBridgeWebFeatureConfig.h"
#import "MMCustomNaviBaseViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface MMBaseWKWebViewController : MMCustomNaviBaseViewController

/**
 * 是否展示进度条, 默认是 YES
 */
@property (nonatomic, assign) BOOL canShowProgress;
@property (nonatomic, strong, readonly) JSBridgeWebFeatureConfig *featureConfig;
@property (nonatomic ,strong) MMBaseWKWebView *myWebView;

@property (nonatomic ,copy) NSString *url;

-(instancetype)initWithUrl:(NSString *)url;

/// 监听事件名数组，子类可重写，可获取数组再添加新的数据进来
- (NSArray *)scriptMessageArray;

/// 页面title，子类可重写
- (NSString *)getTitleWithWebTitle:(NSString *)webTitle;

/// 处理事件，子类可重写
- (void)handleEventWithMessageName:(WKScriptMessage *)message NS_REQUIRES_SUPER;

/// 客户端调用前端
- (void)evalueteJS:(NSString *)jsScript completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))completionHandler;

/// 页面是否加载完
@property (nonatomic, assign) BOOL isWebLoadFinish;

/// 最重要的那个标题拉
@property (nonatomic, copy) NSString *theMostImportantTitle;

/// 监听到断网时不展示重载按钮
@property (nonatomic, assign) BOOL doNotShowRefreshBtnWhenBadNetwork;

@end

NS_ASSUME_NONNULL_END
