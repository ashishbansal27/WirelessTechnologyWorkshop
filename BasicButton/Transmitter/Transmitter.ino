/*
* Wireless Technologies in Arduino Workshop
* Basic Button Test
Transmitter Code
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(8,10); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
}
void loop() {
 byte text = 0;
 Serial.println(digitalRead(A0));
 if( digitalRead(A0)){
  text = 1;
  
 }
 else{
  text= 0;
 }
  //char text[] = "Hello Ashish";
  radio.write(&text, sizeof(text));
  Serial.println("Sent");
  delay(100);
}

