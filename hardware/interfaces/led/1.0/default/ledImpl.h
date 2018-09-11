#ifndef ANDROID_HARDWARE_LED_V1_0_LED_H
#define ANDROID_HARDWARE_LED_V1_0_LED_H
#include <android/hardware/led/1.0/ILed.h>

#include <hidl/Status.h>

#include <hidl/MQDescriptor.h>




namespace android {
namespace hardware {
namespace led {
namespace V1_0 {
namespace implementation {

using ::android::hardware::led::V1_0::LedStatus;
using ::android::hardware::led::V1_0::BrightnessRange;
using ::android::hardware::led::V1_0::ILed;
using ::android::hardware::hidl_array;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;
	
	
struct ledImpl : public ILed {
	public:
		ledImpl();
		Return<LedStatus>  get() override ;
		Return<int32_t> set(LedStatus val) override;
		Return<void> on() override;
		Return<void> off() override;
		Return<void> getBrightnessRange(getBrightnessRange_cb _hidl_cb) override;
		Return<bool> setBrightnessValue(const hidl_vec<int32_t>& range) override;
	private:
		LedStatus state;
};
	
extern "C" ILed* HIDL_FETCH_ILed(const char* name);
}  // namespace implementation
}  // namespace V1_0
}  // namespace led
}  // namespace hardware
}  // namespace android

#endif //ANDROID_HARDWARE_LED_V1_0_LED_H
