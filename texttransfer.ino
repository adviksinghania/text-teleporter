/* Project Name : Text Transfer
 * Transferring text messages from serial monitor to terminal in 2 different devices, via bluetooth
 * For : Arduino Micro/Leonardo/Due/Pro Micro (ATMega 32U4)
 * Author : Advik Singhania
 * Created On : 17th October, 2020; 00:48 AM IST
 */

#define LED_PIN 13 // blinking LED if no data is available on either channel

void setup() {
  // Open the serial port for bluetooth:
  Serial1.begin(9600);
  // Open the serial port over USB interface:
  Serial.begin(9600);
  // Initializing LED on pin 13 as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Check for incoming serial data over bluetooth:
  while (Serial1.available() > 0) {
    // Read incoming serial data:
    String a = Serial1.readString();
    // Type the text:
    Serial1.print("You: ");
    Serial1.println(a);
    Serial.print("Phone: ");
    Serial.println(a);
  }
  // Check for incoming serial data over USB:
  while (Serial.available() > 0) {
    // Read incoming serial data:
    String b = Serial.readString();
    // Type the text:
    Serial.print("You: ");
    Serial.println(b);
    Serial1.print("Laptop: ");
    Serial1.println(b);
  }
  //Blinking LED:
  digitalWrite(LED_PIN, HIGH);
  delay(250);
  digitalWrite(LED_PIN, LOW);
  delay(250);
  
  delay(10); // Delay of 10 milliseconds
}
