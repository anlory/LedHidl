#define LOG_TAG "LedService"

#include <log/log.h>
#include "ledImpl.h"

namespace android {
namespace hardware {
namespace led {
namespace V1_0 {
namespace implementation {

ledImpl::ledImpl() {
	state = LedStatus::BAD_VALUE;
	ALOGE("ledImpl Init status:%d", state);
}

Return<void> ledImpl::on() {
	state = LedStatus::LED_ON;
	ALOGE("ledImpl on status:%d", state);
    return Void();
}

Return<void> ledImpl::off() {
	state = LedStatus::LED_OFF;
	ALOGE("ledImpl off status:%d", state);	
    return Void();
}

Return<LedStatus>  ledImpl::get() {
	return state;
}
Return<int32_t> ledImpl::set(LedStatus val) {
	state = val;
	return 0;
}
ILed* HIDL_FETCH_ILed(const char * /*name*/) {
	ALOGE("ledImpl HIDL_FETCH_ILed ");	
    return new ledImpl();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace led
}  // namespace hardware
}  // namespace android