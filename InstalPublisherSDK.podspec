Pod::Spec.new do |s|
  s.name         = "InstalPublisherSDK"
  s.version      = "0.0.3"
  s.summary      = "Pulisher SDK for Instal.com"

  s.description  = <<-DESC
                   Publisher SDK for Instal.com that allows you to integrate Ads in your iOS application
                   DESC

  s.homepage     = "https://instal.com/"
  s.license      = { :type => "MIT", :file => "LICENSE.md" }

  s.author             = { "Instal.com" => "hello@instal.com" }
  s.social_media_url   = "https://twitter.com/instal_now"

  s.platform     = :ios, "6.0"
  s.source       = { :git => "https://bitbucket.org/tbdsrl/instal-publisher-sdk-ios-distr.git", :tag => "0.0.3" }

  s.source_files  = 'SDK', 'SDK/**/*.{h,m}'
  s.vendored_library = 'SDK/libInstalPublisherSDK.a'

  s.frameworks = 'QuartzCore', 'CoreGraphics', 'EventKit',  'EventKitUI', 'StoreKit', 'MediaPlayer', 'AdSupport'

  s.public_header_files = "SDK/**/*.h"

  s.resource = "SDK/InstalPublisherSDKResources.bundle"

  s.requires_arc = true

end
