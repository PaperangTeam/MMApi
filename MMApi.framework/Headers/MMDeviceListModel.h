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

typedef enum : NSUInteger {
    MMDeviceListNotConnect,
    MMDeviceListConnecting,
    MMDeviceListConnected,
    MMDeviceListConnectFail,
} MMDeviceListConnectStatus;

typedef void(^MMDeviceListModelBlock)(CBPeripheral * _Nonnull peripheral);

NS_ASSUME_NONNULL_BEGIN

@interface MMDeviceListModel : NSObject

@property (nonatomic, strong) CBPeripheral *peripheral;

@property (nonatomic, copy) NSString *deviceName;

@property (nonatomic, copy) NSString *deviceMac;

@property (nonatomic, assign) MMDeviceListConnectStatus connectStatus;

@property (nonatomic, copy) MMDeviceListModelBlock clickBlock;

@end

NS_ASSUME_NONNULL_END
