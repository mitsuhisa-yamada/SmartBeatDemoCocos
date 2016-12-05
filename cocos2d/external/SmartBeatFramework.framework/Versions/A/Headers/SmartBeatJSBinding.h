/*
 * Copyright (c) 2016 FROSK, Inc. All rights reserved.
 */
/*!
 @header SmartBeatJSBinding
 @abstract JavaScript Binding for Cocos2d-JS.
 */

#ifndef SMARTBEAT_JS_BINDING_H
#define SMARTBEAT_JS_BINDING_H

#include <jsapi.h>

namespace SmartBeat {

/*!
 @method registerSmartBeatJSBinding
 @abstract Registers SmartBeat's JavaScript Binding Class.
 @discussion
 Register this function by using ScriptingCore::addRegisterCallback()
 in AppDelegate::applicationDidFinishLaunching() (&lt;Project&gt;/frameworks/runtime-src/Classes/AppDelegate.cpp) as below.
 <pre>bool AppDelegate::applicationDidFinishLaunching()
{
    ...
    sc->addRegisterCallback(...);
    sc->addRegisterCallback(...);
    ...
    sc->addRegisterCallback(SmartBeat::registerSmartBeatJSBinding); // add above sc->start()
    ...
    sc->start();
    ...
}</pre>
 */
void registerSmartBeatJSBinding(JSContext* cx, JS::HandleObject global);

}

#endif // SMARTBEAT_JS_BINDING_H
