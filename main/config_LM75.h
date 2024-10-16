/*
  OpenMQTTGateway Addon  - ESP8266 or Arduino program for home automation

   Act as a gateway between your 433mhz, infrared IR, BLE, LoRa signal and one interface like an MQTT broker
   Send and receiving command by MQTT

   This is a Temperature Addon:
   - Measures Temperature
   - Generates Values for: Temperature in degrees C and F
   - Required Hardware Module: LM75 or NCT75
   - Required Library: jeremycole/I2C Temperature Sensors derived from the LM75

   Connection Schemata:
   --------------------

   LM75 ------> ESP8266
   ======================
   Vcc ---------> Vu (5V)
   GND ---------> GND
   SCL ---------> D1
   SDA ---------> D2

    This file is part of OpenMQTTGateway.

    OpenMQTTGateway is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenMQTTGateway is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef config_LM75_h
#define config_LM75_h

extern void setupLM75();
extern void LM75toX();

#define lm75_always            true // if false when the current value of the parameter is the same as previous one don't send it by MQTT
#define TimeBetweenReadinglm75 30000

/*----------------------------USER PARAMETERS-----------------------------*/
/*-------------DEFINE YOUR MQTT PARAMETERS BELOW----------------*/
#define LM75TOPIC "/TEMPtoMQTT/lm75"

#if defined(ESP32)
#  if !defined(I2C_SDA) || !defined(I2C_SCL)
#    define I2C_SDA 16
#    define I2C_SCL 0
#  endif
#endif

#endif