//
//  INInterstitialAdController.h
//  Instal
//
//  Copyright (c) 2014 Instal, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol INInterstitialAdControllerDelegate;

/**
 * The `INInterstitialAdController` class provides a full-screen advertisement that can be
 * displayed during natural transition points in your application.
 */

@interface INInterstitialAdController : UIViewController

/** @name Obtaining an Interstitial Ad */

/**
 * Returns an interstitial ad object matching the given ad unit ID.
 *
 * The first time this method is called for a given ad unit ID, a new interstitial ad object is
 * created, stored in a shared pool, and returned. Subsequent calls for the same ad unit ID will
 * return that object, unless you have disposed of the object using
 * `removeSharedInterstitialAdController:`.
 *
 * There can only be one interstitial object for an ad unit ID at a given time.
 *
 * @param adUnitId A string representing a Instal ad unit ID.
 */
+ (INInterstitialAdController *)interstitialAdControllerForAdUnitId:(NSString *)adUnitId;

/** @name Setting and Getting the Delegate */

/**
 * The delegate (`INInterstitialAdControllerDelegate`) of the interstitial ad object.
 */
@property (nonatomic, weak) id<INInterstitialAdControllerDelegate> delegate;

/** @name Setting Request Parameters */

/**
 * The Instal ad unit ID for this interstitial ad.
 *
 * Ad unit IDs are created on the Instal website. An ad unit is a defined placement in your
 * application set aside for advertising. If no ad unit ID is set, the ad object will use a default
 * ID that only receives test ads.
 */
@property (nonatomic, copy) NSString *adUnitId;


/** @name Loading an Interstitial Ad */

/**
 * Begins loading ad content for the interstitial.
 *
 * You can implement the `interstitialDidLoadAd:` and `interstitialDidFailToLoadAd:` methods of
 * `INInterstitialAdControllerDelegate` if you would like to be notified as loading succeeds or
 * fails.
 */
- (void)loadAd;

/** @name Detecting Whether the Interstitial Ad Has Loaded */

/**
 * A Boolean value that represents whether the interstitial ad has loaded an advertisement and is
 * ready to be presented.
 *
 * After obtaining an interstitial ad object, you can use `loadAd` to tell the object to begin
 * loading ad content. Once the content has been loaded, the value of this property will be YES.
 */
@property (nonatomic, assign, readonly) BOOL ready;

/** @name Presenting an Interstitial Ad */

/**
 * Presents the interstitial ad modally from the specified view controller.
 *
 * This method will do nothing if the interstitial ad has not been loaded (i.e. the value of its
 * `ready` property is NO).
 *
 * `INInterstitialAdControllerDelegate` provides optional methods that you may implement to stay
 * informed about when an interstitial takes over or relinquishes the screen.
 *
 * @param controller The view controller that should be used to present the interstitial ad.
 */
- (void)showFromViewController:(UIViewController *)controller;

/** @name Disposing of an Interstitial Ad */

/**
 * Removes the given interstitial object from the shared pool of interstitials available to your
 * application.
 *
 * This method removes the mapping from the interstitial's ad unit ID to the interstitial ad
 * object. In other words, you will receive a different ad object if you subsequently call
 * `interstitialAdControllerForAdUnitId:` for the same ad unit ID.
 *
 * @warning **Important**: This method is intended to be used for deallocating the interstitial
 * ad object when it is no longer needed. You should `nil` out any references you have to the
 * object after calling this method.
 *
 * @param controller The interstitial ad object that should be disposed.
 */
+ (void)removeSharedInterstitialAdController:(INInterstitialAdController *)controller;

/*
 * Returns the shared pool of interstitial objects for your application.
 */
+ (NSMutableArray *)sharedInterstitialAdControllers;

@end

#pragma mark -

/**
 * The delegate of an `INInterstitialAdController` object must adopt the
 * `INInterstitialAdControllerDelegate` protocol.
 *
 * The optional methods of this protocol allow the delegate to be notified of interstitial state
 * changes, such as when an ad has loaded, when an ad has been presented or dismissed from the
 * screen, and when an ad has expired.
 */

@protocol INInterstitialAdControllerDelegate <NSObject>

@optional

/** @name Detecting When an Interstitial Ad is Loaded */

/**
 * Sent when an interstitial ad object successfully loads an ad.
 *
 * @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialDidLoadAd:(INInterstitialAdController *)interstitial;

/**
 * Sent when an interstitial ad object fails to load an ad.
 *
 * @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialDidFailToLoadAd:(INInterstitialAdController *)interstitial;

/** @name Detecting When an Interstitial Ad is Presented */

/**
 * Sent immediately before an interstitial ad object is presented on the screen.
 *
 * Your implementation of this method should pause any application activity that requires user
 * interaction.
 *
 * @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialWillAppear:(INInterstitialAdController *)interstitial;

/**
 * Sent after an interstitial ad object has been presented on the screen.
 *
 * @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialDidAppear:(INInterstitialAdController *)interstitial;

/** @name Detecting When an Interstitial Ad is Dismissed */

/**
 * Sent immediately before an interstitial ad object will be dismissed from the screen.
 *
 * @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialWillDisappear:(INInterstitialAdController *)interstitial;

/**
 * Sent after an interstitial ad object has been dismissed from the screen, returning control
 * to your application.
 *
 * Your implementation of this method should resume any application activity that was paused
 * prior to the interstitial being presented on-screen.
 *
 * @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialDidDisappear:(INInterstitialAdController *)interstitial;


/**
 * Sent when the user taps the interstitial ad and the ad is about to perform its target action.
 *
 * This action may include displaying a modal or leaving your application.
 *
 * @param interstitial The interstitial ad object sending the message.
 */
- (void)interstitialDidReceiveTapEvent:(INInterstitialAdController *)interstitial;


@end
