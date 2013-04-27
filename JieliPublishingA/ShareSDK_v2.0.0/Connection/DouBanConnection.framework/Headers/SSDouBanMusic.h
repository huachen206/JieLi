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
 *	@brief	音乐媒体
 */
@interface SSDouBanMusic : NSObject <NSCoding>
{
@private
    NSMutableDictionary *_sourceData;
}

/**
 *	@brief	源数据
 */
@property (nonatomic,retain) NSDictionary *sourceData;

/**
 *	@brief	音乐路径
 */
@property (nonatomic,readonly) NSString *src;

/**
 *	@brief	标题
 */
@property (nonatomic,readonly) NSString *title;

/**
 *	@brief	暂无
 */
@property (nonatomic,readonly) NSString *artist;

/**
 *	@brief	暂无
 */
@property (nonatomic,readonly) NSString *album;

/**
 *	@brief	类型
 */
@property (nonatomic,readonly) NSString *type;

/**
 *	@brief	创建音乐媒体信息
 *
 *	@param 	response 	回复数据
 *
 *	@return	音乐媒体信息
 */
+ (SSDouBanMusic *)musicWithResponse:(NSDictionary *)response;

@end
