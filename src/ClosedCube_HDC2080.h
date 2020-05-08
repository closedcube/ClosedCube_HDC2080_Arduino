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

#ifndef CLOSEDCUBE_HDC2080_ARDUINO_H
#define CLOSEDCUBE_HDC2080_ARDUINO_H

#include "ClosedCube_I2C.h"

namespace ClosedCube {

    namespace Sensor {

        class HDC2080 {
        
        public:

            typedef union {
                uint8_t rawData;
                struct {
                    uint8_t Measurement_Trigger : 1;
                    uint8_t Measurement_Configuration : 2;
                    uint8_t Reserved : 1;
                    uint8_t Humidity_Resolution : 2;
                    uint8_t Temperature_Resolution : 2;
                };
            } Configuration;

            HDC2080();
            HDC2080(uint8_t address);
            HDC2080(ClosedCube::Driver::I2CDevice device);

            void address(uint8_t address);

            void config(Configuration config);

            float readTemperature();
            float readT();

            float readHumidity();
            float readRH();

            uint16_t getDeviceId();
            uint16_t getManufacturerId();

        private:
            ClosedCube::Driver::I2CDevice _sensor;
            
        };
    }
}


#endif
