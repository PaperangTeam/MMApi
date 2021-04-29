//
//  MMSharePrint.h
//  MMApi
//
//  Created by hoho on 2017/10/25.
//  Copyright © 2017年 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class CBPeripheral;

typedef NS_ENUM(NSInteger, PrintType) {
    PrintTypeForImage,      //simulate grayscale printing mode
    PrintTypeForText        //Black and white printing mode
};

typedef NS_ENUM(NSInteger, DensityType) {
    DensityTypeLight = 0,
    DensityTypeNormal,
    DensityTypeStrong,
};


/**
 Discover Paperang device notification with the device object
 {
    @"peripheral":peripheral,
    @"MAC":MAC,
    @"RSSI":RSSI
 }
 */
UIKIT_EXTERN NSNotificationName const MMDidDiscoverPeripheralNotification;
/**
 Will connect to Paperang device notification
  {
     @"peripheral":peripheral
  }
 */
UIKIT_EXTERN NSNotificationName const MMWillConnectPeripheralNotification;
/**
 Connected to Paperang device notification
  {
     @"peripheral":peripheral,
     @"isUserConnect":@(YES)         Judge it is user’s active connection (YES) or auto connection (NO)
  }
 */
UIKIT_EXTERN NSNotificationName const MMDidConnectPeripheralNotification;
/**
 Connect to Paperang device failed notification
  {
     @"code":@(313),
     @"snCode":snCode,
     @"error":@"Haven’t enabled the device with Internet"
  }
  code:
     -1  Cannot recognize the device
     -2  Disallow connection to the device
     -3  Connection timeout
     313 Enable the device with Internet
 */
UIKIT_EXTERN NSNotificationName const MMDidFailToConnectPeripheralNotification;
/**
 Disconnected to Paperang device notification
  {
     @"peripheral":peripheral,
     @"isUserDisconnect":@(YES)       Judge it is user’s active disconnect (YES) or abnormal disconnection
     @"error":errorStr               none error is null character string
 */
UIKIT_EXTERN NSNotificationName const MMDidDisconnectPeripheralNotification;

/**
 Will transmit data notification
 */
UIKIT_EXTERN NSNotificationName const MMWillSendDataNotification;

/**
 Data transmission progress notification
 */
UIKIT_EXTERN NSNotificationName const MMSendDataProgressNotification;

/**
 Data transmission completed notification
 */
UIKIT_EXTERN NSNotificationName const MMDidSendDataNotification;

/**
 Print completed notification
 */
UIKIT_EXTERN NSNotificationName const MMDidFinishPrintNotification;


/**
 Device abnormal data:
 {
    @"code":exceptionCode
    @"errorStr"errorDescription
 }
 code:
    -1 Low battery
    -2 Lack of paper
    -3 Overheated
    -4 Cover opened
 */
UIKIT_EXTERN NSNotificationName const MMDeviceExceptionStatusNotification;

/**
 * get device support size
 */
UIKIT_EXTERN NSNotificationName const MMGetDeviceSupportSizeNotificationName;

/**
 * set device support size success, need reload view
 */
UIKIT_EXTERN NSNotificationName const MMConnectedDevicePrintPreviewType;

@interface MMSharePrint : NSObject

/**
 Obtain current SDK version

 @return SDK version
 */
+ (NSString *)getSdkVersion;

/**
 Register MMAPI SDK

 @param appId Developer application Id
 @param appKey Developer AppKey
 @param secret Developer secret
 */
+ (void)registWithAppID:(long)appId
                 AppKey:(NSString *)appKey
              andSecret:(NSString *)secret;

/**
 Register MMAPI SDK
 
 @param appId Developer application Id
 @param appKey Developer AppKey
 @param secret Developer secret
 @param success verification success call-back
 @param fail fail call-back
 */

+ (void)registWithAppID:(long)appId
                 AppKey:(NSString *)appKey
              andSecret:(NSString *)secret
                success:(void (^)(void))success
                   fail:(void (^) (NSError *error))fail;

/**
 Obtain developer verification status

 @return developer account verification status
 */
+ (BOOL)getAuthorizationStatus;

/**
 Set connection limit. Provided by Paperang, null character string can connect to all the device from Paperang

 @param makerUser Paperang provides limit character string
 */
+ (void)configMakerUser:(NSString *)makerUser;

/**
set to show log or not

 @param showLog log open-close
 */
+ (void)debugLog:(BOOL)showLog;

/**
 set scan time

 @param t 扫描时间，单位为秒
 */
+ (void)setScanTime:(NSTimeInterval)t;
/**
 set to auto reconnect device
 
 @param autoReconnect  auto reconnect open-close
 */
+ (void)autoReconnect:(BOOL)autoReconnect;

/**
 Get device connection status

 @return YES connected   NO disconnected
 */
+ (BOOL)getDeviceConnectStatus;

/**
Start to search Bluetooth
 */
+ (void)startScan;

/**
Stop to searching Bluetooth
 */
+ (void)stopScan;

/**
 Get last device’s UUID

 @return last device’s UUID
 */
+ (NSString *)getLastPeripheralUUID;
/**
 Connect device

 @param peripheral  device object
 */
+ (void)connectPeripheral:(CBPeripheral *)peripheral;

/**
 Disconnect
 */
+ (void)disconnect;

/**
 Share photo data

 @param data photo data
 */
+ (void)mmSharePrintData:(NSData *)data;

/**
 Share photo object

 @param image photo object
 */
+ (void)mmSharePrintImage:(UIImage *)image;

/**
 Print photo object

 @param image photo object
 @param type print type, see detail in PrintType
 @param complete start to send data call-back
 @param fail send data fail call-back
 */
+ (void)printImage:(UIImage *)image
         printType:(PrintType)type
  completeSendData:(void (^)(void))complete
              fail:(void (^)(NSError *error))fail;

/**
 print photo object with copies
 
 @param image print photo
 @param type print type, see detail in PrintType
 @param count print copies
 @param complete start to send data call-back
 @param fail send data fail call-back
 */
+ (void)printImage:(UIImage *)image
         printType:(PrintType)type
             count:(NSInteger)count
  completeSendData:(void (^)(void))complete
              fail:(void (^)(NSError *))fail;


/**
 print scale image
 */

+ (void)printScaleImage:(UIImage *)image;
+ (NSData *)getScaleDataWithImage:(UIImage *)image;
/**
 Set print density
 
 @param density density
 
 */
+ (void)setDensity:(DensityType)density;

+ (BOOL)checkPrintEnable;


+ (BOOL)checkBLEEnable;

/**
 * 请求喵宝营销页 url
 */
+ (void)requestMarketURL;

/**
 * 打印自检页
 */
+ (void)printTestPaper;
@end
