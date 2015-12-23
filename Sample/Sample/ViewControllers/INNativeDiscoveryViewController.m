//
//  INNativeDiscoveryViewController.m
//  Sample
//
//  Created by Ivan Litsvinenka on 23/12/15.
//  Copyright © 2015 com.instal. All rights reserved.
//

#import "INNativeDiscoveryViewController.h"

#import "ISInstalAdCell.h"

#import "INNativeDiscoveryRequest.h"
#import "INNativeAd.h"
#import "INNativeAdDelegate.h"

@interface INNativeDiscoveryViewController () <UITableViewDataSource, UITableViewDelegate, INNativeAdDelegate>
@property (strong, nonatomic) NSArray *ads;
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@end

@implementation INNativeDiscoveryViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self.tableView registerNib:[UINib nibWithNibName:@"ISInstalAdCell" bundle:nil] forCellReuseIdentifier:kDefaultAdCellIdentifier];
    [self loadAds];
}

- (void)loadAds {
    // Create new request
    INNativeDiscoveryRequest *request = [INNativeDiscoveryRequest requestWithAdUnitIdentifier:@"23"];
    
    [request startWithCompletionHandler:^(INNativeDiscoveryRequest *request, NSArray *response, NSError *error) {
        if (error) {
            NSLog(@"Error in loading ads: %@", error);
        } else {
            // Set INNativeAdDelegate to self
            for (INNativeAd *ad in response) {
                ad.delegate = self;
            }
            self.ads = response;
            
            [self.tableView reloadData];
        }
    }];
}


#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    INNativeAd *ad = self.ads[indexPath.row];
    [ad displayContentWithCompletion:nil];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 60;
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.ads.count;
}

NSString *const kDefaultAdCellIdentifier = @"ISInstalAdCell";
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    INNativeAd *ad = self.ads[indexPath.row];
    ISInstalAdCell *cell = [tableView dequeueReusableCellWithIdentifier:kDefaultAdCellIdentifier forIndexPath:indexPath];
    [cell layoutAdAssets:ad];
    return cell;
}


#pragma mark - INNativeAdDelegate
- (UIViewController *)viewControllerForPresentingModalView {
    return self;
}
@end
