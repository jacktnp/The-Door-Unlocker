/*Transmitter nano*/
#include <RF24.h>
#include <SPI.h>
// #include <nRF24L01.h>

#define CE 7
#define CSN 8

RF24 radio(CE, CSN);// CE, CSN

const byte address[6] = "00001";

void setup() {
    radio.begin();
    radio.setRetries(15,15);
    radio.setPALevel(RF24_PA_MIN); // nRF range
    radio.setDataRate(RF24_250KBPS);
    radio.openWritingPipe(address);
    radio.stopListening();
}

void loop() {
    const char text[] = "connected";
    radio.write(&text, sizeof(text));
    delay(1000);
}