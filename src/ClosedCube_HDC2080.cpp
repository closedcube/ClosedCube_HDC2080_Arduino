/*

Arduino library for Arduino library for Texas Instruments HDC2080 ±2% Ultra-Low Powered Digital Humidity and Temperature Sensor
version 2020.5.8

---

Copyright (c) 2018-2020, ClosedCube
All rights reserved.

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, 
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, 
   this list of conditions and the following disclaimer in the documentation and/or 
   other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors 
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <stdint.h>
#include "ClosedCube_HDC2080.h"

ClosedCube::Sensor::HDC2080::HDC2080() {
}

ClosedCube::Sensor::HDC2080::HDC2080(ClosedCube::Driver::I2CDevice device): _sensor(device) {    
}

ClosedCube::Sensor::HDC2080::HDC2080(uint8_t address) {
    _sensor.address(address);
}

void ClosedCube::Sensor::HDC2080::address(uint8_t address) {
    _sensor.address(address);
}

void ClosedCube::Sensor::HDC2080::config( ClosedCube::Sensor::HDC2080::Configuration config) {
    _sensor.writeByteToReg(0x0F,config.rawData);
}

float ClosedCube::Sensor::HDC2080::readT() {
    return readTemperature();
}

float ClosedCube::Sensor::HDC2080::readTemperature() {
    uint16_t t =  (_sensor.readByteFromReg(0x01,5) << 8) | _sensor.readByteFromReg(0x00,5);   
    
    return (float)(t / pow(2,16))*165.0f-40.0f;
}

float ClosedCube::Sensor::HDC2080::readRH() {
    return readHumidity();
}

float ClosedCube::Sensor::HDC2080::readHumidity() {
    uint16_t rh =  (_sensor.readByteFromReg(0x03,5) << 8) | _sensor.readByteFromReg(0x02,5);   
    return (float)(rh / pow(2,16))*100.0f;
}

uint16_t  ClosedCube::Sensor::HDC2080::getDeviceId() {
    uint16_t device_id = (_sensor.readByteFromReg(0xFF) << 8) | _sensor.readByteFromReg(0xFE);   
    return device_id;
}

uint16_t  ClosedCube::Sensor::HDC2080::getManufacturerId() {
    uint16_t manuf_id = (_sensor.readByteFromReg(0xFC) << 8) | _sensor.readByteFromReg(0xFD);   
    return manuf_id;
    
}


            