//
//  INInterstitialAdControlle+Internal.h
//  InstalPublisherSDK
//
//  Created by Ivan Litsvinenka on 29/01/15.
//  Copyright (c) 2015 com.instal. All rights reserved.
//
#import "INInterstitialAdController.h"

@interface INInterstitialAdController (Internal)
@property (nonatomic, assign, getter = isTesting) BOOL testing;

@property (nonatomic, strong) NSString * templateName;
@property (nonatomic, strong) NSString * templateType;
- (void)setFakeRequestTemplate:(NSString *)templateName templateType:(NSString *)templateType;

@end