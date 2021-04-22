//
//  MMCommonAlertGeneralView.h
//  Paperang
//
//  Created by mb on 2020/6/5.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import "MMCommonAlertXibView.h"

NS_ASSUME_NONNULL_BEGIN

@interface MMCommonAlertGeneralView : MMCommonAlertXibView

+ (instancetype)mm_alertViewWithType:(MMCommonAlertType)type;
+ (instancetype)mm_alertWithRequestModel:(MMCommonBaseAlertModel *)requestModel;
+ (instancetype)mm_alertWithRequestModel:(MMCommonBaseAlertModel *)requestModel responseModel:(MMCommonBaseAlertModel * _Nullable)responseModel;
@end

NS_ASSUME_NONNULL_END
