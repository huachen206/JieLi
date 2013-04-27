//
//  Created by ShareSDK.cn on 13-1-14.
//  官网地址:http://www.ShareSDK.cn
//  技术支持邮箱:support@sharesdk.cn
//  官方微信:ShareSDK   （如果发布新版本的话，我们将会第一时间通过微信将版本更新内容推送给您。如果使用过程中有任何问题，也可以通过微信与我们取得联系，我们将会在24小时内给予回复）
//  商务QQ:1955211608
//  Copyright (c) 2013年 ShareSDK.cn. All rights reserved.
//

#import <AGCommon/ICMErrorInfo.h>

#ifndef ShareSDKCoreService_SSCTypeDef_h
#define ShareSDKCoreService_SSCTypeDef_h



/**
 *	@brief	授权会话状态
 */
typedef enum
{
    SSCAuthSessionStateBegan = 0,  /**< 开始会话 */
	SSCAuthSessionStateSuccess = 1, /**< 会话成功 */
	SSCAuthSessionStateFail = 2, /**< 会话失败 */
    SSCAuthSessionStateCancel = 3 /**< 会话取消 */
}
SSCAuthSessionState;

/**
 *	@brief	分享会话状态
 */
typedef enum
{
    SSCShareSessionStateBegan = 0, /**< 开始会话 */
	SSCShareSessionStateSuccess = 1, /**< 会话成功 */
	SSCShareSessionStateFail = 2, /**< 会话失败 */
    SSCShareSessionStateCancel = 3 /**< 会话取消 */
}
SSCShareSessionState;

/**
 *	@brief	分享类型
 */
typedef enum
{
	SSCShareTypeSinaWeibo = 1, /**< 新浪微博 */
	SSCShareTypeTencentWeibo = 2, /**< 腾讯微博 */
	SSCShareTypeSohuWeibo = 3, /**< 搜狐微博 */
	SSCShareType163Weibo = 4, /**< 网易微博 */
	SSCShareTypeDouBan = 5, /**< 豆瓣社区 */
	SSCShareTypeQQSpace = 6, /**< QQ空间 */
	SSCShareTypeRenren = 7, /**< 人人网 */
	SSCShareTypeKaixin = 8, /**< 开心网 */
	SSCShareTypePengyou = 9, /**< 朋友网 */
	SSCShareTypeFacebook = 10, /**< Facebook */
	SSCShareTypeTwitter = 11, /**< Twitter */
	SSCShareTypeEvernote = 12, /**< 印象笔记 */
	SSCShareTypeFoursquare = 13, /**< Foursquare */
	SSCShareTypeGooglePlus = 14, /**< Google＋ */
	SSCShareTypeInstagram = 15, /**< Instagram */
	SSCShareTypeLinkedIn = 16, /**< LinkedIn */
	SSCShareTypeTumbir = 17, /**< Tumbir */
    SSCShareTypeMail = 18, /**< 邮件分享 */
	SSCShareTypeSMS = 19, /**< 短信分享 */
	SSCShareTypeAirPrint = 20, /**< 打印 */
	SSCShareTypeCopy = 21, /**< 拷贝 */
    SSCShareTypeWeixiSession = 22, /**< 微信好友 */
	SSCShareTypeWeixiTimeline = 23, /**< 微信朋友圈 */
    SSCShareTypeQQ = 24, /**< QQ */
    SSCShareTypeInstapaper = 25, /**< Instapaper */
    SSCShareTypePocket = 26, /**< Pocket */
    SSCShareTypeYouDaoNote = 27,     /**< 有道云笔记 */
    SSCShareTypeAny = 99   /**< 任意平台 */
}
SSCShareType;

/**
 *	@brief	授权会话返回事件
 */
typedef void(^SSCAuthSessionResultEvent) (SSCAuthSessionState state, id user, id<ICMErrorInfo> error);


#endif
