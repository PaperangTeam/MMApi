//
//  MMBluetoothManager+MMCategory.h
//  MMApi
//
//  Created by mb on 2020/8/7.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <MMBLEManager/MMBLENormalManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface MMBLENormalManager (MMCategory)

+ (BOOL)checkPrintEnable;
+ (BOOL)checkBLEEnable;
+ (BOOL)isBluetoothOn;
+ (BOOL)isBluetoothAuth;
@end

NS_ASSUME_NONNULL_END
