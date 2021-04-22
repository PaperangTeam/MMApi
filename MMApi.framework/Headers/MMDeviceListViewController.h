//
//  MMDeviceListViewController.h
//  MMApi
//
//  Created by mb on 2020/8/5.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import "MMCustomNaviBaseViewController.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^FromMarketingConnectedBlock)(void);

@interface MMDeviceListViewController : MMCustomNaviBaseViewController

@property (nonatomic, assign) BOOL isFromMarketing;
/// 能否返回上一页, 目的是逻辑中从营销页进入设备页, 连接完成设备需要 pop 到内容页面
@property (nonatomic, assign) BOOL canPop;
@property (nonatomic, copy) FromMarketingConnectedBlock connectedFromMarketing;
@end

NS_ASSUME_NONNULL_END
