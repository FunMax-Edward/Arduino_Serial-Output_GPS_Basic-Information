# Arduino_Serial-Output_GPS_Basic-Information
 
Based on UBLOX-M10, print latitude and longitude, altitude, time, compass 

I'm using esp32-S3,but it's basically universal for microcontrollers written using the arduino framework. 

Reference for the connection between the microcontroller and the GPS module

Here you need to add the library TinyGPSPlus by Mikal Hart

MCU------->GPS 

RT-------->XT 

XT-------->RT 

3.3/5V---->VCC 

gnd------->gnd
