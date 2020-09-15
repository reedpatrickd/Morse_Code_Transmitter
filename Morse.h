// Morse.h


#define _MORSE_h


#include "arduino.h"

char incoming_message = 0;
bool fin = false;
char* letters[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.","...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
//	char numbers[] = { "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." }
int dot_delay = 100;
int word_delay = dot_delay * 7;
int letter_delay = dot_delay * 3;
int dash_delay = dot_delay * 3;

void LED_CONTROL(char DD) {
	digitalWrite(LED_BUILTIN, HIGH);
	if (DD == '.') {
		delay(dot_delay);
	}

	else {
		delay(dash_delay);
	}
	digitalWrite(LED_BUILTIN, LOW);
	delay(letter_delay);
}

void flash(char* letters) {
	int i = 0;
	while (letters[i] != NULL) {
		LED_CONTROL(letters[i]);
		i++;
	}
}

void Send_Morse_Code() {
	while (fin == false)
	{
		if (Serial.available() > 0)
		{
			incoming_message = Serial.read();
			if (incoming_message >= 'A' && incoming_message <= 'Z') {
				flash(letters[incoming_message - 'A']);
			}
			else if (incoming_message >= 'a' && incoming_message <= 'z') {
				flash(letters[incoming_message - 'a']);
			}
			else if (incoming_message == ' ') {
				delay(word_delay);
			}
			else if (incoming_message == '!') {
				Serial.println("Exiting Morse Code Transmitter");
				Serial.flush(); // let serial printing finish
				fin = true;
			}
		}
	}
}
