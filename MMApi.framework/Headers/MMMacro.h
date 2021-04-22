//
//  MMMacro.h
//  MMApi
//
//  Created by hoho on 2017/12/13.
//  Copyright © 2017年 Hoho. All rights reserved.
//

#ifndef MMMacro_h
#define MMMacro_h

#define kPrintURLKey @"print-view-zyb"
#define kMarketURLKey @"market-page-zyb"

#import "NSBundle+MMCategory.h"

#define XLog(format, ...) if (_showLog) NSLog((@"[函数名:%s]" "[行号:%d]" format), __FUNCTION__, __LINE__, ##__VA_ARGS__);

#define WEAKSELF __weak typeof(self) weakself = self;

#define kLocalizedStringEqual(key) key

#endif /* MMMacro_h */
