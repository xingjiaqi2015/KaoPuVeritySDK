//
//  KPCommunityManager.h
//  FriendVeritySDK
//
//  Created by QiJia on 2020/6/18.
//  Copyright © 2020 xjq. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface KPCommunityManager : NSObject

+ (instancetype)shareInstance;

//扫一扫

- (void)startScanning;

/// 跳转到访客申请界面，这些参数通过扫描获得
/// @param province 省
/// @param city 市
/// @param area 区
/// @param communityName 小区名字
/// @param communityId 小区id

- (void)startVisitingApplicationWithProvince:(NSString*)province
                                        city:(NSString*)city
                                        area:(NSString*)area
                               communityName:(NSString*)communityName
                                 communityId:(NSString*)communityId;

//跳转到住户申请界面

- (void)startHouseholderApplication;

//跳转到住户申请记录界面

- (void)startHouseholderApplicationList;

//跳转到访客申请记录页面

- (void)startVisitingApplicationList;

//跳转到住户授权访客申请界面

- (void)startHouseholdAuthorization;

//跳转到出入记录界面

- (void)startRecord;


//根据手机号码，用户信息获取用户所在的小区信息

- (void)getUserInfoWithPhone:(NSString*)userPhone userId:(NSString*)userId;


/// 检查用户有没有权限进入小区，并进行跳转
/// @param province 省
/// @param city 市
/// @param area 区
/// @param communityName 小区名字
/// @param communityId 小区id

- (void)checkUserIdentityWithProvince:(NSString*)province
                                 city:(NSString*)city
                                 area:(NSString*)area
                        communityName:(NSString*)communityName
                          communityId:(NSString*)communityId
                              success:(void (^)(id response))success
                              failure:(void (^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
