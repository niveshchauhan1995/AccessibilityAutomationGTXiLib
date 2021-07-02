//
//  AccessibilitySampleGTXTests.swift
//  AccessibilitySampleGTXTests
//
//  Created by Chauhan, Nivesh(AWF) on 28/06/21.
//

import XCTest
import GTXiLib

@testable import AccessibilitySampleGTX

class AccessibilitySampleGTXTests: XCTestCase {
  
  override class func setUp() {
    super.setUp()
    let checksToBeInstalled: [GTXChecking] = GTXChecksCollection.allGTXChecks()
    let tmp = GTXTestSuite.init(allTestsIn: self)
    GTXiLib.install(on: tmp ?? GTXTestSuite(), checks: checksToBeInstalled, elementExcludeLists: [])
  }
  
  override func setUpWithError() throws {
    // Put setup code here. This method is called before the invocation of each test method in the class.
  }
  
  func testController() {
    
  }
  
  func testView() {
    
  }
  
  override func tearDown() {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    
  }
}

// These error will print in console when we run this sut


//One or more elements FAILED the accessibility checks:
//  <UILabel: 0x7fbf11e13df0; frame = (20 48; 374 162.5); text = 'Lorem Ipsum is simply dum...'; opaque = NO; autoresize = RM+BM; userInteractionEnabled = NO; layer = <_UILabelLayer: 0x6000009f13b0>>
//    + Check "Supports Dynamic Type" failed, This element is a text displaying element, but adjustsFontForContentSizeCategory is NO. Set adjustsFontForContentSizeCategory to YES to automatically scale with Dynamic Type.
//  <UIButton: 0x7fbf11e15e90; frame = (20 230.5; 374 30); opaque = NO; autoresize = RM+BM; layer = <CALayer: 0x600002a81fa0>>
//    + Check "Accessibility label" failed, This element doesn’t have an accessibility label. All accessibility elements must have accessibility labels.
//    + Check "Touch target size" failed, This element has a small touch target. All tappable elements must have a minimum touch target size of 44 by 44 points.%@ The element does not respond to touches in the given range using pointInside:withEvent:.
