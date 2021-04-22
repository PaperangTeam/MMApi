//
//  NSObject+ZWYTableDataModel.h
//  example
//
//  Created by Yesoul on 2018/12/28.
//  Copyright © 2018 hulailin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (ZWYTableDataModel)


/**
 请求的数据源
 
 @param dataArray list
 @param height cell的高度
 @param isNib 是否是Nib
 */
+ (NSMutableArray *)zwy_requestTableDataSource:(NSMutableArray *)dataArray
                                     rowHeight:(CGFloat)height
                                     className:(NSString *)className
                                         isNib:(BOOL)isNib;
/**
 请求的数据源 (头)
 
 @param dataArray list
 @param height cell的高度
 @param isNib 是否是Nib
 @param headerHeight 头部视图高度
 @param headerView 头部视图View
 
 */
+ (NSMutableArray *)zwy_requestTableDataSource:(NSMutableArray *)dataArray
                                     rowHeight:(CGFloat)height
                                     className:(NSString *)className
                                         isNib:(BOOL)isNib
                           sectionHeaderHeight:(CGFloat)headerHeight
                             sectionHeaderView:(UIView * __nullable)headerView;
/**
 请求的数据源 (头尾)
 
 @param dataArray list
 @param height cell的高度
 @param isNib 是否是Nib
 @param headerHeight 头部视图高度
 @param headerView 头部视图View
 @param footerHeight 尾部视图高度
 @param footerView 尾部视图View
 
 */
+ (NSMutableArray *)zwy_requestTableDataSource:(NSMutableArray *)dataArray
                                     rowHeight:(CGFloat)height
                                     className:(NSString *)className
                                         isNib:(BOOL)isNib
                           sectionHeaderHeight:(CGFloat)headerHeight
                             sectionHeaderView:(UIView * __nullable)headerView
                           sectionFooterHeight:(CGFloat)footerHeight
                             sectionFooterView:(UIView * __nullable)footerView;
/**
 数据请求 子类重写
 */
- (NSMutableArray *)zwy_requestTableDataSource:(id)dataArray;
@end

NS_ASSUME_NONNULL_END
