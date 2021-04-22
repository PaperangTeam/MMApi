//
//  MMCrashLog.h
//  MMApi
//
//  Created by mb on 2020/9/27.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MMCrashLog : NSObject

+ (instancetype)sharedInstance;

- (void)registerHandler;
- (void)unregisterHandler;

@end

NS_ASSUME_NONNULL_END
