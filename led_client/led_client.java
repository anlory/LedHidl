package com.android.led.client;
import android.util.Slog;
import android.hardware.led.V1_0.ILed;

public class LedClinet {
	public static void main(String args[]){
		
		ILed service = ILed.getService(true);
		
		service.on();
		service.off();
		
	}
	
	
}