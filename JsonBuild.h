char msg[500];
void JSON_Pack() {
  const size_t capacity = 2 * JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3);
  //if (MB_STS == 228) MB_STS_JSON = 0;
  //else MB_STS_JSON = 1;
  DynamicJsonDocument doc(capacity);
  //doc["MB_STS"] = MB_STS_JSON;
  
  JsonObject temp = doc.createNestedObject("temp");
  temp["tempC"] = tempC;
  temp["tempF"] = tempF;
    
  serializeJson(doc, Serial);
  serializeJson(doc, msg);
  Serial.println();
  client.publish("Dtempsensor/Data/Json", msg);
    
}