//
//  MMNaviRightBtn.h
//  MMApi
//
//  Created by mb on 2020/8/10.
//  Copyright © 2020 Hoho. All rights reserved.
//

#import <UIKit/UIKit.h>
@class MMRightBtnModel;

NS_ASSUME_NONNULL_BEGIN

@interface MMNaviRightBtn : UIButton

- (void)mm_setNaviRightBtnWithModel:(MMRightBtnModel *)model;

@end

@interface MMRightBtnModel : NSObject

@property (nonatomic, strong) UIFont *mm_btnFont;

@property (nonatomic, strong) UIImage *mm_normalImage;
@property (nonatomic, copy) NSString *mm_normalTitle;
@property (nonatomic, strong) UIColor *mm_normalColor;

@property (nonatomic, strong) UIImage *mm_selectedImage;
@property (nonatomic, copy) NSString *mm_selectedTitle;
@property (nonatomic, strong) UIColor *mm_selectedColor;

@property (nonatomic, strong) UIImage *mm_highlightedImage;
@property (nonatomic, copy) NSString *mm_highlightedTitle;
@property (nonatomic, strong) UIColor *mm_highlightedColor;

@property (nonatomic, strong) UIImage *mm_disabledImage;
@property (nonatomic, copy) NSString *mm_disabledTitle;
@property (nonatomic, strong) UIColor *mm_disabledColor;

@end

NS_ASSUME_NONNULL_END
