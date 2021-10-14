//
//  YYModel.h
//  YYModel <https://github.com/ibireme/YYModel>
//
//  Created by ibireme on 15/5/10.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>

#if __has_include(<MBModel/MBModel.h>)
FOUNDATION_EXPORT double MBModelVersionNumber;
FOUNDATION_EXPORT const unsigned char MBModelVersionString[];
#import <MBModel/NSObject+MBModel.h>
#import <MBModel/MBClassInfo.h>
#else
#import "NSObject+MBModel.h"
#import "MBClassInfo.h"
#endif
