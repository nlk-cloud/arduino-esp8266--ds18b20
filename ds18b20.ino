#include <OneWire.h>
#include <DallasTemperature.h>

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

delay(5000);

}




