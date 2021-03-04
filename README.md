![galeria-selphid-logo](https://user-images.githubusercontent.com/1539469/83532587-bd1a2380-a4ee-11ea-860d-8152d7680175.png)

# Selphid widget for iOS
Safe digital onboarding solution with the best real time OCR in the market with facial liveness test.

![selphid](https://user-images.githubusercontent.com/1539469/83533899-72011000-a4f0-11ea-8259-8a2882e3c7aa.gif)

# Table of contents
* [Requirements](##Requirements)
* [Quick Start Guide](##Quick-Start-Guide)
* [Programming Implementation](##Programming-Implementation)


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

## Programming Implementation

In order to implement SelphID Widget in your project follow the next steps.

1. Reference the header file.

Swift

```Swift
import FPhiSelphIDWidgetiOS
```


Objective-C

```Objective-C
#import <FPhiSelphIDWidgetiOS/FPhiSelphIDWidgetiOS.h>
```

2. Invoke SelphID Widget.

SelphID Widget has to be invoked using a Viewcontroller. Next code snippet shows how to implement a method to invoke the SelphID Widget.

**Be aware SelphID Widget needs a license to execute correctly, otherwise will throw an error indicating invalid license**

Swift

```Swift 
func showDocumentWidget() {
        // Get path of resource
        
        guard let resource = Bundle.main.path(forResource: "fphi-selphid-widget-resources-selphid-1.0", ofType: "zip") else { return }

        // Get path of license
        guard let path = Bundle.main.path(forResource: "license", ofType: "lic") else { return }
        guard let license = try? String(contentsOfFile: path, encoding: .utf8) else { return }

       
        do {
           try selphIDWidget = FPhiSelphIDWidget(frontCameraIfAvailable: true, resources: resource, delegate: self, license: license)
        } catch {
           //Catch possible invokation error here
        }
        
        // Checking the correct creation of the widget
        guard let widget = selphIDWidget else { return }

        widget.scanMode = .SMSearch

        // If you want to get a front and back image at the same time
        widget.wizardMode = true

        // Show capture image before snap
        widget.showAfterCapture = true

        // If you want to obtain the data in a more accurate way enter the locale in the specificData property
        widget.specificData = documentModel

        widget.scanType = .DTIDCard

        // Start widget extraction
        widget.startExtraction()

        // Show widget
        present(widget, animated: true)
    }
  ```
  
  For data extraction, SelphID Widget Delegate, FPhiSelphIDWidgetProtocol, has to be conformed:
  
  ```Swift
  extension ViewController: FPhiSelphIDWidgetProtocol {
    /*
     This event is launched when the document capture is complete

     Returns the possible types of results extracted from the OCR extraction.

     Note: Not is recommended to take this data out of the terminal without encryption.

     Capture format
     - Standard: Cropped image from points of interest, to avoid the presence of visual noise. Ideal to show the user. Ex: frontDocument
     - Raw: Original image. Ideal to send to the server and to deal with it. Ex: rawFrontDocument

     Security
     - Plain: They are raw data without applying any encryption layer. It is ideal to show the user. Ex: frontDocument
     - Token: Apply an encryption layer to the data sent. Which is possible to decrypt from the SDK on the server. Ex: tokenFrontDocument

     Side
     - Front: Document front image. Ex: frontDocument
     - Back: Document back image. Ex: backDocument
     - Face: Document facial image. Ex: faceImage
     */

    func captureFinished() {
        // Retrieve data captured from widget
        guard let results = selphIDWidget?.results else { return }

        // Retrieve frontal document image captured from widget
        if let front = results.frontDocument {
            print(front)
        }

        // Retrieve back document image captured from widget
        if let back = results.backDocument {
            print(back)
        }

        // Retrieve face document image captured from widget
        if let face = results.faceImage {
            
            print(face)
        }

        /*
         Returns the possible types of results extracted from the OCR extraction.

         - ocrResults: Returns an unencrypted key value dictionary. Suitable to show in case of flow that contemplates it.
         - tokenOCR: Returns an encrypted key value dictionary. Suitable to send to the server and decrypt it there.
         */
        if let data = results.ocrResults as? [String: String] {
            /*
             This serves to update the list that shows the extracted data.
             It has nothing to do with the logic of the widget, it is only demonstrative.
             */
           print(data)
        }
    }

    // This event is launched when the time to recognize a document has been exceeded
    func captureTimeout() {

    }

    // This event is launched when the user has canceled the capture of the document from the widget interface
    func captureCancelled() {

    }

    // This event is launched when the widget has suffered an error during capture
    func captureFailed(_ error: Error!) {

    }
}
```
 
 Objective-C
 
 ``` Objective-C
 -(void)showDocumentWidget {
   NSLog(@"Widget - Capture Document Front");

    NSString *license = [self readLicense:LICENSE_PATH];

    NSError *error = nil;
    NSBundle *bundle = [NSBundle bundleForClass:[FrontViewController class]];
    _selphidWidget = [[FPhiSelphIDWidget alloc] initWithFrontCameraIfAvailable:true
                                                                     resources:[bundle pathForResource:RESOURCES_PATH ofType:@"zip"]
                                                                      delegate:self
                                                                       license:license
                                                                         error:&error];

    if (error != nil) {
        switch (error.code) {
            case FWMEUnknown:
                NSLog(@"Widget - construction error. Unknown error");
                break;
            case FWMECameraPermission:
                NSLog(@"Widget - construction error. Camera permission denied");
                break;
        }
        return;
    }

    _selphidWidget.scanSide = DSFront;
    _selphidWidget.scanMode = SMSearch;

    // If you want to obtain the data in a more accurate way enter the locale in the specificData property
    NSString *locale = @"ES";
    _selphidWidget.specificData = [NSString stringWithFormat:@"%@|<ALL>", locale];

    // If you want to get a front and back image at the same time
    _selphidWidget.wizardMode = false;

    _selphidWidget.showAfterCapture = true;

    if (_selphidWidget.wizardMode) self.previousData = nil;
    _selphidWidget.tokenPreviousCaptureData = self.previousData;

    [_selphidWidget StartExtraction];

    [self presentViewController:_selphidWidget animated:true completion:nil];
 }
 
 ```
 For data extraction, SelphID Widget Delegate, FPhiSelphIDWidgetProtocol, has to be conformed:
 
 ``` Objective-C
 #pragma Widget delegate
/**
 Invoked when the extraction process is finished.
 - Mandatory method
 */
- (void)CaptureFinished {
    NSLog(@"Widget - Extraction finished");

    if (_selphidWidget.wizardMode)
        self.previousData = nil;
    else
        self.previousData = _selphidWidget.results.tokenOCR;

    _frontImageView.image = _selphidWidget.results.frontDocument;
    _nextButton.enabled = true;
}

/**
 Invoked when the extraction process fail.
 - Optional method
 */
- (void)CaptureFailed:(NSError *)error {
    NSLog(@"Widget - Extraction failed");
}

/**
 Invoked when extraction process is aborted by timeout.
 - Optional method
 */
- (void)CaptureTimeout {
    NSLog(@"Widget - Extraction timeout");
}

/**
 Invoked when extraction process is cancelled by user.
 - Optional method
 */
- (void)CaptureCancelled {
    NSLog(@"Widget - Extraction cancelled");
}


 
