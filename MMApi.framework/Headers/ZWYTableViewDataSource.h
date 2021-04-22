//
//  ZWYTableViewDataSource.h
//  example
//
//  Created by Yesoul on 2018/12/28.
//  Copyright © 2018 hulailin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSObject+ZWYTableDataModel.h"
#import "ZWYTableViewSectionViewModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Hook cellModel的数据
 */
typedef void (^ZWYHookCellModelBlock)(ZWYTableViewCellModel *model, NSIndexPath *indexPath);
/**
 * 配置cell的数据
 */
typedef void (^ZWYConfigCellBlock)(UITableViewCell *cell, id rowData);
/**
 * cell 点击的响应事件
 */
typedef void (^ZWYDidSelectRowAtIndexPath)(UITableView *tableView, NSIndexPath *indexPath, id rowData);
/**
 * 配置头部数据源
 */
typedef void (^ZWYConfigSectionHeaderData)(NSInteger section, UIView *view, id sectionHeaderData);
/**
 * 配置尾部数据源
 */
typedef void (^ZWYConfigSectionFooterData)(NSInteger section, UIView *view, id sectionHeaderData);

@interface ZWYTableViewDataSource : NSObject
<
    UITableViewDataSource,
    UITableViewDelegate
>

/** 头部数据源 */
@property (nonatomic, copy) ZWYConfigSectionHeaderData zwy_configSectionHeaderData;

/** 尾部数据源 */
@property (nonatomic, copy) ZWYConfigSectionFooterData zwy_configSectionFooterData;

@property (nonatomic, copy) ZWYHookCellModelBlock zwy_hookCellModel;

@property (nonatomic, strong) ZWYTableUIModel *zwy_tableUIModel;
    
    
/**
 *  根据外界传入的数据以及标识返回一个数据源
 *
 *  @param dataViewModel    外界传入的数据
 *  @param block            回调block用于配置cell数据 如果不实现且继承了HBTableViewCell 系统自动调用实现
 *
 *  @return 数据源对象
 */
+ (instancetype)zwy_dataSourceViewModel:(id)dataViewModel
                        dataConfigBlock:(ZWYConfigCellBlock)block;
    
    
/**
 *  根据外界传入的数据以及标识返回一个数据源
 *
 *  @param dataViewModel            外界传入的数据
 *  @param block                    回调block用于配置cell数据 如果不实现且继承了HBTableViewCell 系统自动调用实现
 *  @param didSelectRowAtIndexPath  响应事件
 *
 *  @return 数据源对象
 */
+ (instancetype)zwy_dataSourceViewModel:(id)dataViewModel
                        dataConfigBlock:(ZWYConfigCellBlock)block
                didSelectRowAtIndexPath:(nullable ZWYDidSelectRowAtIndexPath)didSelectRowAtIndexPath;

/**
 * 更新数组并刷新视图
 */
- (void)zwy_updateModelViewArray:(NSMutableArray *)modelViewArray
                       tableView:(__kindof UITableView * __nullable)tableView;
    
@end

NS_ASSUME_NONNULL_END


/*
 
 * cell 继承 ZWYTableViewCell
 * 实现 zwy_updateWithCellData 模型赋值
 - (void)zwy_updateWithCellData:(id)aData {
    HBTestModel *model = (HBTestModel *)aData;
    self.textLabel.text = model.titleName;
    self.detailTextLabel.text = model.detail;
 }
 
 * viewController
 * 三个必备属性 tableview 数据源 元数据模型
 @property (nonatomic, strong) UITableView *table;
 @property (nonatomic, strong) ZWYTableViewDataSource *dataSource;
 @property (nonatomic, strong) NSMutableArray *dataArr;
 
 * 要求拥有 dataArr 转换数据源, 然后绑定 DataSource Delegate 给 tableview 必须这个顺序
 * 1) 拥有 dataArr
 * 2) 转换数据源
 * 1) 绑定 DataSource Delegate 给 tableview
 [self dataArrayFormart];
 
 - (void)dataArrayFormart{
     NSMutableArray *array = [HBTestModel zwy_requestTableDataSource:self.dataArr rowHeight:100 className:NSStringFromClass(ZWYNoramlTableViewCell.class) isNib:NO];
 
     self.dataSource = [ZWYTableViewDataSource zwy_dataSourceViewModel:array dataConfigBlock:^(id  _Nonnull cell, id  _Nonnull model) {
 
     } didSelectRowAtIndexPath:^(UITableView * _Nonnull tableView, NSIndexPath * _Nonnull indexPath, id  _Nonnull rowData) {
        NSLog(@"%@", indexPath);
     }];
     self.dataSource.zwy_hookCellModel = ^(ZWYTableViewCellModel * _Nonnull model, NSIndexPath * _Nonnull indexPath) {
         if (indexPath.row % 2 == 0) {
             model.zwy_tableViewCellStyle = UITableViewCellStyleSubtitle;
             model.zwy_selectionStyle = UITableViewCellSelectionStyleBlue;
             model.zwy_hasInset = YES;
             model.zwy_separatorInset = UIEdgeInsetsMake(0, 100, 0, 100);
         } else {
             model.zwy_tableViewCellStyle = UITableViewCellStyleSubtitle;
             model.zwy_accessoryType = UITableViewCellAccessoryDisclosureIndicator;
             model.zwy_selectionStyle = UITableViewCellSelectionStyleGray;
             model.zwy_hasInset = YES;
         }
     };
 }
 
 - (UITableView *)table {
     if (!_table) {
         _table = [[UITableView alloc] initWithFrame:CGRectMake(0,  0, self.view.frame.size.width, self.view.frame.size.height)];
         _table.dataSource = self.dataSource;
         _table.delegate = self.dataSource;
     }
     return _table;
 }

 
 
 */


