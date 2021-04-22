//
//  MMDeviceProgressLogic.h
//  MMApi
//
//  Created by mb on 2020/8/20.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MMDeviceProgressLogic : NSObject

@property (nonatomic, assign) NSInteger progressCount;

- (void)showAlert;
- (void)dismissAlert;
@end

NS_ASSUME_NONNULL_END
