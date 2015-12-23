//
//  INDiscoveryWebView.h
//  InstalSDKSample
//
//  Created by Ivan Litsvinenka on 17/12/15.
//  Copyright © 2015 net.freezzz. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol INDiscoveryWebViewDelegate;

/**
 * The INDiscoveryWebView class provides a view that can display multiple application advertisements.
 */
@interface INDiscoveryWebView : UIView

/**
 * The delegate (`INDiscoveryWebView`) of the ad view.
 *
 * @warning **Important**: Before releasing an instance of `INDiscoveryWebView`, you must set its delegate
 * property to `nil`.
 */
@property (nonatomic, weak) id<INDiscoveryWebViewDelegate> delegate;

/**
 * Requests a new ad from the Instal ad server.
 * @param layoutID layout id you can find in your Instal panel
 */
- (void)loadWithLayoutID:(NSString *)layoutID;
@end

////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma mark -

/**
 * The delegate of an `INDiscoveryWebViewDelegate`
 * Optional methods of this protocol allow the delegate to be notified of banner success or
 * failure.
 */
@protocol INDiscoveryWebViewDelegate <NSObject>
@optional
- (void)dicoveryWebViewDidLoad:(INDiscoveryWebView *)discoveryWebView;
- (void)dicoveryWebViewFailedToLoad:(INDiscoveryWebView *)discoveryWebView error:(NSError*)error;
@end