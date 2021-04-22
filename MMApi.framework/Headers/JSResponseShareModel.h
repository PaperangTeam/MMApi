//
//  JSResponseShareModel.h
//  Paperang
//
//  Created by Diff on 2020/4/14.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface JSResponseShareModel : NSObject

@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subTitle;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *image;  ///< 图片网络地址
@property (nonatomic, copy) NSArray<NSString *> *platform;

/// 已经下载好了要分享的图片
@property (nonatomic, strong) UIImage *downloadImage;

- (BOOL)isShareImage;

@end

NS_ASSUME_NONNULL_END
