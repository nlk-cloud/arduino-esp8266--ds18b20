void setup_wifi() {
  

  //Connecting WIFI_Router_AS_Client
  Serial.println();
  Serial.print("Connecting to Router :- ");
  Serial.println(ssid);
  WiFi.begin(ssid, passuint16_t);
  int timeout = 0;
  while (WiFi.status() != WL_CONNECTED) {
    //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(100);
    Serial.print(".");
    timeout = timeout + 1;
    if (timeout >= 120) {
      Serial.println("Connection not establised");
      return;
    }
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}