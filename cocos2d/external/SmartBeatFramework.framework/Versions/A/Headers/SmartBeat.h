//
//  SmartBeat.h
//  SmartBeat
//
//  Created by FROSK, Inc. on 2013/11/05.
//  Copyright (c) 2013年 FROSK. All rights reserved.
//
/*!
 @header SmartBeat
 The SmartBeat API provides an initilization interface and configuration interface.
 Use these APIs to enable SmartBeat functionality.
 Please be sure to include the following frameworks in your project to use SmartBeat.<br>
 <ul>
 <li>CoreLocation.framework</li>
 <li>SystemConfiguration.framework</li>
 <li>CoreTelephony.framework</li>
 </ul>
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface SmartBeat : NSObject

/*!
 @method startWithApiKey:
 @abstract Create and initilize a new SmartBeat instance.  This method must be called before calling other SmartBeat methods.
 @param apiKey The API key for your application.  You can find your API key on the settings screen of the SmartBeat web console.
 @result Returns the newly initialized SmartBeat object or nil on error.
 */
+ (SmartBeat *) startWithApiKey:(NSString *) apiKey;

/*!
 @method startWithApiKey:
 @abstract Create and initilize a new SmartBeat instance with initial control.  This method must be called before calling other SmartBeat methods.
 @param apiKey The API key for your application.  You can find your API key on the settings screen of the SmartBeat web console.
 @param enabled NO if saving/sending Crash/Exception/Captured image shall be disabled by default.
 @result Returns the newly initialized SmartBeat object or nil on error.
 */
+ (SmartBeat *) startWithApiKey:(NSString *) apiKey withEnabled:(BOOL) enabled;


/*!
 @method shared
 @abstract Get the SmartBeat instance.  Note that you must initilize the SmartBeat instance by calling "startWithApiKey" before calling this method.
 @result Returns the instance of SmartBeat object if it is already initilized or nil if it is not initilized.
 */
+ (SmartBeat *) shared;

/*!
 @method setExtraData:
 @abstract Set extra data set that will be sent with crash data.
 @param extraData Set of keys/values. A string represented by description method is logged.
 */
- (void) setExtraData: (NSDictionary *) extraData;

/*!
 @method logException:
 @abstract Send exception data handled by application code to the SmartBeat server.
 @param exception The exception that is handled by the application.
 */
- (void) logException: (NSException *) exception;

/*!
 @method logException:withExtraData:
 @abstract Send exception data handled by application code with any extra data to SmartBeat server.
 @param exception The exception that is handled by the application.
 @param extraData The extraData set that should be sent to server with exception data. Note that extraData set by "setExtraData" won't be sent.
 */
- (void) logException: (NSException *) exception withExtraData:(NSDictionary *) extraData;

/*!
 @method leaveBreadcrumb:
 @abstract Leave a breadcrumb.  When a crash occurs, the last 16 breadcrumbs to be set will be sent with the crash report.
 @param breadcrumb A string shall be set as a breadcrumb
 */
- (void) leaveBreadcrumb: (NSString *) breadcrumb;

/*!
 @method enableNSLog
 @abstract Enable sending NSLog contents to SmartBeat server with crash reports.  If this option is enabled the content of the system log is sent in the crash report when a crash occurs.
 */
- (void) enableNSLog;

/*!
 @method enableDebugLog
 @abstract Enable SmartBeat debug log.  If this option is enabled the SmartBeat library will print debug entries to NSLog.
 */
- (void) enableDebugLog;

/*!
 @method enableAutoScreenCapture
 @abstract Enable auto screen capture.  If this option is enabled screenshots will be taken automatically every second and sent to server when a crash occurs.  At most the last 3 screenshots will be sent.
 */
- (void) enableAutoScreenCapture;

/*!
 @method disableAutoScreenCapture
 @abstract Disable auto screen capture.  Call this method to stop automatic screen captures.
 */
- (void) disableAutoScreenCapture;

/*!
 @method setUserId
 @abstract Set user unique identifier.  Any string can be set. If a user ID has been set it will be included in the crash report.
 @param userId A unique user ID string used by your application.
 */
- (void) setUserId:(NSString *) userId;

/*!
 @method logExceptionForUnity
 @abstract This method is not public.  It may be called from your unity guru code.
 */
- (void) logExceptionForUnity: (NSString *) stackTrace withMessage:(NSString *) message withImagePath:(NSString *) imagePath;

/*!
 @method beforePresentRenderbuffer
 @abstract Call this API right before calling presentRenderbuffer in your rendering loop to take OpenGL screen captures.
 @param view The UIView to be rendered.
 */
- (void) beforePresentRenderbuffer:(UIView *)view;

/*!
 @method afterPresentRenderbuffer
 @abstract Call this API right after calling presentRenderbuffer in your rendering loop when taking OpenGL screen captures.
 */
- (void) afterPresentRenderbuffer;

/*!
 @method getSdkVersion
 @abstract Get current SDK version
 @result returns current SDK version.
 */
- (NSString *)getSdkVersion;

/*!
 @method enable
 @abstract Enable saving/sending Crash/Exception/Captured image.
 */
- (void) enable;

/*!
 @method disable
 @abstract Disable saving/sending Crash/Exception/Captured image.
 */
- (void) disable;

/*!
 @method isEnabled
 @abstract Return if saving/sending Crash/Exception/Captured image is enabled.
 @result YES if saving/sending Crash/Exception/Captured image is enabled, NO otherwise.
 */
- (BOOL) isEnabled;

/*!
 @method addSensitiveViewTag
 @abstract Add tag of sensitive view. Screen capture is skipped if the view with tag is included in keywindow view hierarchy. NOTE "0" cannot be added because it's default tag id.
 @param tag The tag id of view that screen capture shouldn't be taken.
 */
- (void) addSensitiveViewTag:(NSInteger) tag;

/*!
 @method removeSensitiveViewTag
 @abstract Remove tag of sensitive view.
 @param tag
 */
- (void) removeSensitiveViewTag:(NSInteger) tag;


@end
