/*
 * Serial Read Background Colour
 * 
 * Waits for Arduino serial connection.
 * 
 * Sets the background colour based on the serial values recieved.
 * 
 * Created by Adam Corrie on 28/07/2019
 * Licensed under the GNU General Public License v3.0
 * 
 */

import processing.serial.*;

Serial serialPort;

color backgroundColour;

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
  backgroundColour = color(0, 0, 0);
  background(backgroundColour);
}

void draw() {
  background(backgroundColour);
  while (serialPort.available() > 0) {
    String serialData = trim(serialPort.readStringUntil(10));
    if (serialData != null) {
      try {
        String[] rgbValues = split(serialData, ',');
        if (rgbValues.length == 3) {
          int rValue = Integer.parseInt(rgbValues[0]);
          int gValue = Integer.parseInt(rgbValues[1]);
          int bValue = Integer.parseInt(rgbValues[2]);
          color newBackgroundColour = color(rValue, gValue, bValue);
          println("R: " + rValue + " G: " + gValue + " B: " + bValue);
          backgroundColour = newBackgroundColour;
        }
      } catch (Exception e) {}
    }
  }
}
