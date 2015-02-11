//
//  INAdView+Internal.h
//  InstalPublisherSDK
//
//  Created by Insal.com on 29/01/15.
//  Copyright (c) 2015 com.instal. All rights reserved.
//
#import "INAdView.h"

@interface INAdView (Internal)

- (void)setFakeRequestTemplate:(NSString *)templateName templateType:(NSString *)templateType;

- (BOOL)isTesting;
- (void)setTesting:(BOOL)testing;
- (NSString *) templateName;
- (NSString *) templateType;

@end