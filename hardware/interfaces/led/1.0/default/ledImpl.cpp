/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless requleded by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "LedService"

#include <log/log.h>



#include "ledImpl.h"

namespace android {
namespace hardware {
namespace led {
namespace V1_0 {
namespace implementation {

ledImpl::ledImpl() {
	status = -1;
	ALOGE("ledImpl Init status:%d", status);
}



Return<void> ledImpl::on() {
	status = 1;
	ALOGE("ledImpl on status:%d", status);
    return Void();
}

Return<void> ledImpl::off() {
	status = 0;
	ALOGE("ledImpl off status:%d", status);	
    return Void();
}


Return<LedStatus>  get() {
		if(status == LedStatus::LED_ON)
			return 1;
		if(status == LedStatus::LED_OFF)
			return 0;
		if(status == LedStatus::BAD_VALUE)
			return -1;
}

Return<int32_t> set(LedStatus val) {
		if(val == LedStatus::LED_ON){
			status = 1;
			return 0;
		}
		if(val == LedStatus::LED_OFF){
			status = 0;
			return 0;
		}
		return -1;
}

IledImpl* HIDL_FETCH_IledImpl(const char * /*name*/) {
	ALOGE("ledImpl HIDL_FETCH_IledImpl status:%d", status);	
    return new ledImpl();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace led
}  // namespace hardware
}  // namespace android