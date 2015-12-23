//
//  INDiscoveryWebViewController.m
//  Sample
//
//  Created by Ivan Litsvinenka on 23/12/15.
//  Copyright © 2015 com.instal. All rights reserved.
//

#import "INDiscoveryWebViewController.h"
#import "INDiscoveryWebView.h"

@interface INDiscoveryWebViewController () <INDiscoveryWebViewDelegate>
@property (weak, nonatomic) IBOutlet INDiscoveryWebView *discoveryView;

- (IBAction)onRefreshAdButton:(id)sender;
@end

@implementation INDiscoveryWebViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.discoveryView.delegate = self;
    [self.discoveryView loadWithLayoutID:@"23"];
}

- (IBAction)onRefreshAdButton:(id)sender {
    [self.discoveryView loadWithLayoutID:@"23"];
}


#pragma mark - INDiscoveryWebViewDelegate
- (void)dicoveryWebViewDidLoad:(INDiscoveryWebView *)discoveryWebView {
    NSLog(@"Discovery WebView loaded");
}

- (void)dicoveryWebViewFailedToLoad:(INDiscoveryWebView *)discoveryWebView error:(NSError *)error{
    NSLog(@"Error: %@", error);
}
@end
