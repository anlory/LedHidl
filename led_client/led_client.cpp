
#define LOG_TAG "LED_CLINET"
#include <android/hardware/led/1.0/ILed.h>
#include <log/log.h>

using android::hardware::led::V1_0::ILed;
using android::hardware::led::V1_0::LedStatus;
using android::hardware::led::V1_0::BrightnessRange;
using android::hardware::hidl_vec;
using android::sp;


int main(){
	// BrightnessRange range;
	sp<ILed> service = ILed::getService();
	if( service == nullptr ){
		ALOGE("Can't find ILed service...");
		return -1;
	}
	ALOGE("ILed ON");
	service->on();
	
	ALOGE("ILed OFF");
	service->off();
	
	ALOGE("ILed set");
	service->set(LedStatus::LED_ON);

	ALOGE("ILed get");
	LedStatus ret = service->get();
	ALOGE("ILed get: %d",ret);
	
	service->getBrightnessRange([](bool ret1,BrightnessRange range){
		ALOGE("ILed getBrightnessRange ret: %d",ret1);
		ALOGE("ILed getBrightnessRange Max: %d",range.max);
		ALOGE("ILed getBrightnessRange Min: %d",range.min);
	});
	int32_t array[] = {5, 6, 7};
	hidl_vec<int32_t> hv1 = std::vector<int32_t>(array, array + 3);
	bool ret2 = service->getBrightnessValue(hv1);
	ALOGE("ILed getBrightnessValue bool: %d",ret2);
	return 0;
}
