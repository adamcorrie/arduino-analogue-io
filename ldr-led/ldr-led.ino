/*
 * LDR LED
 * 
 * Connect a light-dependent resistor between 5V and Pin A0. Use
 * a 10k Ohm pull-down resistor.
 * 
 * Connect an LED and a suitable current-limiting resistor
 * between Pin 3 and GND.
 * 
 * The brightness of the LED will change in response to the
 * ambient lighting.
 * 
 * Created by Adam Corrie on 30/07/2019
 * Licensed under the GNU General Public License v3.0
 * 
 */

#define potPin A0 // define potPin as Pin A0
#define ledPin 3 // define ledPin as Pin 3

void setup() {
  Serial.begin(9600); // start serial communication at 9,600 baud
}

void loop() {
  int potValue = analogRead(potPin); // read value from potentiometer
  Serial.println(potValue); // write value to serial port
  int mappedPotValue = map(potValue, 1023, 0, 0, 255); // map the value
  analogWrite(ledPin, mappedPotValue); // write the mapped value to the PWM pin
  delay(50); // 50ms delay to reduce serial traffic
}
