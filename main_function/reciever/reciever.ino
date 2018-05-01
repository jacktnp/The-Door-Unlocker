/*Reciever uno*/
#include <RF24.h>
#include <SPI.h>
// #include <nRF24L01.h>
#include <string.h>

//nrf
#define CE 7
#define CSN 8
#define MOSI 11
#define MISO 12
#define CLK 13 //SCK

//other
#define vib_pin A1 //vibration sensor
#define tone_pin 9 //buzzer

//mortor and potentiameter
#define stepPin  3
#define dirPin  5
#define poten A2
int customDelay, customDelayMapped;

//set password here
const int pass = 3;

RF24 radio(CE, CSN);// CE, CSN

const byte address[6] = "00001";

void setup() {
    Serial.begin(9600);
    radio.begin();
    radio.setRetries(15,15);
    radio.setPALevel(RF24_PA_MIN);
    radio.setDataRate(RF24_250KBPS);
    radio.openReadingPipe(0, address);
    radio.startListening();
}


void loop() {
    if (radio.available()) {
        while (radio.available()) {
            char reci[30] = "";
            radio.read(&reci, sizeof(reci));

            Serial.println(reci);
            Serial.println("Let knock to enter");
            int knocking_count = selector();
            Serial.println(knocking_count);
            if (knocking_count != 0) {
                if (knocking_count == pass) {
                  for (int i=0;i<4;i++)tonePin();
                    Serial.println("unlocking");
                    mortorRoll();
                }
            }
        } Serial.println("Remote is not in range or connection lost.");
    }
    delay(500);
}
