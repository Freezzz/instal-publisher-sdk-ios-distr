//
//  INTableNativeViewController.m
//  Sample
//
//  Created by Insal.com on 10/02/15.
//  Copyright (c) 2015 com.instal. All rights reserved.
//

#import "INTableNativeViewController.h"
#import "INTableViewAdPlacer.h"
#import "ISInstalAdCell.h"
#import "INClientAdPositioning.h"

@interface INTableNativeViewController () <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong) INTableViewAdPlacer *placer;
@property (nonatomic, strong) NSMutableArray *contentArray;

@property (weak, nonatomic) IBOutlet UITableView *tableView;
@end

@implementation INTableNativeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.contentArray = [[NSMutableArray alloc] initWithArray:[UIFont familyNames]];
    [self.tableView reloadData];
    
    [self setupAdPlacer];
}


#pragma mark - AdPlacer

- (void)setupAdPlacer
{
    // Create a table view ad placer that uses server-side ad positioning.
    INClientAdPositioning * positioning = [[INClientAdPositioning alloc] init];
    positioning.repeatingInterval = 5;
    
    self.placer = [INTableViewAdPlacer placerWithTableView:self.tableView
                                            viewController:self
                                             adPositioning:positioning
                                   defaultAdRenderingClass:[ISInstalAdCell class]];
    
    [self.placer loadAdsForAdUnitID:@"506"];
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    /*
     * IMPORTANT: add the in_ prefix to deselectRowAtIndexPath:animated:.
     */
    [tableView in_deselectRowAtIndexPath:indexPath animated:YES];
}


#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.contentArray.count;
}

NSString *const kDefaultCellIdentifier = @"DefaultCellIdentifier";
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView in_dequeueReusableCellWithIdentifier:kDefaultCellIdentifier forIndexPath:indexPath];
    cell.textLabel.text = self.contentArray[indexPath.row];
    return cell;
}
@end
