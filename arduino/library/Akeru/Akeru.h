/* This file started from Akeru library http://akeru.cc copyleft Snootlab, 2014
 and has been modified for droneRescue by Stephane D, 2014.
 
 This library is free software: you can redistribute it and/or
 modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License along
 with droneRescue.  If not, see <http://www.gnu.org/licenses/>.*/

#ifndef AKERU_H
#define AKERU_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class Akeru {
    public:
        Akeru(uint8_t rxPin, uint8_t txPin);
        ~Akeru();
        int begin();
        bool isReady();
        bool send(const void* data, uint8_t len);
        uint8_t getRev();
        unsigned long getID();
        bool setPower(uint8_t power);

        enum RETURN_CODE {
            OK = 'O',
            KO = 'K',
            SENT = 'S'
        };

    private:
        SoftwareSerial _serial;
        unsigned long _lastSend;
        uint8_t _rxPin;
        uint8_t _txPin;
        uint8_t _nextReturn();
};

#endif
