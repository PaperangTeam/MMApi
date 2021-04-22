//
//  MMAlertXibView.h
//  Paperang
//
//  Created by mb on 2020/6/5.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MMCommonBaseAlertModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface MMCommonAlertXibView : UIView

@property (nonatomic, strong) MMCommonBaseAlertModel *mm_requestModel;
@property (nonatomic, strong) MMCommonBaseAlertModel *mm_responseModel;

/**
 * 根据类名创建 xib 视图
 */
+ (instancetype)mm_alertDefaultXibView;

+ (instancetype)mm_alertXibViewWithName:(NSString *)xibName;
@end

NS_ASSUME_NONNULL_END
