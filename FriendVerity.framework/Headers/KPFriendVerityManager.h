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
//test

//success 验证是否成功
//info 包含两个keyvalue ,verityType验证业务类型 callBackInfo:头像URL
typedef void(^FriendVerityBlock)(BOOL success , NSDictionary *info);//

typedef void(^FriendVerityStartBlock)(BOOL success);

typedef void(^FriendVerityEndBlock)(BOOL success);

@interface KPFriendVerityManager : NSObject

@property (nonatomic ,copy) NSString *currentUserId;

@property (nonatomic ,copy) NSString *serviceType;//验证业务类型

@property (nonatomic ,copy) NSString *isVerityForScan;//是否扫码验证

@property (nonatomic ,copy) NSString *loginStatus;//是否登录

@property (nonatomic ,copy) NSString *tokenid;

+ (instancetype)shareInstance;

//验证结果回调block

@property (nonatomic ,strong) FriendVerityBlock _Nullable resultBlock;

@property (nonatomic ,strong) FriendVerityStartBlock _Nullable startBlock;

@property (nonatomic ,strong) FriendVerityEndBlock _Nullable endBlock;

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

- (void)uploadNewContact;

- (void)uploadContactWithUserId:(NSString*)userId;

- (void)clearCache;

/// 获取用户资料

- (void)getUserInfoWithUserId:(NSString*)userId success:(void (^)(id response))success failure:(void (^)(NSError *error))failure;

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

- (void)startFriendVerityWithUserId:(NSString*)userId;

/// 选择参与验证的好友

- (void)settingVerityList;

/// 帮助好友进行验证

- (void)helpFriendVerity;

- (void)helpFriendVerityWithUserId:(NSString *)userId;

- (void)startHelpFriendVerityWithUserId:(NSString *)userId taskId:(NSString*)taskId;

//首次进行好友验证
- (void)firstFriendVerity;

//进入社区管理模块

- (void)startCommunityManager;

- (void)startAuthorizeToCommunityManagerWithPhoneNumber:(NSString*)phoneNumber avatar:(NSString*)avatar realName:(NSString*)realName userId:(NSString*)userId tokenId:(NSString*)tokenId deviceType:(NSString*)deviceType gender:(NSString*)gender;

- (void)startAuthorizeToCommunityManagerWithPhoneNumber:(NSString *)phoneNumber avatar:(NSString *)avatar realName:(NSString *)realName userId:(NSString *)userId tokenId:(NSString *)tokenId deviceType:(NSString *)deviceType gender:(NSString *)gender superVc:(UIViewController*)superVc success:(void (^)(id _Nonnull))success failure:(void (^)(NSError * _Nonnull))failure;

/// 解析推送信息
/// @param notice 不可空参数，点击推送后获取的推送信息的notice

- (void)processingNotice:(NSDictionary*)notice;

/// 进入社区管理模块
/// @param code 不可空参数，授权后获取的code

- (void)startAuthorizeToCommunityManagerWithCode:(NSString*)code;

//退出登录

- (void)loginOut;

///处理前台获取的推送推送信息
/// @param pushMsg 不可空参数，前台获取的推送推送信息

- (void)handlePushMsgOnForegroundWithPushMsg:(NSDictionary*)pushMsg;

//授权并进入社区管理模块

- (void)startAuthorizeToCommunityManager;

//处理扫描结果

- (void)handleScannignResult:(NSDictionary*)result;

@end

NS_ASSUME_NONNULL_END
