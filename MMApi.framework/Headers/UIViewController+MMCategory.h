//
//  UIViewController+MMCategory.h
//  MMApi
//
//  Created by mb on 2020/8/7.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (MMCategory)

+ (UIViewController *)topViewController;

+ (UIViewController * __nullable)topVC;

+ (UINavigationController *)topNaviViewController;
@end

NS_ASSUME_NONNULL_END
