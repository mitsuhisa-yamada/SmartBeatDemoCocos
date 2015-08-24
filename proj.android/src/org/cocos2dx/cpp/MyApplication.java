package org.cocos2dx.cpp;

import com.smrtbeat.SmartBeat;
import android.app.Application;

public class MyApplication extends Application {
    public void onCreate() {
        SmartBeat.initAndStartSession(this, "81033dd3-62d2-4030-8ec3-b885814c694b");
    }
}
