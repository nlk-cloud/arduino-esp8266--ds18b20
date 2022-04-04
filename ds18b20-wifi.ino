#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// Data wire is plugged into port D8 on the ESP8266
// Red wire to 3.3V and black to gnd. Yellow wire should go to D8 and should be pulled up to 3.3V via 4.7K resistor


#define ONE_WIRE_BUS D8

// Setup a one wire instance to communicate with any one wire device

OneWire oneWire(ONE_WIRE_BUS);

// Pass oneWire reference to Dallas Temperature

DallasTemperature sensors(&oneWire);

//variable to hold device address
DeviceAddress Thermometer[5];

int deviceCount=0;

//Access credentials

const char* ssid = "neel";
const char* pwd = "neesa1468";
// xamp server on local computer. Check the ipaddress using IPCONFIG and plug it in here
//const char* host = "http://192.168.2.6";
//String get_host = "http://192.168.2.6";

//Metriq server
const char* host = "http://192.185.149.194";
String get_host = "http://192.185.149.194";

//use this with XAMP 
WiFiServer server(80);

// Use this with Metriq
WiFiServer server(2082);


void setup() {
  // put your setup code here, to run once:
//start serial port
delay(1000);
Serial.begin(115200);
delay(1000);
// start the library
sensors.begin();

//locate the devices on bus
Serial.println("Locating devices...");
Serial.print("Found");
deviceCount= sensors.getDeviceCount();
Serial.print(deviceCount,DEC);
Serial.println(" devices. ");
Serial.println("");

Serial.println("Printing addresses...");

for(int i=0; i< deviceCount; i++)
{
  Serial.print("Sensor ");
  Serial.print(i+1);
  Serial.print(" :");
  sensors.getAddress(Thermometer[i],i);
  //printAddress(Thermometer);
  Serial.println(sensors.getAddress(Thermometer[i],i));

}
// connecting to wifi

delay(20);
    WiFi.begin(ssid,pwd);

    // starting the server
    server.begin();

    Serial.println("Connecting");

    while(WiFi.status() != WL_CONNECTED)
    {
          delay(500);
          Serial.print(".");
    }

    Serial.println();

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
 
}

void loop() {
  // put your main code here, to run repeatedly:
sensors.requestTemperatures();
float tempc=sensors.getTempC(Thermometer[0]);  
float tempf=sensors.getTempF(Thermometer[0]);

Serial.print(" Temp in oC is: ");
Serial.println(tempc); 
Serial.print(" Temp in oF is: ");
Serial.println(tempf);

post_device_status("thermometer0",tempc);
delay(5000);

}

void post_device_status(String thermometer, float value)

{
    String data, station, postData;

    WiFiClient client = server.available();
    HTTPClient http;

    float sensedata = value;
    data = String(sensedata);   //String to interger conversion
    station = thermometer;

  //Post Data
  postData = "status=" + data + "&station=" + station ;
  
  String url = get_host+"/IIOT/ds18b20-post-get.php";
  http.begin(client,url);
  
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header

  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload

  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload

  http.end();  //Close connection
  
 
}





