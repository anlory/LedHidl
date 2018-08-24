
#define LOG_TAG "LED_CLINET"
#include <android/hardware/led/1.0/ILed.h>
#include <log/log.h>

using android::hardware::led::V1_0::ILed;
using android::sp;
int main(){
	sp<ILed> service = ILed::getService();
	if( service == nullptr ){
		ALOGE("Can't find ILed service...");
		return -1;
	}
	ALOGE("ILed ON");
	service->on();
	
	ALOGE("ILed OFF");
	service->off();

	return 0;
}
