#include<ESP8266WiFi.h>
#include<WiFiUdp.h>

WiFiUDP Udp;

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin("Arihant", "arpit13579");
  Udp.begin(4210);
}

void loop() {
  int i = Udp.parsePacket();
  if(i>0){
    uint8_t rdata[1];
    Udp.read(rdata,1);
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(rdata,i);
    Udp.endPacket();
  }
}
