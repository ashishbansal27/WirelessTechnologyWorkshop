#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(8,10); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    byte text;
    radio.read(&text, sizeof(text));
    if(text) 
    Serial.println("Pressed");
    else
    Serial.println("Not Pressed");
   
  }
}
