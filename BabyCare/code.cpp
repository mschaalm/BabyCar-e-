#include "SIM900.h"
#include <SoftwareSerial.h>
//If not used, is better to exclude the HTTP library,
//for RAM saving.
//If your sketch reboots itself proprably you have finished,
//your memory available.
//#include "inetGSM.h"

//If you want to use the Arduino functions to manage SMS, uncomment the lines below.
#include "sms.h"
SMSGSM sms;     //

				//To change pins for Software Serial, use the two lines in GSM.cpp.

				//GSM Shield for Arduino
				//www.open-electronics.org
				//this code is based on the example of Arduino Labs.

				//Simple sketch to send and receive SMS.

intnumdata;
boolean started = false;
charsmsbuffer[160];
char n[20];
#define sw 2
int  temp;

void setup()
{
	//Serial connection.
	Serial.begin(9600);
	Serial.println("GSM Shield testing.");
	//Start configuration of shield with baudrate.
	//For http uses is raccomanded to use 4800 or slower.
	if (gsm.begin(2400)) 
	{	 Serial.println("\nstatus=READY");    
		 started = true; 
	}
	elseSerial.println("\nstatus=IDLE");
}

voidsendsms()
{
	if (started)
	{
		//   if (sms.SendSMS("0543902925", " IM' in the car   help "))      Serial.println("\nSMS sent OK");
		if (sms.SendSMS("0523818648", " IM' in the car   help "))      
				Serial.println("\nSMS sent OK");
		started = 0;
	}
	if (gsm.readSMS(smsbuffer, 160, n, 20))
	{
		Serial.println(n);
		Serial.println(smsbuffer);
	}
	delay(1000);
}

void loop()
{
	temp = analogRead(0);
	Serial.print(temp); Serial.print(" ");
	if (digitalRead(sw) && (temp<600))
	{
		Serial.print("    HELP ");  sendsms();
	}
	//if (digitalRead(sw))Serial.println("     1  ");else Serial.println("    0  ");
	delay(1000);
};
