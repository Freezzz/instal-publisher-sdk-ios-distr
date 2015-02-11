//
//  INAdView.h
//  InstalPublisherSDK
//
//  Created by Insal.com on 11/11/14.
//  Copyright (c) 2014 com.instal All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol INAdViewDelegate;

/**
 * The INAdView class provides a view that can display banner advertisements.
 */

@interface INAdView : UIView

/** @name Initializing a Banner Ad */

/**
 * Initializes an INAdView with the given ad unit ID and banner size.
 *
 * @param adUnitId A string representing a Instal ad unit ID.
 * @param size The desired ad size. A list of standard ad sizes is available in INConstants.h.
 * @return A newly initialized ad view corresponding to the given ad unit ID and size.
 */
- (id)initWithAdUnitId:(NSString *)adUnitId;

/** @name Setting and Getting the Delegate */

/**
 * The delegate (`INAdViewDelegate`) of the ad view.
 *
 * @warning **Important**: Before releasing an instance of `INAdView`, you must set its delegate
 * property to `nil`.
 */
@property (nonatomic, weak) id<INAdViewDelegate> delegate;

/** @name Setting Request Parameters */

/**
 * The Instal ad unit ID for this ad view.
 *
 * Ad unit IDs are created on the Instal website. An ad unit is a defined placement in your
 * application set aside for advertising. If no ad unit ID is set, the ad view will use a default
 * ID that only receives test ads.
 */
@property (nonatomic, copy) NSString *adUnitId;


/**
 * Requests a new ad from the Instal ad server.
 *
 * If the ad view is already loading an ad, this call will be ignored. You may use `forceRefreshAd`
 * if you would like cancel any existing ad requests and force a new ad to load.
 */
- (void)loadAd;

/**
 * Cancels any existing ad requests and requests a new ad from the Instal ad server.
 */
- (void)forceRefreshAd;

/** @name Obtaining the Size of the Current Ad */

/**
 * Returns the size of the current ad being displayed in the ad view.
 *
 * Ad sizes may vary between different ad networks. This method returns the actual size of the
 * underlying mediated ad. This size may be different from the original, initialized size of the
 * ad view. You may use this size to determine to adjust the size or positioning of the ad view
 * to avoid clipping or border issues.
 *
 * @returns The size of the underlying mediated ad.
 */
- (CGSize)adContentViewSize;
@end

////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma mark -

/**
 * The delegate of an `INAdView` object must adopt the `INAdViewDelegate` protocol. It must
 * implement `viewControllerForPresentingModalView` to provide a root view controller from which
 * the ad view should present modal content.
 *
 * Optional methods of this protocol allow the delegate to be notified of banner success or
 * failure, as well as other lifecycle events.
 */

@protocol INAdViewDelegate <NSObject>

@required

/** @name Managing Modal Content Presentation */

/**
 * Asks the delegate for a view controller to use for presenting modal content, such as the in-app
 * browser that can appear when an ad is tapped.
 *
 * @return A view controller that should be used for presenting modal content.
 */
- (UIViewController *)viewControllerForPresentingModalView;

@optional

/** @name Detecting When a Banner Ad is Loaded */

/**
 * Sent when an ad view successfully loads an ad.
 *
 * Your implementation of this method should insert the ad view into the view hierarchy, if you
 * have not already done so.
 *
 * @param view The ad view sending the message.
 */
- (void)adViewDidLoadAd:(INAdView *)view;

/**
 * Sent when an ad view fails to load an ad.
 *
 * To avoid displaying blank ads, you should hide the ad view in response to this message.
 *
 * @param view The ad view sending the message.
 */
- (void)adViewDidFailToLoadAd:(INAdView *)view;

/** @name Detecting When a User Interacts With the Ad View */

/**
 * Sent when an ad view is about to present modal content.
 *
 * This method is called when the user taps on the ad view. Your implementation of this method
 * should pause any application activity that requires user interaction.
 *
 * @param view The ad view sending the message.
 * @see `didDismissModalViewForAd:`
 */
- (void)willPresentModalViewForAd:(INAdView *)view;

/**
 * Sent when an ad view has dismissed its modal content, returning control to your application.
 *
 * Your implementation of this method should resume any application activity that was paused
 * in response to `willPresentModalViewForAd:`.
 *
 * @param view The ad view sending the message.
 * @see `willPresentModalViewForAd:`
 */
- (void)didDismissModalViewForAd:(INAdView *)view;

/**
 * Sent when a user is about to leave your application as a result of tapping
 * on an ad.
 *
 * Your application will be moved to the background shortly after this method is called.
 *
 * @param view The ad view sending the message.
 */
- (void)willLeaveApplicationFromAd:(INAdView *)view;

@end
