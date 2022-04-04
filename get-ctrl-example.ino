#include "ESP8266HTTPClient.h"
#include "ESP8266WiFi.h" 

//Access point credentials
const char* ssid = "neel";
const char* pwd = "neesa1468";
const char* host = "http://192.168.2.7";
String get_host = "http://192.168.2.7";

//WiFiServer server(80);  // open port 80 for server connection

void setup() 
{
   Serial.begin(115200); //initialise the serial communication
   delay(20);

   //WiFi.begin(ssid, pwd);

   //starting the server
   //server.begin();
   
}

void loop()
{
  Serial.println("It is in setup");
   //call_test();
  //get_device_status("led1","Home Light");      
}


/*void call_test()
{
  Serial.println("It is test");
}

/*void get_device_status(String device_name, String device_text)
  {
    
        WiFiClient client = server.available();

        HTTPClient http;
        String url = get_host+"/IOT/iot_light.php?device_name="+device_name;
        
        http.begin(client, url);
       
        //GET method
        int httpCode = http.GET();
        String payload = http.getString();
        if(payload=="1")
        {
          Serial.println(device_text+" is ON");
        }
        else
        {
          Serial.println(device_text+" is Off");
        }
        http.end();
        delay(1000);
  
  }*/