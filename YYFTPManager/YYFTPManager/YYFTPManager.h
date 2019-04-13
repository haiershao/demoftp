//
//  YYFTPManager.h
//  ERA
//
//  Created by Mac on 2019/4/8.
//  Copyright © 2019 silence. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@interface YYFTPManager : NSObject
@property (nonatomic, copy, nullable) NSURL *serverURL;
@property (nonatomic, copy, nullable) NSString *username;
@property (nonatomic, copy, nullable) NSString *password;

@property (nonatomic, assign) NSInteger finishedSize;
@property (nonatomic, assign) NSInteger totalSize;

@property (nonatomic, copy, nullable) void (^progressAction)(NSInteger totalSize, NSInteger finishedSize, CGFloat finishedPercent);
@property (nonatomic, copy, nullable) void (^successAction)(Class resultClass, id result);
@property (nonatomic, copy, nullable) void (^failAction)(CFStreamErrorDomain errorDomain, NSInteger error, NSString *errorDescription);

- (instancetype)initManager;

/**
 下载
 
 @param path 存储本地路径
 @param fileName 下载服务端文件名称
 */
- (BOOL)downloadFileRequestWithPath:(NSString *)path fileName:(NSString *)fileName;

- (BOOL)getResourceList;
@end

NS_ASSUME_NONNULL_END
