
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "";  //device ID

const char SSID[]               = ; //wifi name   
const char PASS[]               = ;   //wifi password
const char DEVICE_KEY[]  = ;    //key grnerates in arduino cloud


float voltage;
int bat_percentage;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(voltage, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(bat_percentage, READ, ON_CHANGE, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
