//
//  KPContactManager.h
//  FriendVeritySDK
//
//  Created by QiJia on 2020/2/27.
//  Copyright © 2020 xjq. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN


//success 验证是否成功
//info 包含两个keyvalue ,verityType验证业务类型 callBackInfo:头像URL
typedef void(^FriendVerityBlock)(BOOL success , NSDictionary *info);//

@interface KPFriendVerityManager : NSObject

@property (nonatomic ,copy) NSString *currentUserId;

@property (nonatomic ,copy) NSString *serviceType;//验证业务类型

+ (instancetype)shareInstance;

//验证结果回调block

@property (nonatomic ,strong) FriendVerityBlock resultBlock;

/// SDK初始化
/// @param userId 当前登录用户的用户id
- (void)initWithUserId:(NSString*)userId;


/// 注册新用户
/// @param userId 用户id
/// @param avaterUrl 用户头像URL,远程访问地址
/// @param phone 用户电话号码
/// @param nickName 用户昵称
/// @param gender 用户性别 1：男 2：女  0：未知
/// @param deviceName 设备名字 , 格式是：iPhoneX / iOS  12.3 "
/// @param deviceId 设备id , 可以用代表设备的唯一标识字符
/// @param deviceIp 设备ip ，当前的设备IP地址
/// @param success 成功回调
/// @param failure 失败回调

- (void)registerUserWithUserId:(NSString*)userId
                     avaterUrl:(NSString*)avaterUrl
                         phone:(NSString*)phone
                      nickName:(NSString *)nickName
                        gender:(NSString*)gender
                    deviceName:(NSString*)deviceName
                      deviceId:(NSString*)deviceId
                      deviceIp:(NSString*)deviceIp
                       success:(void (^)(id response))success failure:(void (^)(NSError *error))failure;


/// 上传通讯录

- (void)uploadContactSuccess:(void (^)(id response))success failure:(void (^)(NSError *error))failure;

/// 上传头像
/// @param image 头像image对象
/// @param success 成功回调
/// @param failure 失败回调

- (void)uploadAvaterWithImage:(UIImage*)image success:(void (^)(NSString *url))success failure:(void (^)(NSString *msg))failure;


/// 修改用户信息
/// @param avaterUrl 用户头像URL，远程访问地址
/// @param phone 用户手机号码
/// @param nickName 用户昵称
/// @param success 成功回调
/// @param failure 失败回调

- (void)aleterUserInfoWithAvaterUrl:(NSString*)avaterUrl
                              phone:(NSString*)phone
                           nickName:(NSString *)nickName
                            success:(void (^)(id response))success
                            failure:(void (^)(NSError *error))failure;

/// 本人进行好友验证

- (void)startFriendVerity;

/// 选择参与验证的好友

- (void)settingVerityList;

/// 帮助好友进行验证

- (void)helpFriendVerity;

//首次进行好友验证
- (void)firstFriendVerity;

//进入社区管理模块

- (void)startCommunityManager;

//授权并进入社区管理模块

- (void)startAuthorizeToCommunityManager;

@end

NS_ASSUME_NONNULL_END
