//
//  AccessibilitySampleGTXUITests.swift
//  AccessibilitySampleGTXUITests
//
//  Created by Chauhan, Nivesh(AWF) on 28/06/21.
//

import XCTest
import GTXiLib

@testable import AccessibilitySampleGTX


class AccessibilitySampleGTXUITests: XCTestCase {

    override func setUpWithError() throws {
        // Put setup code here. This method is called before the invocation of each test method in the class.
        continueAfterFailure = false

        // In UI tests it’s important to set the initial state - such as interface orientation - required for your tests before they run. The setUp method is a good place to do this.
    }
  
  override class func setUp() {
    super.setUp()
    let checksToBeInstalled: [GTXChecking] = GTXChecksCollection.allGTXChecks()
    let tmp = GTXTestSuite.init(allTestsIn: self)
    GTXiLib.install(on: tmp ?? GTXTestSuite(), checks: checksToBeInstalled, elementExcludeLists: [])
  }

    override func tearDownWithError() throws {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
    }

    func testExample() throws {
        // UI tests must launch the application that they test.
        let app = XCUIApplication()
        app.launch()
        // Use recording to get started writing UI tests.
        // Use XCTAssert and related functions to verify your tests produce the correct results.
    }

    func testLaunchPerformance() throws {
        if #available(macOS 10.15, iOS 13.0, tvOS 13.0, *) {
            // This measures how long it takes to launch your application.
//            measure(metrics: [XCTApplicationLaunchMetric()]) {
//                XCUIApplication().launch()
//            }
        }
    }
}
