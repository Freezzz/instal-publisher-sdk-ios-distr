//
//  INAlertAd.h
//  InstalPublisherSDK
//
//  Created by Ivan Litsvinenka on 17/12/14.
//  Copyright (c) 2014 com.instal All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol INAlertAdDelegate;

@interface INAlertAd : UIView

/**
 * The Instal ad unit ID for this alert ad.
 *
 * Ad unit IDs are created on the Instal website. An ad unit is a defined placement in your
 * application set aside for advertising. If no ad unit ID is set, the ad object will use a default
 * ID that only receives test ads.
 */
@property (nonatomic, copy) NSString *adUnitId;

/** @name Detecting Whether the Alert Ad Has Loaded */

/**
 * A Boolean value that represents whether the alert ad has loaded an advertisement and is
 * ready to be presented.
 *
 * After obtaining an alert ad object, you can use `loadAd` to tell the object to begin
 * loading ad content. Once the content has been loaded, the value of this property will be YES.
 */
@property (nonatomic, assign, readonly, getter=isReady) BOOL ready;

@property (nonatomic, weak) id<INAlertAdDelegate> delegate;

- (instancetype) initWithAdUnitId:(NSString *)adUnitId;
- (void) loadAd;
- (void) showAd;
@end


@protocol INAlertAdDelegate <NSObject>
@required
- (UIViewController *)viewControllerForPresentingModalView;

@optional
/** @name Detecting When an alert Ad is Loaded */

/**
 * Sent when an alert ad object successfully loads an ad.
 *
 * @param alert The alert ad object sending the message.
 */
- (void)alertDidLoadAd:(INAlertAd *)alert;

/**
 * Sent when an alert ad object fails to load an ad.
 *
 * @param alert The alert ad object sending the message.
 */
- (void)alertDidFailToLoadAd:(INAlertAd *)alert;
@end