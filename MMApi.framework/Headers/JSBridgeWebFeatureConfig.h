//
//  JSBridgeWebFeatureConfig.h
//  Paperang
//
//  Created by Juicer on 2020/2/18.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JSBridgeWebFeatureConfig : NSObject

+ (JSBridgeWebFeatureConfig *)parse:(NSString *)url;

/**
 是否隐藏状态栏  0显示 1不显示
 */
@property (nonatomic, assign) BOOL hideStatusBar;

/**
 是否隐藏导航栏  0显示 1不显示
 */
@property (nonatomic, assign) BOOL hideNavBar;

/**
 是否显示加载进度条
 */
@property (nonatomic, assign) BOOL showProgressBar;

/**
 由js控制音频(自动播放语音)
*/
@property (nonatomic, assign) BOOL isJsPlayAudio;

/**
 由js控制播放器
*/
@property (nonatomic, assign) BOOL isJsPlayMedia;


@end

NS_ASSUME_NONNULL_END
