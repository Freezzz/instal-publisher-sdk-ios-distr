//
//  INNativeDiscoveryRequest.h
//  InstalSDKSample
//
//  Created by Ivan Litsvinenka on 22/12/15.
//  Copyright © 2015 net.freezzz. All rights reserved.
//

#import <Foundation/Foundation.h>

@class INNativeAd;
@class INNativeDiscoveryRequest;

typedef void(^INNativeDiscoveryAdRequestHandler)(INNativeDiscoveryRequest *request,
                                        NSArray *response,
                                        NSError *error);

////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * The `INNativeAdRequest` class is used to fetch an array of INNativeAd from Instal
 **/
@interface INNativeDiscoveryRequest : NSObject

/** @name Initializing and Starting an Ad Request */

/**
 * Initializes a request object.
 *
 * @param identifier The ad unit identifier for this request. An ad unit is a defined placement in
 * your application set aside for advertising. Ad unit IDs are created on the Instal website.
 *
 * @return An `INNativeAdRequest` object.
 */
+ (instancetype)requestWithAdUnitIdentifier:(NSString *)identifier;

/**
 * Executes a request to the Instal ad server.
 *
 * @param handler A block to execute when the request finishes. The block includes as parameters the
 * request itself and either a valid NSArray of INNativeAd or an NSError object indicating failure.
 */
- (void)startWithCompletionHandler:(INNativeDiscoveryAdRequestHandler)handler;

@end
