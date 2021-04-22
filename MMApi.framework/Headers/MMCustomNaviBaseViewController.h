//
//  MMCustomNaviBaseViewController.h
//  Paperang
//
//  Created by mb on 2020/6/4.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MMNavigationBar.h"

@class MMCustomNaviBaseViewController;

@protocol MMCustomNaviBaseViewControllerDataSource <NSObject>

@optional
- (BOOL)mm_navBaseViewControllerIsNeedNavBar:(MMCustomNaviBaseViewController *)navBaseViewController;

- (UIStatusBarStyle)mm_navBaseViewControllerPreferStatusBarStyle:(MMCustomNaviBaseViewController *)navBaseViewController;

@end    

@interface MMCustomNaviBaseViewController : UIViewController
<
    MMNavigationBarDelegate,
    MMNavigationBarDataSource,
    MMCustomNaviBaseViewControllerDataSource
>

/// push 或者 present 之前的页面是否隐藏了系统的 navigationbar, 默认 NO
@property (nonatomic, assign) BOOL isOrignalNaviBarHidden;

/** naviBar  */
@property (nonatomic, weak) MMNavigationBar *mm_navgationBar;

/*默认的导航栏字体*/
- (NSMutableAttributedString *(^)(NSString *))mm_changeTitle;

- (void)mm_setConfig;
@end
