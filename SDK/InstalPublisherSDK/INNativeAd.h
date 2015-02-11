//
//  INNativeAd.h
//  Copyright (c) 2013 Instal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol INNativeAdAdapter;
@protocol INNativeAdDelegate;
@class INAdConfiguration;

/**
 * The `INNativeAd` class is used to render and manage events for a native advertisement. The
 * class provides methods for accessing native ad properties returned by the server, as well as
 * convenience methods for URL navigation and metrics-gathering.
 */

@interface INNativeAd : NSObject

/** @name Ad Resources */

/**
 * The delegate of the `INNativeAd` object.
 */
@property (nonatomic, weak) id<INNativeAdDelegate> delegate;

/**
 * The default click-through URL for the ad.
 *
 * May be nil.
 */
@property (nonatomic, readonly) NSURL *defaultActionURL;

/**
 * Title for the ad.
 */
@property (nonatomic, readonly) NSString *title;

/**
 * Description text for the ad.
 */
@property (nonatomic, readonly) NSString *text;

/**
 * Call to action for the ad. Typicaly rapresented on a button.
 */
@property (nonatomic, readonly) NSString *ctaText;

/**
 * Main icon for the ad.
 */
@property (nonatomic, readonly) NSURL *iconURL;

/**
 * NSArray of NSString containg screenshot URLs 
 */
@property (nonatomic, readonly) NSArray *screenshots;

/**
 * Star rating for the ad.
 *
 * This is a float value between 0 and 5.
 *
 * May be nil.
 */
@property (nonatomic, readonly) NSNumber *starRating;


/** @name Preparing Ad Content for Display */

/**
 * Instructs the ad object to configure the provided view with ad content.
 *
 * The provided view should implement the `MPNativeAdRendering` protocol to correctly display the ad
 * content.
 *
 * When this method is called, an impression will automatically be recorded at the appropriate time,
 * so there is no need to additionally invoke -trackImpression.
 *
 * @param view A view that will contain the ad content.
 * @see MPNativeAdRendering
 */
- (void)prepareForDisplayInView:(UIView *)view;

/** @name Handling Ad Interactions */

/**
 * Records an impression event.
 *
 * When -prepareForDisplayInView is called, -trackImpression will automatically be invoked at the
 * appropriate time, so there is no need to additionally invoke -trackImpression.
 */
- (void)trackImpression;

/**
 * Records a click event.
 *
 * When -displaycontentForURL:rootViewController:completion: is called, a click event will
 * automatically be recorded, so there is no need to additionally invoke -trackClick.
 */
- (void)trackClick;

/**
 * Opens a resource defined by the ad using an appropriate mechanism (typically, an in-application
 * modal web browser or a modal App Store controller).
 *
 * @param completionBlock The block to be executed when the action defined by the URL has been
 * completed, returning control to your application.
 *
 * You should call this method when you detect that a user has tapped on the ad (i.e. via button,
 * table view selection, or gesture recognizer).
 *
 * When this method is called, a click event will automatically be recorded, so there is no
 * need to additionally invoke -trackClick.
 */
- (void)displayContentWithCompletion:(void (^)(BOOL success, NSError *error))completionBlock;

/**
 * Opens a URL using an appropriate mechanism (typically, an in-application modal web browser or a
 * modal App Store controller).
 *
 * @param URL The URL to be opened.
 * @param completionBlock The block to be executed when the action defined by the URL has been
 * completed, returning control to your application.
 *
 * You should call this method when you detect that a user has tapped on the ad (i.e. via button,
 * table view selection, or gesture recognizer).
 *
 * When this method is called, a click event will automatically be recorded, so there is no
 * need to additionally invoke -trackClick.
 */
- (void)displayContentForURL:(NSURL *)URL completion:(void (^)(BOOL success, NSError *error))completionBlock;


/** @name Loading Specific Ad Resources into Views */

/**
 * Asynchronously loads the ad object's icon image into the provided image view.
 *
 * @param imageView An image view.
 */
- (void)loadIconIntoImageView:(UIImageView *)imageView;

/**
 * Asynchronously loads the ad object's main image into the provided image view.
 *
 * @param imageView An image view.
 */
- (void)loadImageIntoImageView:(UIImageView *)imageView;

/**
 * Loads the ad object's title into the provided label.
 *
 * @param label A label.
 */
- (void)loadTitleIntoLabel:(UILabel *)label;

/**
 * Loads the ad object's main text into the provided label.
 *
 * @param label A label.
 */
- (void)loadTextIntoLabel:(UILabel *)label;

/**
 * Loads the ad object's main text into the provided textView.
 *
 * @param label A label.
 */
- (void)loadTextIntoTextView:(UITextView *)textView;

/**
 * Loads the ad object's call-to-action text into the provided label.
 *
 * @param label A label.
 */
- (void)loadCallToActionTextIntoLabel:(UILabel *)label;

/**
 * Loads the ad object's call-to-action text into the provided button.
 *
 * @param button A button.
 */
- (void)loadCallToActionTextIntoButton:(UIButton *)button;

/**
 * Asynchronously loads the image referenced by imageURL into the provided image view.
 *
 * @param imageURL A URL identifying an image resource.
 * @param imageView An image view.
 */
- (void)loadImageForURL:(NSURL *)imageURL intoImageView:(UIImageView *)imageView;

@end
