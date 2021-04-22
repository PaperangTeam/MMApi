//
//  ZWYTableViewCell.h
//  example
//
//  Created by Yesoul on 2018/12/28.
//  Copyright © 2018 hulailin. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZWYTableViewCell : UITableViewCell

/**
 *  cell 根据数据显示 UI
 *
 *  @param  aData 数据
 */
- (void)zwy_updateWithCellData:(id __nullable)aData;
@end

NS_ASSUME_NONNULL_END
