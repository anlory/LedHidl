#include <android/hardware/ir/1.0/ILed.h>
#include <log/log.h>

#define LOG_TAG "LED_CLINET"
using android::hardware::led::V1_0::ILed;
using android::sp;
int main(){
	sp<ILed> service = ILed.getService();
	if( service == nullptr ){
		ALOGE("Can't find ILed service...");
		return -1;
	}
	ALOGE("ILed ON");
	ILed->on();
	
	ALOGE("ILed OFF");
	ILed->off();

	return 0;
}