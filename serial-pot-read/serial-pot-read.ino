/*
 * Serial Pot Read
 * 
 * Connect a potentiometer between 5V, Pin A0 and GND.
 * 
 * The input value will be sent to the serial console.
 * 
 * Created by Adam Corrie on 27/07/2019
 * Licensed under the GNU General Public License v3.0
 * 
 */

#define potPin A0 // define potPin as Pin A0

void setup() {
  delay(3000); // 3s startup delay
  Serial.begin(9600); // start serial communication at 9,600 baud
}

void loop() {
  int potValue = analogRead(potPin); // read value from potentiometer
  //int potValue = map(analogRead(potPin), 0, 1023, 0, 511); // read mapped value from potentiometer
  Serial.println(potValue); // writes value to serial port
  delay(50); // 50ms delay to reduce serial traffic
}
