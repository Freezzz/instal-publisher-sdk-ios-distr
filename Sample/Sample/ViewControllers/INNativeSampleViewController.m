//
//  INNativeSampleViewController.m
//  InstalSDKSample
//
//  Created by Insal.com on 18/11/14.
//  Copyright (c) 2014 com.instal All rights reserved.
//

#import "INNativeSampleViewController.h"
#import "INNativeAdRequest.h"
#import "INNativeAd.h"
#import "INNativeAdDelegate.h"

@interface INNativeSampleViewController () <INNativeAdDelegate>
@property (nonatomic, strong) INNativeAd *nativeAd;

@property (weak, nonatomic) IBOutlet UILabel *titleLable;
@property (weak, nonatomic) IBOutlet UIImageView *iconImageView;
@property (unsafe_unretained, nonatomic) IBOutlet UIView *bannerContainer;

- (IBAction)onRefreshAdButton:(id)sender;
- (IBAction)onCtaButton:(id)sender;
@end

@implementation INNativeSampleViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self loadAd];
    self.bannerContainer.hidden = YES;
}

- (void)loadAd{
    INNativeAdRequest *adRequest = [INNativeAdRequest requestWithAdUnitIdentifier:@"506"];
    
    [adRequest startWithCompletionHandler:^(INNativeAdRequest *request, INNativeAd *response, NSError *error) {
        if (error) {
            // Handle error.
            NSLog(@"%@", error);
        } else {
            self.bannerContainer.hidden = NO;
            self.nativeAd = response;
            self.nativeAd.delegate = self;
            [self displayAd];
        }
    }];
}

- (void)displayAd
{
    [self.nativeAd loadTitleIntoLabel:self.titleLable];
    [self.nativeAd loadIconIntoImageView:self.iconImageView];
    [self.nativeAd trackImpression];
}

#pragma mark - IBActions

- (IBAction)onRefreshAdButton:(id)sender {
    [self loadAd];
}

- (IBAction)onCtaButton:(id)sender {
    [self.nativeAd displayContentWithCompletion:^(BOOL success, NSError *error) {
        if (success) {
            NSLog(@"Completed display of ad's default action URL");
        } else {
            NSLog(@"================> %@", error);
        }
    }];
}


#pragma mark - INNativeAdDelegate
- (UIViewController *)viewControllerForPresentingModalView {
    return self;
}


@end
