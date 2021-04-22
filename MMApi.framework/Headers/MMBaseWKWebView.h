//
//  MMBaseWKWebView.h
//  Paperang
//
//  Created by colayet on 2020/1/10.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <WebKit/WebKit.h>
#import "JSRequestModel.h"
#import "WKWebView+Category.h"

#import "JSResponseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface MMBaseWKWebView : WKWebView

@property (nonatomic,copy) void (^gotoPrintVCBlock)(JSRequestModel *jsRequest,UIImage *img,JSResponseModel *jsRes);
@property (nonatomic,copy) void (^gotoWebPageBlock)(NSString *url,NSString *title);
@property (nonatomic,copy) void (^gotoYZWebPageBlock)(NSString *url);
@property (nonatomic,copy) void (^closeWebPageBlock)(void);
@property (nonatomic,copy) void (^shareBlock)(MMBaseWKWebView *me,JSRequestModel *jsRequest);
@property (nonatomic,copy) void (^showStatuBarBlock)(MMBaseWKWebView *me,BOOL show);
@property (nonatomic,copy) void (^setTitleBlock)(NSString *title);
@property (nonatomic,copy) void (^printPageComplete)(void);
 
#pragma mark - WKNavigationDelegate

@property (nonatomic,copy) void (^didStartProvisionalNavigationBlock)(MMBaseWKWebView *me,WKNavigation *navigation);
@property (nonatomic,copy) void (^didFailNavigationBlock)(MMBaseWKWebView *me,WKNavigation *navigation,NSError *error);
@property (nonatomic,copy) void (^didFinishNavigationBlock)(MMBaseWKWebView *me,WKNavigation *navigation);
@property (nonatomic,copy) void (^didFailLoadWithErrorBlock)(MMBaseWKWebView *me, NSError *error);
@property (nonatomic,copy) void (^didFailProvisionalNavigationBlock)(MMBaseWKWebView *me,WKNavigation *navigation,NSError *error);
@property (nonatomic,copy) void (^decidePolicyForNavigationActionBlock)(MMBaseWKWebView *me,WKNavigationAction *navigationAction,void (^decisionHandler)(WKNavigationActionPolicy));//url拦截

#pragma mark - WKScriptMessageHandler

@property (nonatomic,copy) void (^didReceiveScriptMessageBlock)(MMBaseWKWebView *me,
WKUserContentController *userContentController,WKScriptMessage *message);

#pragma mark - WKUIDelegate

@property (nonatomic,copy) void (^runJavaScriptAlertPanelWithMessageBlock)(MMBaseWKWebView *me,NSString *message,WKFrameInfo *frame,void (^completionHandler)(void));
@property (nonatomic,copy) void (^runJavaScriptConfirmPanelWithMessageBlock)(MMBaseWKWebView *me,NSString *message,WKFrameInfo *frame,void (^completionHandler)(BOOL));
@property (nonatomic,copy) void (^runJavaScriptTextInputPanelWithPromptBlock)(MMBaseWKWebView *me,NSString *prompt,NSString *defaultText,WKFrameInfo *frame,void (^completionHandler)(NSString * _Nullable));


/// 处理事件，子类可重写
- (void)handleEventWithMessageName:(WKScriptMessage *)message NS_REQUIRES_SUPER;
- (void)reloadWith:(NSString *)url;

/// 预先设置脚本，子类可重写
- (void)customJSStringSetup:(NSString *)customJSString;

/// 注册消息,内部自动去重
/// @param addCustomScriptMessageArray NSString
- (void)addCustomScriptMessageArraySetup:(NSArray <NSString *>*)addCustomScriptMessageArray;

/// 销毁自己,使用者的dealloc必须调用
- (void)releaseMe;

/// 执行脚本
/// @param jsScript jsScript description
- (void)evalueteJS:(NSString *)jsScript;


@end

NS_ASSUME_NONNULL_END
