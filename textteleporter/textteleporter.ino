/* Project Name : Text Teleporter
 * Receives some text in String format via bluetooth from one device and types (pastes) it into another device.
 * For : Arduino Micro/Leonardo/Due/Pro Micro (ATMega 32U4)
 * Author : Advik Singhania
 * Created On : 11th October, 2020; 11:23 AM IST
 */

//Keyboard header file for Arduino to take
//control of the keyboard and paste the string
#include "Keyboard.h"

void setup() {
  // Open the serial port for bluetooth:
  Serial1.begin(9600);
  // Initialize control for the keyboard:
  Keyboard.begin();
}

void loop() {
  // Check for incoming serial data:
  if (Serial1.available() > 0) {
    // Read incoming serial data:
    String a = Serial1.readString();
    // Type the text:
    Keyboard.print(a);
  }
  delay(10); // Delay of 10 milliseconds
}
