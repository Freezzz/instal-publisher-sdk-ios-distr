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
