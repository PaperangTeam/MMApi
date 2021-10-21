//
//  JSBridgeConfig.h
//  Paperang
//
//  Created by colayet on 2019/12/22.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JSRequestModel.h"
#import "JSResponseModel.h"

NS_ASSUME_NONNULL_BEGIN

#define JSBridgeConfigNative @"PaperangNative"
#define JSBridgeConfigGetAuthCode @"getAuthCode"

@interface JSBridgeConfig : NSObject

//+ (void)requestAuthCodeWithCompletion:(void (^)(BOOL isSuccess,NSString *authCode))completion;
+ (UIImage *)getPringImage:(NSDictionary *)dic;
+ (NSDictionary *)getAppdic;
+ (NSDictionary *)getDeviceDic;
+ (NSDictionary *)getUserDic;
//+ (NSDictionary *)getNetWorkStatusDic;
//+ (void)registerAgent:(NSString *)agentStr;
//
/// 清理所有类型wkwebview缓存 目前网页没有版本管理,没有更优解的策略。杀死应用则清理所有wk缓存
/// @param completionHandler 结束
+ (void)clearAllWKCache:(void(^)(void))completionHandler;
//+ (void)login;
+ (NSString *)getRenderPrintJS:(NSDictionary * _Nullable)dic;
+ (NSString *)setParamsJS:(NSDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
