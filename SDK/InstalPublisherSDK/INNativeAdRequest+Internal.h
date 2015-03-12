//
//  INNativeAdRequest+Internal.h
//  InstalPublisherSDK
//
//  Created by Ivan Litsvinenka on 29/01/15.
//  Copyright (c) 2015 com.instal. All rights reserved.
//
#import "INNativeAdRequest.h"

@interface INNativeAdRequest (Internal)
- (void)setTesting:(BOOL)testing;
- (void)setStaging:(BOOL)staging;
@end