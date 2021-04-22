//
//  ZWYTableViewSectionViewModel.h
//  example
//
//  Created by Yesoul on 2018/12/28.
//  Copyright © 2018 hulailin. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef NSString *(^ZWYConfigCellIdentifier)(UITableView *tableView, NSIndexPath *indexPath);
typedef CGFloat (^ZWYConfigRowHeight)(NSIndexPath *indexPath);

@interface ZWYTableViewCellModel: NSObject
    
/** 当前cell的Class,要保证当前aClass名称与当前identifier标识符一致 */
@property (nonatomic ,copy) NSString* zwy_className;
/** cell的高度 用block是为了能动态计算cell的高度*/
@property (nonatomic, copy ) ZWYConfigRowHeight zwy_configRowHeight;
/** 是否通过nib加载cell，默认为NO isNib */
@property (nonatomic) BOOL zwy_isNib;
/** cell填充数据 */
@property (nonatomic, strong) id zwy_rowData;

// optional 参数
@property (nonatomic, assign) UITableViewCellStyle    zwy_tableViewCellStyle;
@property (nonatomic) UITableViewCellAccessoryType    zwy_accessoryType;              // default is UITableViewCellAccessoryNone. use to set standard type
@property (nonatomic) UITableViewCellSelectionStyle   zwy_selectionStyle;             // default is UITableViewCellSelectionStyleDefault.
@property (nonatomic) BOOL                            zwy_hasInset;
@property (nonatomic) UIEdgeInsets                    zwy_separatorInset;       // 自定义分割线位置 zwy_hasInset 为 yes 使用, 默认 分割线从0位置开始  UIEdgeInsetsZero
/**
 创建 model
 @param rowData cell 对应的数据源
 @param isNib 是否Nib YES 是 NO 不是
 @param rowHeight cell 的高度
 @return cellModel
 */
+ (instancetype)zwy_cellViewModelClassName:(NSString *)className
                                   rowData:(id)rowData
                                     isNib:(BOOL)isNib
                                 rowHeight:(ZWYConfigRowHeight)rowHeight;
@end


#pragma mark - mark ZWYTableViewSectionViewModel

typedef CGFloat(^ZWYConfigSectionHeaderHeight)(NSInteger section);
typedef UIView *(^ZWYConfigSectionHeaderView)(NSInteger section);
typedef CGFloat(^ZWYConfigSectionFooterHeight)(NSInteger section);
typedef UIView *(^ZWYConfigSectionFooterView)(NSInteger section);

@interface ZWYTableViewSectionViewModel : NSObject
#pragma mark - 分区视图2个属性必须配置，否则不显示
/** 分区头视图高度 configSectionHeaderHeight*/
@property (nonatomic, copy) ZWYConfigSectionHeaderHeight zwy_configSectionHeaderHeight;
/** 分区头视图 configSectionHeaderView*/
@property (nonatomic, strong) ZWYConfigSectionHeaderView zwy_configSectionHeaderView;
    
#pragma mark - 分区视图2个属性必须配置，否则不显示
/** 分区尾视图高度 configSectionFooterHeight*/
@property (nonatomic, copy) ZWYConfigSectionFooterHeight zwy_configSectionFooterHeight;
/** 分区尾视图 configFooterView*/
@property (nonatomic, strong) ZWYConfigSectionFooterView zwy_configFooterView;

/** 分区尾部视图数据 sectionFooterData*/
@property (nonatomic, strong) id zwy_sectionFooterData;
/** 分区头部头部视图数据 sectionHeaderData*/
@property (nonatomic, strong) id zwy_sectionHeaderData;

/** 分区内的数据模型 rowDataArray*/
@property (nonatomic, strong) NSMutableArray <ZWYTableViewCellModel *>* zwy_rowDataArray;


/**
 设置分区头部视图
 
 @param configSectionHeaderHeight 高度
 @param configSectionHeaderView 视图View
 */
- (void)zwy_configSectionHeaderHeight:(ZWYConfigSectionHeaderHeight)configSectionHeaderHeight
                    sectionHeaderView:(ZWYConfigSectionHeaderView)configSectionHeaderView;
    
    
/**
 设置分区尾视图
 
 @param configSectionFooterHeight 尾部视图高度
 @param configSectionFooterView 尾部视图View
 */
- (void)zwy_configSectionFooterHeight:(ZWYConfigSectionFooterHeight)configSectionFooterHeight
                    sectionFooterView:(ZWYConfigSectionFooterView)configSectionFooterView;
@end

@interface ZWYTableUIModel : NSObject

@property (nonatomic, copy) void(^zwy_scrollOffset)(CGPoint point);
@property (nonatomic, copy) void(^zwy_scrollViewDidScroll)(UIScrollView *scrollView);
@property (nonatomic, copy) void(^zwy_willDisplayCell)(UITableView *tableView, UITableViewCell *cell, NSIndexPath *indexPath);
@property (nonatomic, copy) void(^zwy_shouldHighlightRow)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) void(^zwy_didSelectRowAtIndexPath)(UITableView *tableView, NSIndexPath *indexPath, id rowData);
@end

NS_ASSUME_NONNULL_END
