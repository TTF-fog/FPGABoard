#include "Arduino.h"
#include "SPI.h"
#include "SPIFFS.h"
#define CS 14
#define CRESET_B 17
void delayNanoseconds(int ns) {
    delay(ns/1000);
}
void setup() {
    while (!Serial.begin(9600)){}
    SPIClass flash;
    pinMode(CS, OUTPUT);
    pinMode(CRESET_B, OUTPUT);
    flash.begin(15, 16, 12, CS);
    SPIFFS.begin();
    File bitstream = SPIFFS.open("stream", "r");
    digitalWrite(CS, LOW);
    digitalWrite(CRESET_B, LOW);
    Serial.println("FPGA reset"); //note: check if logging could caause timing issues
    delayMicroseconds(200);
    digitalWrite(CRESET_B, HIGH);
    Serial.println("SPI peripheral mode");
    delayMicroseconds(1200);
    SPISettings settings = SPISettings(4000000, MSBFIRST, SPI_MODE0);{};
    flash.beginTransaction(settings);
    flash.transferBytes(bitstream.readBytes());
    flash.endTransaction();
    Serial.println("transferred");
    pinMode(18, INPUT);
    while (digitalRead(18) == LOW) {Serial.println("error while programming");}
    char dummy[48];
    flash.beginTransaction(settings);
    flash.transferBytes(dummy,0,sizeof(dummy));
    flash.endTransaction();
    Serial.println("done programming!");
}
void loop(){}