//
//  JSRequestModel.h
//  Paperang
//
//  Created by Juicer on 2019/12/20.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface JSRequestModel : NSObject
//{//方法调用
//  "invoke": "methodName", // 调用的Java/oc方法名
//  "data": { // 调用方法的参数
//    "name": "value"
//    // ...
//  },
//  "callbackId":""// 回调唯一id
//}
@property (nonatomic, copy) id data;
@property (nonatomic, copy) NSString *invoke;
@property (nonatomic, copy) NSString *callbackId;

- (void)parse:(WKScriptMessage *)wkScriptMessage;

// id data转dic
- (NSDictionary *)getResolveDic;

@end

NS_ASSUME_NONNULL_END
