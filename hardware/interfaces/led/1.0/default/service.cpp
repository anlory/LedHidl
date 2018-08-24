#define LOG_TAG "android.hardware.led@1.0-service"

#include <android/hardware/led/1.0/ILed.h>
#include <hidl/LegacySupport.h>
#include "ledImpl.h"
using android::hardware::led::V1_0::ILed;
using android::hardware::led::V1_0::implementation::ledImpl;
using android::hardware::defaultPassthroughServiceImplementation;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::sp;


int main() {
#if 0 
// Passthrough   dlopen so方式
    return defaultPassthroughServiceImplementation<Iled>(); 
#else
// Binder 方式
	sp<ILed> service = new ledImpl();
	configureRpcThreadpool(1, true /*callerWillJoin*/);
    if(android::OK !=  service->registerAsService())
			return 1;
    joinRpcThreadpool();
#endif
}





