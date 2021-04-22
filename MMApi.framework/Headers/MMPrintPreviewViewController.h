//
//  MMPrintPreviewViewController.h
//  MMApi
//
//  Created by mb on 2020/8/8.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import "MMBaseWKWebViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface MMPrintPreviewViewController : MMBaseWKWebViewController

- (instancetype)initWithFlag:(NSString *)flag renderBlock:(void (^)(NSString *flag))renderBlock;

- (void)reloadPrintData:(NSString *)printData;
@end

NS_ASSUME_NONNULL_END
