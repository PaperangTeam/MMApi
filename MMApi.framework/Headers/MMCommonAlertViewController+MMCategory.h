//
//  MMAlertViewController+MMCategory.h
//  Paperang
//
//  Created by Diff on 2020/6/22.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import "MMCommonAlertViewController.h"

@interface MMCommonAlertViewController (MMCategory)

/// 未注册MMAPI SDK
+ (BOOL)mm_showAlertSDKPermit:(UIViewController *)presentVC;
/// 允许作业帮APP打开蓝牙吗？
+ (BOOL)mm_showAlertBluePermit:(UIViewController *)presentVC
             confirmCompletion:(MMCommonAlertVoidBlock)confirmCompletion;

/// 设备查找失败
+ (BOOL)mm_showAlertDeviceSearchFail:(UIViewController *)presentVC
                   confirmCompletion:(MMCommonAlertVoidBlock)confirmCompletion;

/// 蓝牙连接失败
+ (BOOL)mm_showAlertBLEConnectFail:(UIViewController *)presentVC
                 confirmCompletion:(MMCommonAlertVoidBlock)confirmCompletion;

/// 蓝牙连接失败 没有权限
+ (BOOL)mm_showAlertBLEConnectFailNoPermit:(UIViewController *)presentVC
                         confirmCompletion:(MMCommonAlertVoidBlock)confirmCompletion;

/// 蓝牙连接失败, 网络断开
+ (BOOL)mm_showAlertBLEConnectFailNoNetwork:(UIViewController *)presentVC
                          confirmCompletion:(MMCommonAlertVoidBlock)confirmCompletion;

/// 打印机开盖啦～
+ (BOOL)mm_showAlertOpenCap:(UIViewController *)presentVC;

/// 打印机没纸啦～
+ (BOOL)mm_showAlertNoPaper:(UIViewController *)presentVC;

/// 打印机电量过低
+ (BOOL)mm_showAlertNoPower:(UIViewController *)presentVC;

/// 打印机过热
+ (BOOL)mm_showAlertOverheating:(UIViewController *)presentVC;

/// 设备未连接
+ (BOOL)mm_showAlertDeviceNoConnect:(UIViewController *)presentVC
                   cancelCompletion:(MMCommonAlertVoidBlock)cancelCompletion
                  confirmCompletion:(MMCommonAlertVoidBlock)confirmCompletion;

/// 设备更新完成
+ (void)mm_showAlertUpdateDone:(UIViewController *)presentVC;

/// 发现新固件
+ (void)mm_showAlertShowNewFirmware:(UIViewController *)presentVC
                            content:(NSString *)content
                  confirmCompletion:(MMCommonAlertVoidBlock)confirmCompletion;

/// 蓝牙连接已断开
+ (void)mm_showAlertBLEDisconnect:(UIViewController *)presentVC
                confirmCompletion:(MMCommonAlertVoidBlock)confirmCompletion;
@end
