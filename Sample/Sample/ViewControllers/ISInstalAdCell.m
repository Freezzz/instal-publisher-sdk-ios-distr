//
//  ISInstalAdCell.m
//  Sample
//
//  Created by Insal.com on 10/02/15.
//  Copyright (c) 2015 com.instal. All rights reserved.
//

#import "ISInstalAdCell.h"
#import "INNativeAd.h"

@interface ISInstalAdCell ()
@property (weak, nonatomic) IBOutlet UIImageView *adIcon;
@property (weak, nonatomic) IBOutlet UILabel *adTitle;
@property (weak, nonatomic) IBOutlet UILabel *adSubtitle;
@end

@implementation ISInstalAdCell

#pragma mark - INNativeAdRendering
- (void)layoutAdAssets:(INNativeAd *)adObject {
    [adObject loadTitleIntoLabel:self.adTitle];
    [adObject loadTextIntoLabel:self.adSubtitle];
    [adObject loadIconIntoImageView:self.adIcon];
}

+ (UINib *)nibForAd {
    return [UINib nibWithNibName:@"ISInstalAdCell" bundle:nil];
}


+ (CGSize)sizeWithMaximumWidth:(CGFloat)maximumWidth
{
    return CGSizeMake(maximumWidth, 60);
}

@end
