import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class serial_read_circles extends PApplet {

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



Serial serialPort;

int circleDiameter;

public void setup() {
  
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

public void draw() {
  background(0);
  while (serialPort.available() > 0) {
    String serialData = trim(serialPort.readStringUntil(10));
    if (serialData != null) {
      try {
        int newCircleDiameter = Integer.parseInt(serialData);
        circleDiameter = newCircleDiameter;
      } catch (Exception e) {}
    }
  }
  ellipse((width / 2), (height / 2), circleDiameter, circleDiameter);
}
  public void settings() {  size(512, 512); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "serial_read_circles" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
