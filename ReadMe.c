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
	


2. 实现java调用hidl service的例子
3. 实现C++ 调用hidl service的例子
4. 编写LED驱动


