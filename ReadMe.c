hidl demo
1. 以控制LED为例进行demo的编写
1.1 编写led.hal 和types.hal
1.2 执行update-makefiles.sh 编译文件
	新建defalut文件夹
	
1.3 实现android.hardware.led@1.0-impl和android.hardware.led@1.0-service
	编写android.bp
		cc_library_shared {
			name: "android.hardware.led@1.0-impl",
			defaults: ["hidl_defaults"],
			relative_install_path: "hw",
			proprietary: true,
			srcs: ["Consumerled.cpp"],
			shared_libs: [
				"libhidlbase",
				"libhidltransport",
				"libhardware",
				"liblog",
				"libutils",
				"android.hardware.led@1.0",
			],
		}

		cc_binary {
			relative_install_path: "hw",
			defaults: ["hidl_defaults"],
			name: "android.hardware.led@1.0-service",
			proprietary: true,
			init_rc: ["android.hardware.led@1.0-service.rc"],
			srcs: ["service.cpp"],

			shared_libs: [
				"liblog",
				"libhardware",
				"libhidlbase",
				"libhidltransport",
				"libutils",
				"android.hardware.led@1.0",
			],

		}
	
		接下来，使用相应功能填写存根并设置守护进程。守护进程代码（支持直通）示例：

		#include <hidl/LegacySupport.h>

		int main(int /* argc */, char* /* argv */ []) {
			return defaultPassthroughServiceImplementation<INfc>("nfc");
		}
		defaultPassthroughServiceImplementation 将对提供的 -impl 库执行 dlopen() 操作，并将其作为绑定式服务提供。守护进程代码（对于纯绑定式服务）示例：

		int main(int /* argc */, char* /* argv */ []) {
			sp nfc = new Nfc();
			const status_t status = nfc->registerAsService();
			if (status != ::android::OK) {
				return 1; // or handle error
			}
			// join pool or do other things
		}

		
		add the code to the manifest.xm 以至于hwservicemanager 查找到指定的hidl service
			About HIDL configures
			device/linaro/hikey/manifest.xml
			<hal format="hidl">
				<name>android.hardware.led</name>
				<transport>hwbinder</transport>
				<version>1.0</version>
				<interface>
					<name>ILed</name>
					<instance>default</instance>
				</interface>
			</hal>
		
		
2. 实现java调用hidl service的例子
	2.1 添加库：
		将以下内容添加到 Android.mk 中：
		LOCAL_JAVA_LIBRARIES += android.hardware.foo-V1.0-java
		或
		将以下内容添加到 Android.bp 中：
		shared_libs: [
			/* … */
			"android.hardware.foo-V1.0-java",
		],
		该库还存在静态版：android.hardware.foo-V1.0-java-static。
	2.2 将以下内容添加到您的 Java 文件中：
		import android.hardware.foo.V1_0.IFoo;
		...
		// retry to wait until the service starts up if it is in the manifest
		IFoo server = IFoo.getService(true /* retry */); // throws NoSuchElementException if not available
		IFoo anotherServer = IFoo.getService("second_impl", true /* retry */);
		server.doSomething(…);
		

3. 实现C++ 调用hidl service的例子
	首先将 HAL 库添加到 makefile 中：
		Make：LOCAL_SHARED_LIBRARIES += android.hardware.nfc@1.0
		Soong：shared_libs: [ …, android.hardware.nfc@1.0 ]
	接下来，添加 HAL 头文件：
		#include <android/hardware/nfc/1.0/IFoo.h>
		…
		// in code:
		sp<IFoo> client = IFoo::getService();
		client->doThing();


4. 编写LED驱动


