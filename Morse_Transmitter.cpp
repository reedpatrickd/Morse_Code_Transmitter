

#include "Morse.h"




int main()
{
	pinMode(LED_BUILTIN, OUTPUT);
	init();  // initialize timers
	Serial.begin(115200);
	Serial.println("Enter Your Message or press '!' to end");
	Serial.flush(); // let serial printing finish

	Send_Morse_Code();


return 0;
}

