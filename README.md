# Getting started

This guide shows how to include the Instal publisher SDK into your iOS application.


## Using CocoaPods

Our sdk is distribuited with [CocoaPods](http://coccoapods.org)

    pod 'InstalPublisherSDK', :git => 'https://bitbucket.org/freezzz/instal-publisher-sdk-ios-distr.git'



## Manual integration

1. Download latest [SDK](http://instal.com/sdk/)
2. Drag downloaded folder in your project
3. Include following frameworks in your poject:
    * CoreGraphics.framework
    * EventKit.framework
    * EventKitUI.framework
    * QuartzCore.framework
    * StoreKit.framework
    * MediaPlayer.framework
    * AdSupport.framework
4. In your target build settings in Other Linker Flags add "-ObjC"

# Banner Integration

Banner ads usually appears at the top or bottom of your app’s screen. Adding one to your app takes just a few lines of code.

## Basic integration

Adding a banner to your application takes only a few, easy steps:

1. In your view controller's header file:
	* Import the `INAdView.h` header file and declare an `INAdView *adView` property.
 	* Declare that your view controller implements the `INAdViewDelegate` protocol.
2. In your view controller's implementation file, instantiate an INAdView, passing in your ad unit ID. This is typically done in `-viewDidLoad`.
3. Register your view controller as the `adView`'s delegate.
4. Implement the `-viewControllerForPresentingModalView` `INAdViewDelegate` method. The `adView` will use the view controller returned by this method to present modals when tapped. Typically your controller can simply return self.
5. Finally, load an ad by sending adView the `-loadAd` message.

## Sample Code
```objective-c
- (void)viewDidLoad {
    [super viewDidLoad];
	
    self.adView = [[INAdView alloc] initWithAdUnitId:@"YOUR_ADUNIT_ID"];
    self.adView.delegate = self;    
    [self.bannerContainer addSubview:self.adView];
    
    [self.adView loadAd];
}
```

Implement non optional INAdViewDelegate protocol

```objective-c
#pragma mark - <INAdViewDelegate>
- (UIViewController *)viewControllerForPresentingModalView {
    return self;
}
```
## Delegates

Detecting When a Banner Ad is Loaded 

```objective-c
- (void)adViewDidLoadAd:(INAdView *)view;
- (void)adViewDidFailToLoadAd:(INAdView *)view;
```

Detecting When a User Interacts With the Ad View */

```objective-c
- (void)willPresentModalViewForAd:(INAdView *)view;
- (void)didDismissModalViewForAd:(INAdView *)view;
- (void)willLeaveApplicationFromAd:(INAdView *)view;
```

A complete ViewController is available in [sample app](https://bitbucket.org/tbdsrl/instal-publisher-sdk-ios-distr/src/master/Sample/Sample/ViewControllers/INBannerAdViewController.m).


# Interstitial Integration

Interstitial ads provide full screen experiences, you can preload an interstitial ad and show it during the normal flow in your app.
You can use the InstalInterstitial object and its associated listeners to fetch and display interstitial ads in your app.

## Basic integration
1. In your view controller's header file:
	* Import the `INInterstitialAdController.h` header file and declare an `INInterstitialAdController *interstitial` property.
	* Declare that your view controller implements the `INInterstitialAdControllerDelegate` protocol.
2. In your view controller's implementation file, instantiate an `INInterstitialAdController` using the class convenience method `+interstitialAdControllerForAdUnitId:`, passing in your ad unit ID.
3. Register your view controller as the `interstitial`'s delegate. (e.g. `self.interstitial.delegate = self;`)
4. Pre-fetch the interstitial ad by calling `-loadAd` on the `interstitial`.
5. When you'd like to display the ad, check the ad's ready property.
6. If the ad is ready to be shown, call `-showFromViewController:` on the `interstitial`, passing in your view controller.


## Sample Code

```objective-c
// MyViewController.h

#import "INInterstitialAdController.h"

@interface MyViewController : UIViewController <INInterstitialAdControllerDelegate>
@property (nonatomic, retain) MPInterstitialAdController *interstitial;
@end
```

```objective-c
// MyViewController.h
#import "MyViewController.h"
@implementation MyViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
	self.interstitial = [INInterstitialAdController
                         interstitialAdControllerForAdUnitId:@"YOUR_ADUNIT_ID"];
    self.interstitial.delegate = self;
    
    [self.interstitial loadAd];
}


// Present the ad only after it is ready.
- (void)levelDidEnd {
    if (self.interstitial.ready){
        [self.interstitial showFromViewController:self];
    } else {
        // The interstitial wasn't ready, so continue as usual.
    }
}
```


## Delegates

You can recieve various delegagates call about interstitial status

Detecting When an Interstitial Ad is Loaded:
```objective-c
- (void)interstitialDidLoadAd:(INInterstitialAdController *)interstitial;
```

```objective-c
- (void)interstitialDidFailToLoadAd:(INInterstitialAdController *)interstitial;
```


Detecting When an Interstitial Ad is Presented

```objective-c
- (void)interstitialWillAppear:(INInterstitialAdController *)interstitial;
- (void)interstitialDidAppear:(INInterstitialAdController *)interstitial;
```


Detecting When an Interstitial Ad is Dismissed

```objective-c
- (void)interstitialWillDisappear:(INInterstitialAdController *)interstitial;
- (void)interstitialDidDisappear:(INInterstitialAdController *)interstitial;
- (void)interstitialDidReceiveTapEvent:(INInterstitialAdController *)interstitial;
```

A complete ViewController is available in [sample app](https://bitbucket.org/tbdsrl/instal-publisher-sdk-ios-distr/src/master/Sample/Sample/ViewControllers/INInterstitialSampleViewController.m?at=master).

# Native Ads integration

Native ads let you easily monetize your app in a way that's consistent with its existing design.
The Instal SDK execute the download and all the tracking automatically, you can just populate your layout with the information managed by the sdk.


## Download and display a native ad

```objective-c
@property (nonatomic, strong) INNativeAd *nativeAd;
```

Create an MPNativeAdRequest object using the `+requestWithAdUnitIdentifier:` method.

```objective-c
- (void)viewDidLoad {
	[super viewDidLoad];
	INNativeAdRequest *adRequest = [INNativeAdRequest requestWithAdUnitIdentifier:@"YOUR_AD_UNIT_ID"];
}
```

Start the request via `-startWithCompletionHandler:`, providing a completion block to handle the results of the request. If the request is successful, the completion block's MPNativeAd parameter will represent an object that contains the ad's assets. The following sections of this guide provide more information on how to access ad assets.

```objective-c
INNativeAdRequest *adRequest = [INNativeAdRequest requestWithAdUnitIdentifier:@"506"];
[adRequest startWithCompletionHandler:^(INNativeAdRequest *request, INNativeAd *response, NSError *error) {
        if (error) {
            // Handle error.
            NSLog(@"%@", error);
        } else {
            // Use the 'response' object to render a native ad.
            self.nativeAd = response;
            self.nativeAd.delegate = self;
            [self displayAd];
        }
    }];
```

## Layout ad view
You can use the following informations to populate ad layout:

  * title
  * promo text
  * call to action text
  * long text
  * icon url
  * list of screenshots (optional)
  
```objective-c
- (void)displayAd
{
    [self.nativeAd loadTitleIntoLabel:self.titleLable];
    [self.nativeAd loadIconIntoImageView:self.iconImageView];
    [self.nativeAd loadCallToActionTextIntoButton:self.ctaButton];
    [self.nativeAd trackImpression];
}
```

## Trigger the ad's default action
When you detect that the user has tapped on an ad (e.g. via gesture recognizer or a button action), trigger the ad's default action by calling the `-displayContentForURL:rootViewController:completionBlock:` method on the corresponding `INNativeAd`.

```objective-c
- (IBAction)onCtaButton:(id)sender {
    [self.nativeAd displayContentWithCompletion:^(BOOL success, NSError *error) {
        if (success) {
            NSLog(@"Completed display of ad's default action URL");
        } else {
            NSLog(@"%@", error);
        }
    }];
}
```

A complete ViewController is available in [sample app](https://bitbucket.org/tbdsrl/instal-publisher-sdk-ios-distr/src/master/Sample/Sample/ViewControllers/INNativeSampleViewController.m).
