//
//  INNativeAdRequest.h
//  Copyright (c) 2013 Instal. All rights reserved.
//

#import <Foundation/Foundation.h>

@class INNativeAd;
@class INNativeAdRequest;

typedef void(^INNativeAdRequestHandler)(INNativeAdRequest *request,
                                      INNativeAd *response,
                                      NSError *error);

////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * The `INNativeAdRequest` class is used to manage individual requests to the Instal ad server for
 * native ads.
 *
 * @warning **Note:** This class is meant for one-off requests for which you intend to manually
 * process the native ad response. If you are using `MPTableViewAdPlacer` or
 * `MPCollectionViewAdPlacer` to display ads, there should be no need for you to use this class.
 */

@interface INNativeAdRequest : NSObject

/** @name Initializing and Starting an Ad Request */

/**
 * Initializes a request object.
 *
 * @param identifier The ad unit identifier for this request. An ad unit is a defined placement in
 * your application set aside for advertising. Ad unit IDs are created on the Instal website.
 *
 * @return An `INNativeAdRequest` object.
 */
+ (INNativeAdRequest *)requestWithAdUnitIdentifier:(NSString *)identifier;

/**
 * Executes a request to the Instal ad server.
 *
 * @param handler A block to execute when the request finishes. The block includes as parameters the
 * request itself and either a valid INNativeAd or an NSError object indicating failure.
 */
- (void)startWithCompletionHandler:(INNativeAdRequestHandler)handler;

/** @name Enabling Test Mode */

/**
 * A Boolean value that determines whether the ad view should request ads in test mode.
 *
 * The default value is NO.
 * @warning **Important**: If you set this value to YES, make sure to reset it to NO before
 * submitting your application to the App Store.
 */
@property (nonatomic, assign, getter = isTesting) BOOL testing;

@property (nonatomic, strong) NSString * templateName;
@property (nonatomic, strong) NSString * templateType;

/** @name Loading a Banner Ad */


- (void)setFakeRequestTemplate:(NSString *)templateName templateType:(NSString *)templateType;

@end
