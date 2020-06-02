
![galeria-selphid-logo](https://user-images.githubusercontent.com/1539469/83532587-bd1a2380-a4ee-11ea-860d-8152d7680175.png)

# Selphid widget for iOS
Safe digital onboarding solution with the best real time OCR in the market with facial liveness test.

![selphid](https://user-images.githubusercontent.com/1539469/83533899-72011000-a4f0-11ea-8259-8a2882e3c7aa.gif)

# Table of contents
* [Requirements](##Requirements)
* [Quick Start Guide](##Quick-Start-Guide)


## Requirements

SelphID widget is distributed in XCFramerwork format together with a resource bundle distributed in a Zip file. The framework can be 
deployed in iOS 10.0 or later.

## Quick Start Guide

The fastest way to integrate SelphID widget is using CocoaPods.

In order to use Cocoapods, you need to create a podfile in your project directory: 


`$ touch podfile`


Add the following conten to your podfile:


```ruby
platform :ios, '10.0'
target 'Your-App-Target' do
  pod 'FPhiSelphIDWidgetiOS'
end
```

Install the widget and its dependencies in your project running:

`$ pod install`


Open the new generated Xcode  workspace (.xcworkspace).
