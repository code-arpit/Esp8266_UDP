#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

//set wifi credentials
#define WIFI_USERNAME ""
#define WIFI_PASSWORD ""
#define UDP_PORT 4210

// UDP
WiFiUDP UDP;
char packet[255];
char reply[] = "packet received";

void setup (){
  //setup serial 
  Serial.begin(115200);
  Serial.println();

  //Begin WIFI
  WiFi.begin(WIFI_USERNAME , WIFI_PASSWORD);

  //connecting to wifi...
  Serial.print("Connecting to .....");
  Serial.print(WIFI_USERNAME);

  //loop continue until wifi is connected
  while (WiFi.status() != WL_CONNECTED){
    delay(100);
    Serial.println("Trying...");  
  }
  
  //after connection
  Serial.println();
  Serial.println("Connected! IP Address");
  Serial.println(WiFi.localIP());

  //begin listening to UDP port
  UDP.begin(UDP_PORT);
  Serial.print("listening to udp port");
  Serial.println(UDP_PORT);
  
  
}

void loop(){

  //if packet is received
  int packetSize = UDP.parsePacket();
  if (packetSize) { 
    Serial.print("Received packet! Size: ");
    Serial.println(packetSize);
    int len = UDP.read(packet, 255);
    if (len > 0)
      packet[len] = '\0';

      Serial.print("packet Received:");
      Serial.println(packet);

      UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
      UDP.write(reply);
      UDP.endPacket();
      
      
  }
  
}
