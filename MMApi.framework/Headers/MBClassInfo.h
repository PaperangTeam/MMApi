//
//  MBClassInfo.h
//  MBModel <https://github.com/ibireme/MBModel>
//
//  Created by ibireme on 15/5/9.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Type encoding's type.
 */
typedef NS_OPTIONS(NSUInteger, MBEncodingType) {
    MBEncodingTypeMask       = 0xFF, ///< mask of type value
    MBEncodingTypeUnknown    = 0, ///< unknown
    MBEncodingTypeVoid       = 1, ///< void
    MBEncodingTypeBool       = 2, ///< bool
    MBEncodingTypeInt8       = 3, ///< char / BOOL
    MBEncodingTypeUInt8      = 4, ///< unsigned char
    MBEncodingTypeInt16      = 5, ///< short
    MBEncodingTypeUInt16     = 6, ///< unsigned short
    MBEncodingTypeInt32      = 7, ///< int
    MBEncodingTypeUInt32     = 8, ///< unsigned int
    MBEncodingTypeInt64      = 9, ///< long long
    MBEncodingTypeUInt64     = 10, ///< unsigned long long
    MBEncodingTypeFloat      = 11, ///< float
    MBEncodingTypeDouble     = 12, ///< double
    MBEncodingTypeLongDouble = 13, ///< long double
    MBEncodingTypeObject     = 14, ///< id
    MBEncodingTypeClass      = 15, ///< Class
    MBEncodingTypeSEL        = 16, ///< SEL
    MBEncodingTypeBlock      = 17, ///< block
    MBEncodingTypePointer    = 18, ///< void*
    MBEncodingTypeStruct     = 19, ///< struct
    MBEncodingTypeUnion      = 20, ///< union
    MBEncodingTypeCString    = 21, ///< char*
    MBEncodingTypeCArray     = 22, ///< char[10] (for example)
    
    MBEncodingTypeQualifierMask   = 0xFF00,   ///< mask of qualifier
    MBEncodingTypeQualifierConst  = 1 << 8,  ///< const
    MBEncodingTypeQualifierIn     = 1 << 9,  ///< in
    MBEncodingTypeQualifierInout  = 1 << 10, ///< inout
    MBEncodingTypeQualifierOut    = 1 << 11, ///< out
    MBEncodingTypeQualifierBycopy = 1 << 12, ///< bycopy
    MBEncodingTypeQualifierByref  = 1 << 13, ///< byref
    MBEncodingTypeQualifierOneway = 1 << 14, ///< oneway
    
    MBEncodingTypePropertyMask         = 0xFF0000, ///< mask of property
    MBEncodingTypePropertyReadonly     = 1 << 16, ///< readonly
    MBEncodingTypePropertyCopy         = 1 << 17, ///< copy
    MBEncodingTypePropertyRetain       = 1 << 18, ///< retain
    MBEncodingTypePropertyNonatomic    = 1 << 19, ///< nonatomic
    MBEncodingTypePropertyWeak         = 1 << 20, ///< weak
    MBEncodingTypePropertyCustomGetter = 1 << 21, ///< getter=
    MBEncodingTypePropertyCustomSetter = 1 << 22, ///< setter=
    MBEncodingTypePropertyDynamic      = 1 << 23, ///< @dynamic
};

/**
 Get the type from a Type-Encoding string.
 
 @discussion See also:
 https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtTypeEncodings.html
 https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtPropertyIntrospection.html
 
 @param typeEncoding  A Type-Encoding string.
 @return The encoding type.
 */
MBEncodingType MBEncodingGetType(const char *typeEncoding);


/**
 Instance variable information.
 */
@interface MBClassIvarInfo : NSObject
@property (nonatomic, assign, readonly) Ivar ivar;              ///< ivar opaque struct
@property (nonatomic, strong, readonly) NSString *name;         ///< Ivar's name
@property (nonatomic, assign, readonly) ptrdiff_t offset;       ///< Ivar's offset
@property (nonatomic, strong, readonly) NSString *typeEncoding; ///< Ivar's type encoding
@property (nonatomic, assign, readonly) MBEncodingType type;    ///< Ivar's type

/**
 Creates and returns an ivar info object.
 
 @param ivar ivar opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithIvar:(Ivar)ivar;
@end


/**
 Method information.
 */
@interface MBClassMethodInfo : NSObject
@property (nonatomic, assign, readonly) Method method;                  ///< method opaque struct
@property (nonatomic, strong, readonly) NSString *name;                 ///< method name
@property (nonatomic, assign, readonly) SEL sel;                        ///< method's selector
@property (nonatomic, assign, readonly) IMP imp;                        ///< method's implementation
@property (nonatomic, strong, readonly) NSString *typeEncoding;         ///< method's parameter and return types
@property (nonatomic, strong, readonly) NSString *returnTypeEncoding;   ///< return value's type
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *argumentTypeEncodings; ///< array of arguments' type

/**
 Creates and returns a method info object.
 
 @param method method opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithMethod:(Method)method;
@end


/**
 Property information.
 */
@interface MBClassPropertyInfo : NSObject
@property (nonatomic, assign, readonly) objc_property_t property; ///< property's opaque struct
@property (nonatomic, strong, readonly) NSString *name;           ///< property's name
@property (nonatomic, assign, readonly) MBEncodingType type;      ///< property's type
@property (nonatomic, strong, readonly) NSString *typeEncoding;   ///< property's encoding value
@property (nonatomic, strong, readonly) NSString *ivarName;       ///< property's ivar name
@property (nullable, nonatomic, assign, readonly) Class cls;      ///< may be nil
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *protocols; ///< may nil
@property (nonatomic, assign, readonly) SEL getter;               ///< getter (nonnull)
@property (nonatomic, assign, readonly) SEL setter;               ///< setter (nonnull)

/**
 Creates and returns a property info object.
 
 @param property property opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithProperty:(objc_property_t)property;
@end


/**
 Class information for a class.
 */
@interface MBClassInfo : NSObject
@property (nonatomic, assign, readonly) Class cls; ///< class object
@property (nullable, nonatomic, assign, readonly) Class superCls; ///< super class object
@property (nullable, nonatomic, assign, readonly) Class metaCls;  ///< class's meta class object
@property (nonatomic, readonly) BOOL isMeta; ///< whether this class is meta class
@property (nonatomic, strong, readonly) NSString *name; ///< class name
@property (nullable, nonatomic, strong, readonly) MBClassInfo *superClassInfo; ///< super class's class info
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, MBClassIvarInfo *> *ivarInfos; ///< ivars
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, MBClassMethodInfo *> *methodInfos; ///< methods
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, MBClassPropertyInfo *> *propertyInfos; ///< properties

/**
 If the class is changed (for example: you add a method to this class with
 'class_addMethod()'), you should call this method to refresh the class info cache.
 
 After called this method, `needUpdate` will returns `YES`, and you should call 
 'classInfoWithClass' or 'classInfoWithClassName' to get the updated class info.
 */
- (void)setNeedUpdate;

/**
 If this method returns `YES`, you should stop using this instance and call
 `classInfoWithClass` or `classInfoWithClassName` to get the updated class info.
 
 @return Whether this class info need update.
 */
- (BOOL)needUpdate;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param cls A class.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClass:(Class)cls;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param className A class name.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClassName:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
