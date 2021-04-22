//
//  MMAlertViewController.h
//  Paperang
//
//  Created by mb on 2020/6/5.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MMCommonCheckRecordBoxRequestModel.h"
#import "MMCommonCheckRecordBoxResponseModel.h"
#import "MMCommonProgressAlertRequestModel.h"
#import "MMCommonProgressAlertResponseModel.h"

@interface MMCommonAlertViewController : UIViewController

@property (nonatomic, strong) MMCommonBaseAlertRequestModel *requestModel;
@property (nonatomic, copy) MMCommonAlertVoidBlock dismissBlock;

/**
 * 默认两个按钮形式的 alert
 */
+ (instancetype)mm_alertDefaultWithTitle:(NSString *)title
                                 content:(NSString *)content
                                  cancel:(MMCommonAlertResponseBlock)cancel
                                 confirm:(MMCommonAlertResponseBlock)confirm;
/**
 * 默认单独一个按钮的 alert
 */
+ (instancetype)mm_alertSingleButtonWithTitle:(NSString *)title
                                      content:(NSString *)content
                                      confirm:(MMCommonAlertResponseBlock)confirm;
/**
 * 默认两个按钮圆形图片形式的 alert
 */
+ (instancetype)mm_alertCircleImageWithImageName:(NSString *)imageName
                                           title:(NSString *)title
                                         content:(NSString *)content
                                          cancel:(MMCommonAlertResponseBlock)cancel
                                         confirm:(MMCommonAlertResponseBlock)confirm;
/**
 * 默认两个按钮圆形图片形式的 alert
 */
+ (instancetype)mm_alertRectangleImageWithImageName:(NSString *)imageName
                                              title:(NSString *)title
                                            content:(NSString *)content
                                             cancel:(MMCommonAlertResponseBlock)cancel
                                            confirm:(MMCommonAlertResponseBlock)confirm;

/**
 * 默认有一个 box 用来打钩, 不再提醒那种
 */
+ (instancetype)mm_alertCheckRecordBoxWithTitle:(NSString *)title
                                        content:(NSString *)content
                                         cancel:(MMCommonAlertResponseBlock)cancel
                                        confirm:(MMCommonAlertResponseBlock)confirm;

/**
 * 默认升级进度条的 alert
 */
+ (instancetype)mm_alertUpgradeProgressWithCompletion:(MMCommonAlertResponseBlock)completion;

- (void)mm_show;
- (void)mm_show:(MMCommonAlertVoidBlock)completion;
- (void)mm_showInViewController:(UIViewController *)viewController;
- (void)mm_showInViewController:(UIViewController *)viewController completion:(MMCommonAlertVoidBlock)completion;
@end


@interface MMCommonAlertQueue : NSObject

+ (instancetype)queue;

- (void)addAlert:(MMCommonAlertViewController *)alert
       presentVC:(UIViewController *)viewController
      completion:(MMCommonAlertVoidBlock)completion;

@end
