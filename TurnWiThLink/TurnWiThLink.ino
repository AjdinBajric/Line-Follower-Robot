#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

ESP8266WebServer server(80);

char* ssid="ConnectionLost";
char* password ="dajdatiukucam";


void setup(){

  pinMode(5,OUTPUT);
  
  Serial.begin(115200);

  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED){
    
    delay(500);
    Serial.println("Connecting to: ");
    Serial.println("ssid");
    
    
    }

    Serial.println(WiFi.localIP());

    server.on("/0", [](){
      
     digitalWrite(5,HIGH); 
      
     });

     server.on("/1", [](){
      
     digitalWrite(5,LOW); 
      
     });

     server.begin();

     digitalWrite(5,HIGH);
}


void loop(){

  server.handleClient();
  
  
}
