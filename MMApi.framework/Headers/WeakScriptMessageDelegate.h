//
//  WeakScriptMessageDelegate.h
//  Paperang
//
//  Created by colayet on 2020/3/2.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WeakScriptMessageDelegate : NSObject<WKScriptMessageHandler>

@property (nonatomic, weak) id<WKScriptMessageHandler> scriptDelegate;

- (instancetype)initWithDelegate:(id<WKScriptMessageHandler>)scriptDelegate;

@end


NS_ASSUME_NONNULL_END
