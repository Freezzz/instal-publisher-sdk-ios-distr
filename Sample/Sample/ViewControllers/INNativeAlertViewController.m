//
//  INNativeAlertViewController.m
//  InstalSDKSample
//
//  Created by Insal.com on 17/12/14.
//  Copyright (c) 2014 com.instal All rights reserved.
//

#import "INNativeAlertViewController.h"
#import "INAlertAd.h"
#import "INNativeAdDelegate.h"

@interface INNativeAlertViewController () <INAlertAdDelegate>
@property (weak, nonatomic) IBOutlet UIButton *presentButton;

@property (weak, nonatomic) IBOutlet UILabel *bannerStatusLabel;

@property (retain, nonatomic) INAlertAd * alertAd;
- (IBAction)onRefreshAdButton:(id)sender;
@end

@implementation INNativeAlertViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.alertAd = [[INAlertAd alloc] initWithAdUnitId:@"506"];
    self.alertAd.delegate = self;
}

#pragma mark - IBActions

- (IBAction)onPresentButton:(id)sender {
    if (self.alertAd.ready) {
        [self.alertAd showAd];
    } else {
        [self.bannerStatusLabel setText:@"Loading alert..."];
        [self.alertAd loadAd];
        self.presentButton.enabled = NO;
    }
    
}

- (IBAction)onRefreshAdButton:(id)sender {
    [self.alertAd loadAd];
    [self.bannerStatusLabel setText:@"Refreshing alert..."];
    self.presentButton.enabled = NO;
}

#pragma mark - INAlertAdDelegate

- (UIViewController *)viewControllerForPresentingModalView {
    return self;
}

- (void)alertDidLoadAd:(INAlertAd *)alert {
    [self.bannerStatusLabel setText:@"Alert loaded"];
    self.presentButton.enabled = YES;
    [self.alertAd showAd];
}

- (void)alertDidFailToLoadAd:(INAlertAd *)alert {
    [self.bannerStatusLabel setText:@"Failed loading Alert"];
    self.presentButton.enabled = NO;
}

@end
