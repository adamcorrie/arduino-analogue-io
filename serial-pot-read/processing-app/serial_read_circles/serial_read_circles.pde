/*
 * Serial Read Circles
 * 
 * Waits for Arduino serial connection.
 * 
 * Draws a circle with a diameter corresponding to the serial values recieved.
 * 
 * Created by Adam Corrie on 27/07/2019
 * Licensed under the GNU General Public License v3.0
 * 
 */

import processing.serial.*;

Serial serialPort;

int circleDiameter;

void setup() {
  size(512, 512);
  String selectedPort = "";
  while (selectedPort == "") {
    String[] serialPorts = Serial.list();
    for (int i = 0; i < serialPorts.length; i++) {
      if (serialPorts[i].indexOf("cu.usb") != -1) {
        selectedPort = serialPorts[i];
      }
    }
  }
  serialPort = new Serial(this, selectedPort, 9600);
  background(0);
  fill(0);
  stroke(255);
  circleDiameter = 0;
}

void draw() {
  background(0);
  while (serialPort.available() > 0) {
    String serialData = trim(serialPort.readStringUntil(10));
    if (serialData != null) {
      try {
        int newCircleDiameter = Integer.parseInt(serialData);
        println("Diameter: " + newCircleDiameter + " pixels");
        circleDiameter = newCircleDiameter;
      } catch (Exception e) {}
    }
  }
  ellipse((width / 2), (height / 2), circleDiameter, circleDiameter);
}
