/*
 * Serial Three Pot Read
 * 
 * Connect a potentiometer between 5V, Pin A0 and GND.
 * Connect another potentiometer between 5V, Pin A1 and GND.
 * Connect a final potentiometer between 5V, Pin A2 and GND.
 * 
 * The input value will be sent to the serial port.
 * 
 * Created by Adam Corrie on 28/07/2019
 * Licensed under the GNU General Public License v3.0
 * 
 */

#define pot1Pin A0 // define pot1Pin as Pin A0
#define pot2Pin A1 // define pot2Pin as Pin A1
#define pot3Pin A2 // define pot3Pin as Pin A2

void setup() {
  delay(3000); // 3s startup delay
  Serial.begin(9600); // start serial communication at 9,600 baud
}

void loop() {
  int pot1Value = map(analogRead(pot1Pin), 0, 1023, 0, 255); // read mapped value from potentiometer 1
  int pot2Value = map(analogRead(pot2Pin), 0, 1023, 0, 255); // read mapped value from potentiometer 2
  int pot3Value = map(analogRead(pot3Pin), 0, 1023, 0, 255); // read mapped value from potentiometer 3
  // combine values and send to serial port
  Serial.print(pot1Value);
  Serial.print(",");
  Serial.print(pot2Value);
  Serial.print(",");
  Serial.println(pot3Value);
  delay(50); // 50ms delay to reduce serial traffic
}
