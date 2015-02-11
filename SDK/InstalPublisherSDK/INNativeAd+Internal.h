//
//  INNativeAd+Internal.h
//  Copyright (c) 2014 Instal. All rights reserved.
//

#import "INNativeAd.h"

@interface INNativeAd (Internal)

@property (nonatomic, readonly) NSDate *creationDate;

- (NSTimeInterval)requiredSecondsForImpression;
- (void)willAttachToView:(UIView *)view;
- (void)setVisible:(BOOL)visible;
- (NSMutableSet *)impressionTrackers;
- (NSURL *)engagementTrackingURL;

- (void)setEngagementTrackingURL:(NSURL *)engagementTrackingURL;
- (instancetype)initWithAdAdapter:(id<INNativeAdAdapter>)adAdapter;
@end
