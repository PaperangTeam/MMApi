//
//  MMDeviceListModel.h
//  MMApi
//
//  Created by mb on 2020/8/6.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
@class MMDevice;

typedef enum : NSUInteger {
    MMDeviceListNotConnect,
    MMDeviceListConnecting,
    MMDeviceListConnected,
    MMDeviceListConnectFail,
} MMDeviceListConnectStatus;

typedef void(^MMDeviceListModelBlock)(MMDevice * _Nonnull device);

NS_ASSUME_NONNULL_BEGIN

@interface MMDeviceListModel : NSObject

@property (nonatomic, strong) MMDevice *device;

@property (nonatomic, copy) NSString *deviceName;

@property (nonatomic, copy) NSString *deviceMac;

@property (nonatomic, assign) MMDeviceListConnectStatus connectStatus;

@property (nonatomic, copy) MMDeviceListModelBlock clickBlock;

@end

NS_ASSUME_NONNULL_END
