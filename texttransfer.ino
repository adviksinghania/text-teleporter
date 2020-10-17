/* Project Name : Text Transfer
 * Transferring text messages from serial monitor to terminal in 2 different devices, via bluetooth
 * For : Arduino Micro/Leonardo/Due/Pro Micro (ATMega 32U4)
 * Author : Advik Singhania
 * Created On : 17th October, 2020; 00:48 AM IST
 */

void setup() {
  // Open the serial port for bluetooth:
  Serial1.begin(9600);
  // Open the serial port over USB interface:
  Serial.begin(9600);
}

void loop() {
  // Check for incoming serial data over bluetooth:
  if (Serial1.available() > 0) {
    // Read incoming serial data:
    String a = Serial1.readString();
    // Type the text:
    Serial.println(a);
  }
  // Check for incoming serial data over USB:
  if (Serial.available() > 0) {
    // Read incoming serial data:
    String b = Serial.readString();
    // Type the text:
    Serial1.println(b);
  }
  delay(10); // Delay of 10 milliseconds
}
