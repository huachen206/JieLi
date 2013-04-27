//
//  Created by ShareSDK.cn on 13-1-14.
//  官网地址:http://www.ShareSDK.cn
//  技术支持邮箱:support@sharesdk.cn
//  官方微信:ShareSDK   （如果发布新版本的话，我们将会第一时间通过微信将版本更新内容推送给您。如果使用过程中有任何问题，也可以通过微信与我们取得联系，我们将会在24小时内给予回复）
//  商务QQ:1955211608
//  Copyright (c) 2013年 ShareSDK.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *	@brief	授权凭证
 */
@interface SSRenRenCredential : NSObject <NSCoding>
{
@private
    NSMutableDictionary *_sourceData;
}

/**
 *	@brief	源数据
 */
@property (nonatomic,retain) NSDictionary *sourceData;

/**
 *	@brief	访问令牌
 */
@property (nonatomic,readonly) NSString *accessToken;

/**
 *	@brief	过期时间
 */
@property (nonatomic,readonly) NSDate *expiresIn;

/**
 *	@brief	刷新令牌
 */
@property (nonatomic,readonly) NSString *refreshToken;

/**
 *	@brief	权限
 */
@property (nonatomic,readonly) NSString *scope;

/**
 *	@brief	用户ID
 */
@property (nonatomic,readonly) long long uid;

/**
 *	@brief	判断授权数据是否有效
 */
@property (nonatomic,readonly) BOOL available;

/**
 *	@brief	初始化授权信息
 *
 *	@param 	sourceData 	源授权数据
 *
 *	@return	授权信息
 */
- (id)initWithData:(NSDictionary *)sourceData;

@end
