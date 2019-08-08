#include <SPI.h>  
#include "RF24.h"

RF24 myRadio (8,10);
byte addresses[][6] = {"00001", "00002"};

struct package {

  char  text[300] = "";
};


typedef struct package Package;
Package dataRecieve;
Package dataTransmit;

void setup() {
  Serial.begin(9600);
  delay(1000);
  
  myRadio.begin();  
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS );
  
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();
}

void loop() {
  if ( myRadio.available()) {
    Serial.print("Other:");
    while (myRadio.available()){
      myRadio.read( &dataRecieve, sizeof(dataRecieve) );
      
      Serial.print(dataRecieve.text);
    }
    Serial.println();

  }

  delay(200);

  myRadio.stopListening();

 char inData[300];
  int index = 0;
  if(Serial.available()){
     Serial.print("Me:");
    
  
  while (Serial.available() >= 1) {
    if (index < 500) {
   
     inData[index] = Serial.read();
      index++;
      inData[index] = '\0';
      sprintf(dataTransmit.text, "%s", inData);
    }
      
   
    }
     myRadio.openWritingPipe(addresses[0]);
      myRadio.write(&dataTransmit, sizeof(dataTransmit));
      Serial.print(dataTransmit.text);
     // delay(10);
    Serial.println();
  }
    
    
  
  
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();
}
