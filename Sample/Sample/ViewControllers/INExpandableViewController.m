//
//  INExpandableViewController.m
//  InstalSDKSample
//
//  Created by Insal.com on 17/11/14.
//  Copyright (c) 2014 com.instal All rights reserved.
//

#import "INExpandableViewController.h"
#import "INAdView.h"

@interface INExpandableViewController () <INAdViewDelegate>

@property (nonatomic) INAdView *adView;
@property (weak, nonatomic) IBOutlet UILabel *bannerStatusLabel;
@property (weak, nonatomic) IBOutlet UIView *bannerContainer;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *bannerHeightConstraint;

- (IBAction)onRefreshAdButton:(id)sender;

@end

@implementation INExpandableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.adView = [[INAdView alloc] initWithAdUnitId:@"504"];
    self.adView.delegate = self;
    self.adView.translatesAutoresizingMaskIntoConstraints = NO;
    
    [self.bannerContainer addSubview:self.adView];
    
    NSDictionary *views = NSDictionaryOfVariableBindings(_adView);
    [self.bannerContainer addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-0-[_adView]-0-|" options:0 metrics:nil views:views]];
    [self.bannerContainer addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-0-[_adView]-0-|" options:0 metrics:nil views:views]];
    
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        self.bannerHeightConstraint.constant = 90;
    } else {
        self.bannerHeightConstraint.constant = 50;
    }
    
    [self.adView loadAd];
    [self.bannerStatusLabel setText:@"Loading banner..."];
}


#pragma mark - INAdViewDelegate
- (UIViewController *)viewControllerForPresentingModalView {
    return self;
}

- (IBAction)onRefreshAdButton:(id)sender {
    [self.adView forceRefreshAd];
    [self.bannerStatusLabel setText:@"Refreshing banner..."];
}

- (void)adViewDidLoadAd:(INAdView *)view {
    [self.bannerStatusLabel setText:@"Banner loaded"];
}

- (void)adViewDidFailToLoadAd:(INAdView *)view {
    [self.bannerStatusLabel setText:@"Failed loading banner"];
}

- (void)willPresentModalViewForAd:(INAdView *)view {
    [self.bannerStatusLabel setText:@"Banner expanded"];
}


- (void)didDismissModalViewForAd:(INAdView *)view {
    [self.bannerStatusLabel setText:@"Banner expantion closed"];
}

@end
