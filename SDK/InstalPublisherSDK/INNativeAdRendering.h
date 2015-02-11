//
//  INNativeAdRendering.h
//  Copyright (c) 2013 Instal. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "INNativeAd.h"

/**
 * The INNativeAdRendering protocol provides methods for displaying ad content in
 * custom view classes.
 */

@protocol INNativeAdRendering <NSObject>

/**
 * Populates a view's relevant subviews with ad content.
 *
 * Your implementation of this method should call one or more of the methods listed below.
 *
 * @param adObject An object containing ad assets (text, images) which may be loaded
 * into appropriate subviews (UILabel, UIImageView) via convenience methods.
 * @see [INNativeAd loadTextIntoLabel:]
 * @see [INNativeAd loadTitleIntoLabel:]
 * @see [INNativeAd loadIconIntoImageView:]
 * @see [INNativeAd loadImageIntoImageView:]
 * @see [INNativeAd loadCallToActionTextIntoLabel:]
 * @see [INNativeAd loadCallToActionTextIntoButton:]
 * @see [INNativeAd loadImageForURL:intoImageView:]
 */
- (void)layoutAdAssets:(INNativeAd *)adObject;

@optional

/**
 * Returns size of the rendering object given a maximum width.
 *
 * @param maximumWidth The maximum width intended for the size of the view.
 *
 * @return a CGSize that corresponds to the given maximumWidth.
 */
+ (CGSize)sizeWithMaximumWidth:(CGFloat)maximumWidth;

/**
 * Specifies a nib object containing a view that should be used to render ads.
 *
 * If you want to use a nib object to render ads, you must implement this method.
 *
 * @return an initialized UINib object. This is not allowed to be `nil`.
 */
+ (UINib *)nibForAd;

@end
