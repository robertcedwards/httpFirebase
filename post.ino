#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x19 };   // Be sure this address is unique in your network
uint8_t pinDevid1 = 3; // Example : the mailbox switch is connect to the Pin 3
boolean DEBUG = true;

char serverName[] = "rfidtofirebase.heroku.com"; //The important bit
boolean pinDevid1State = false;                // Save the last state of the Pin for DEVID1
boolean lastConnected = false;                 // State of the connection last time through the main loop

EthernetClient client;

void setup() {
  Serial.begin(9600);
  pinMode(pinDevid1, INPUT);
  
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    while(true);
  }
  else{
    Serial.println("Ethernet ready");
    // print the Ethernet board/shield's IP address:
    Serial.print("My IP address: ");
    Serial.println(Ethernet.localIP());
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
}

void loop()
{
        sendToPushingBox(DEVID1);
      //DEBUG part
      // this write the respons from PushingBox Server.
      // You should see a "200 OK"
      if (client.available()) {
        char c = client.read();
        if(DEBUG){Serial.print(c);}
      }
      
      // if there's no net connection, but there was one last time
      // through the loop, then stop the client:
      if (!client.connected() && lastConnected) {
        if(DEBUG){Serial.println();}
        if(DEBUG){Serial.println("disconnecting.");}
        client.stop();
      }
      lastConnected = client.connected();
}


//Function for sending the request to PushingBox
void sendToPushingBox(char devid[]){
  client.stop();
  if(DEBUG){Serial.println("connecting...");}

  if (client.connect(serverName, 80)) {
    if(DEBUG){Serial.println("connected");}

    if(DEBUG){Serial.println("sendind request");}
    client.print("GET /firebaseTest.php");//The other important bit
    client.print(devid);//This is the variable you'll be passing
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(serverName);
    client.println("User-Agent: Arduino");
    client.println();
  } 
  else {
    if(DEBUG){Serial.println("connection failed");}
  }
}
