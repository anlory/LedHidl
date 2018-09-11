adb root
adb remount
adb shell mkdir /data/hidl/
adb push led_client /data/hidl/
adb push android.hardware.led@1.0-service /data/hidl/
adb push hidl_java.java /data/hidl/
adb push android.hardware.led@1.0-impl.so /vendor/lib64/hw/
REM adb push android.hardware.led@1.0.so /system/lib64/hw/
adb push android.hardware.led@1.0.so /vendor/lib64/hw/
adb push manifest.xml /vendor/
adb shell chmod 755 /data/hidl/*

REM adb shell export LD_LIBRARY_PATH=/vendor/lib64/hw:$LD_LIBRARY_PATH
pause