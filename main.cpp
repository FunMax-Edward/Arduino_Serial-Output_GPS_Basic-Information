#include <Arduino.h>
#include <TinyGPS++.h>


//The serial port here is manually mapped by me, which is a feature of the esp32S3, of course you can use the default pins  
#define UART_RX_PIN 18 // GPIO18
#define UART_TX_PIN 17 // GPIO17

TinyGPSPlus gps; // Create a TinyGPSPlus object

void printGPSData();

void setup() {
    Serial.begin(38400); // Connects to the computer，It's customizable,and the baud rate doesn't have to be the same as the one below
    Serial2.begin(38400, SERIAL_8N1, UART_RX_PIN, UART_TX_PIN); // Connects to external GPS device,我的GPS默认波特率为38400
}


void loop() {
    while (Serial2.available() > 0) {
        char c = Serial2.read(); // Read a character from the GPS device
        if (gps.encode(c)) { // Feed the GPS character into TinyGPS++ decoder
            printGPSData(); // Function to print all available GPS data
        }
    }
}

void printGPSData() {
    // Check if location data is valid
    if (gps.location.isValid()) {
        Serial.print("Latitude: ");
        Serial.println(gps.location.lat(), 6); // Print latitude with 6 decimal places
        Serial.print("Longitude: ");
        Serial.println(gps.location.lng(), 6); // Print longitude with 6 decimal places
    } else {
        Serial.println("Invalid location data.");
    }

    // Check if altitude data is valid
    if (gps.altitude.isValid()) {
        Serial.print("Altitude: ");
        Serial.println(gps.altitude.meters()); // Print altitude in meters
    } else {
        Serial.println("Invalid altitude data.");
    }

    // Check if time is valid
    if (gps.time.isValid()) {
        Serial.print("Time: ");
        Serial.print(gps.time.hour() + 8); // Assuming GMT+8 for China, adjust as needed
        Serial.print(":");
        Serial.print(gps.time.minute());
        Serial.print(":");
        Serial.println(gps.time.second());
    } else {
        Serial.println("Invalid time data.");
    }

    // Print course (Compass information)
    if (gps.course.isValid()) {
        Serial.print("Compass Heading: ");
        Serial.println(gps.course.deg()); // Print course in degrees
    } else {
        Serial.println("Invalid compass data.");
    }
}
