// Main code to communicate with Cube Pilot and parachute ESPs

#include <Arduino.h>
#include <HardwareSerial.h>
#include <common/mavlink.h>

// #include <Streaming.h>
// #include <SPI.h>
// #include <SD.h>

// #define VERSION "0.0.1"

#include "params.h"
#include "util.h"
#include "linker.h"
#include "autopilot_interface.h"

HardwareSerial PiSerial(2); // UART2
HardwareSerial CubeSerial(2); // UART2

Linker linker;
Autopilot_Interface pixhawk(&linker);

void setup() {
    Serial.begin(57600);
    PiSerial.begin(15200, SERIAL_8N1, 4, 2); 
    CubeSerial.begin(57600, SERIAL_8N1, 16, 17);
    delay(1000);
}

Mavlink_Messages msg;

String drop_point = "";
String des_drop_point;
int bottle_num;
double lat, lon, heading;
double wind_speed, wind_heading;
double des_lat, des_lon, des_heading;

void loop() {

    while (drop_point == "") {
        if (PiSerial.available() > 0) {
            drop_point = Serial.readStringUntil('\n');
        }
    }
    // TODO: Convert drop point data to doubles

    msg = pixhawk.read_messages();
    Serial.println(msg.attitude.roll);
    // TODO: Get windspeed
    // calc_des_drop_state();

    // TODO: Convert desired drop point data to string
    PiSerial.println("Desired drop point and heading");

    // TODO: Monitor until close enough to drop point and relese payload

}


