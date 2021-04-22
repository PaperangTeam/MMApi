//
//  WKWebView+Category.h
//  Paperang
//
//  Created by 王明阳 on 2019/10/23.
//  Copyright © 2019 Hoho. All rights reserved.
//
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WKWebView (Category)

/// 利用PDF进行长截图
- (void)mmCaptureWithComletion:(void (^)(UIImage *result))completion;

- (void)mmEvaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^)(id _Nullable v, CGFloat scrollHeight, NSError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
