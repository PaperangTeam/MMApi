//
//  UIView+MMAdd.h
//  YYCategories <https://github.com/ibireme/YYCategories>
//
//  Created by ibireme on 13/4/3.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Provides extensions for `UIView`.
 */
@interface UIView (MMAdd)

@property (nonatomic) CGFloat mb_left;        ///< Shortcut for frame.origin.x.
@property (nonatomic) CGFloat mb_top;         ///< Shortcut for frame.origin.y
@property (nonatomic) CGFloat mb_right;       ///< Shortcut for frame.origin.x + frame.size.width
@property (nonatomic) CGFloat mb_bottom;      ///< Shortcut for frame.origin.y + frame.size.height
@property (nonatomic) CGFloat mb_width;       ///< Shortcut for frame.size.width.
@property (nonatomic) CGFloat mb_height;      ///< Shortcut for frame.size.height.
@property (nonatomic) CGFloat mb_centerX;     ///< Shortcut for center.x
@property (nonatomic) CGFloat mb_centerY;     ///< Shortcut for center.y
@property (nonatomic) CGPoint mb_origin;      ///< Shortcut for frame.origin.
@property (nonatomic) CGSize  mb_size;        ///< Shortcut for frame.size.

@end

NS_ASSUME_NONNULL_END
