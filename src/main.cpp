#include <Arduino.h>
#include "DigiCDC.h"
#include "TinyBMP280.h"

// Objeto do sensor barométrico
tbmp::TinyBMP280 barometer;

// Rotina que incicia por USB e Sensor barométrifo
void setup() {
    // Inicia porta USB
    SerialUSB.begin();

    // Inicializa sensor barométrico bmp280
    barometer.begin();
}

// Rotina que se repete infinitamente
void loop() {
    // Efetua leitura do sensor barométrifo
    uint32_t pressao = barometer.readIntPressure(); //em Pa,float

    // Envia dados pro USB-CDC
    SerialUSB.print("PRS "); // BlueFlyDevice XCSoar ou XCTrack
    SerialUSB.println(pressao,HEX);

    // Aguarda 250ms
    SerialUSB.delay(250);
}
