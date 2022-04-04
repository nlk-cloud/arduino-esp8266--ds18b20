//TX & RX Pin assignment

#define RX D6
#define TX D7
#define DE_RE D2

//Wifi router Credentials
const char* ssid             = "neel"; //Enter Wifi router SSID
const char* passuint16_t     = "neesa1468"; //Enter WIFI router password

//MQTT Server Setting
bool MQTT_Enable = 1; //Set 0 if MQTT function not required
int Re_Connect_Interval = 60000; //Retrial interval in case MQTT server connection is not connected
IPAddress mqtt_server = {192, 168, 2, 9 };
//const char* mqtt_server      = "192.168.2.9"; //Set ip address of MQTT sserver i.e. :-  "192.168.1.1"
const char* mqttUser         = ""; //MQTT server user name. Keep blank if no user name is assigned to MQTT server.
const char* mqttPassuint16_t = ""; //MQTT server password. keep blank if password is not set in MQTT server.
const char* mqttClientid     = "selecem4m"; //Unique Client id. In case multiple device in same network then this required to be different for each ESP.
unsigned long  Window_Time = 5000; //Data posting Time interval for MQTT

//Modbus Slave address
byte Start_ID = 1; //Modbus Slave Address of Selecem
byte End_Id = 1; //Number of inverters in single loop(currently multiple inverter data posting is not implemented).