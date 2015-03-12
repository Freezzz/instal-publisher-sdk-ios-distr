//
//  INInterstitialAdControlle+Internal.h
//  InstalPublisherSDK
//
//  Created by Ivan Litsvinenka on 29/01/15.
//  Copyright (c) 2015 com.instal. All rights reserved.
//
#import "INInterstitialAdController.h"

@interface INInterstitialAdController (Internal)

- (void)setFakeRequestTemplate:(NSString *)templateName templateType:(NSString *)templateType;

- (BOOL)isTesting;
- (void)setTesting:(BOOL)testing;
- (void)setStaging:(BOOL)staging;

- (NSString *) templateName;
- (NSString *) templateType;
@end