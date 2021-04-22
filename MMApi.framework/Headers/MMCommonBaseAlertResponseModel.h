//
//  MMCommonBaseAlertResponseModel.h
//  Paperang
//
//  Created by mb on 2020/6/5.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import "MMCommonBaseAlertModel.h"
@class MMCommonAlertViewController;

NS_ASSUME_NONNULL_BEGIN

@interface MMCommonBaseAlertResponseModel : MMCommonBaseAlertModel

@property (nonatomic, weak) MMCommonAlertViewController *alertViewController;
@property (nonatomic, copy) NSString *cancelFlag;
@end

NS_ASSUME_NONNULL_END
