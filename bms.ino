#include "thingproperties.h"
int analogInPin  = A0;    
int sensorValue; 
float calibration = 0.36; 
void setup() {
Serial.begin(9600);
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);  
setDebugMessageLevel(2);
ArduinoCloud.printDebugInfo();
}
void loop() {
ArduinoCloud.update();
ArduinoCloud.update();
sensorValue = analogRead(analogInPin);
voltage = (((sensorValue * 3.3) / 1024) * 2 + calibration); 
bat_percentage = mapfloat(voltage, 2.8, 4.2, 0, 100); 
if (bat_percentage>= 100)
  {
bat_percentage = 100;
  }
if (bat_percentage<= 0)
  {
bat_percentage = 1;
  }
Serial.print("Analog Value = ");
Serial.print(sensorValue);
Serial.print("\t Output Voltage = ");
Serial.print(voltage);
Serial.print("\t Battery Percentage = ");
Serial.println(bat_percentage);
delay(1000);
}
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
