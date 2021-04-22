//
//  JSResponseModel.h
//  Paperang
//
//  Created by Juicer on 2019/12/20.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JSResponseModel : NSObject

@property (nonatomic, copy) id data;
@property (nonatomic, copy) NSString *callbackId;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, copy) NSString *status;
@property (nonatomic, copy) NSString *method;


/// 客户端回复前端"callback"事件
- (NSString *)jsScript;
- (NSString *)jsShareScript:(BOOL)success;

/// 客户端调用前端的on方法事件脚本 需要外部配置data和method
- (NSString *)jsEventScriptWithMethod:(NSString *)method;

@end

NS_ASSUME_NONNULL_END
