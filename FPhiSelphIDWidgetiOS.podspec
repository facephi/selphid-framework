#
#  Be sure to run `pod spec lint FPhiSelphIDWidgetiOS.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  spec.name         = "FPhiSelphIDWidgetiOS"
  spec.version      = "0.0.4"
  spec.summary      = "A short description of FPhiSelphIDWidgetiOS."
  spec.ios.deployment_target  = "10.0"
  spec.static_framework = true

  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  spec.description  = <<-DESC
  An extended description of MyFramework project.
  DESC
  spec.homepage     = "http://your.homepage/here"
  spec.license = { :type => 'Copyright', :text => <<-LICENSE
                 Copyright 2020
                 Permission is granted to...
                LICENSE
              }

  spec.author             = { "Carlos Fernandez" => "cfernandez@facephi.com" }
  spec.source       = { :git => "https://github.com/facephi/selphid-framework.git", :tag => "0.0.4" }

  spec.ios.vendored_frameworks = "FPhiSelphIDWidgetiOS.framework"
  spec.public_header_files = "FPhiSelphIDWidgetiOS.framework/Headers/*.h"
  spec.source_files = "FPhiSelphIDWidgetiOS.framework/Headers/*.h"
  spec.dependency "Firebase/Analytics" , "6.22.0"
  spec.dependency "Firebase/MLVision"
  spec.dependency "Firebase/MLVisionTextModel"



end
