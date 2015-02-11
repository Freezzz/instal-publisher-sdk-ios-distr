//
//  INInterstitialSampleViewController.m
//  InstalSDKSample
//
//  Created by Insal.com on 18/11/14.
//  Copyright (c) 2014 com.instal All rights reserved.
//

#import "INInterstitialSampleViewController.h"

#import "INInterstitialAdController.h"


@interface INInterstitialSampleViewController () <INInterstitialAdControllerDelegate>

@property (nonatomic, retain) INInterstitialAdController *interstitial;
@property (weak, nonatomic) IBOutlet UIButton *presentButton;
@property (weak, nonatomic) IBOutlet UILabel *bannerStatusLabel;

- (IBAction)onRefreshAdButton:(id)sender;
@end

@implementation INInterstitialSampleViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.interstitial = [INInterstitialAdController
                         interstitialAdControllerForAdUnitId:@"505"];
    self.interstitial.delegate = self;
}

#pragma mark - IBActions

- (IBAction)onPresentButton:(id)sender {
    if (self.interstitial.ready) {
        [self.interstitial showFromViewController:self];
    } else {
        [self.bannerStatusLabel setText:@"Loading interstitial..."];
        [self.interstitial loadAd];
        self.presentButton.enabled = NO;
    }
    
}

- (IBAction)onRefreshAdButton:(id)sender {
    [self.interstitial setAdUnitId:@"505"];
    [self.interstitial loadAd];
    [self.bannerStatusLabel setText:@"Refreshing banner..."];
    self.presentButton.enabled = NO;
}

#pragma mark - INInterstitialAdControllerDelegate

- (void)interstitialDidLoadAd:(INInterstitialAdController *)interstitial {
    [self.bannerStatusLabel setText:@"Banner loaded"];
    self.presentButton.enabled = YES;
    [self.interstitial showFromViewController:self];
}

- (void)interstitialDidFailToLoadAd:(INInterstitialAdController *)interstitial{
    [self.bannerStatusLabel setText:@"Failed loading banner"];
    self.presentButton.enabled = NO;
}


@end
