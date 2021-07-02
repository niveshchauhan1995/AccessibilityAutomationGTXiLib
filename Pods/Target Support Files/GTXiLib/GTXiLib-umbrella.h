#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "GTXAccessibilityTree.h"
#import "GTXAnalytics.h"
#import "GTXAnalyticsUtils.h"
#import "GTXAssertions.h"
#import "GTXCheckBlock.h"
#import "GTXChecking.h"
#import "GTXCheckResult.h"
#import "GTXChecksCollection.h"
#import "GTXCommon.h"
#import "GTXElementReference.h"
#import "GTXElementResultCollection.h"
#import "GTXError.h"
#import "GTXErrorReporter.h"
#import "GTXExcludeListBlock.h"
#import "GTXExcludeListFactory.h"
#import "GTXExcludeListing.h"
#import "GTXHierarchyResultCollection.h"
#import "GTXiLib.h"
#import "GTXiLibCore.h"
#import "GTXImageAndColorUtils.h"
#import "GTXImageRGBAData.h"
#import "GTXLogging.h"
#import "GTXPluginXCTestCase.h"
#import "GTXReport.h"
#import "GTXResult.h"
#import "GTXSwizzler.h"
#import "GTXTestCase.h"
#import "GTXTestEnvironment.h"
#import "GTXTestSuite.h"
#import "GTXToolKit.h"
#import "GTXXCUIApplicationProxy.h"
#import "GTXXCUIElementProxy.h"
#import "GTXXCUIElementQueryProxy.h"
#import "NSError+GTXAdditions.h"
#import "UIColor+GTXAdditions.h"

FOUNDATION_EXPORT double GTXiLibVersionNumber;
FOUNDATION_EXPORT const unsigned char GTXiLibVersionString[];

