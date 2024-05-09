#include <SoftwareSerial.h>
#define BLYNK_PRINT Serial

//Install the following Libraries
#include <TinyGPS++.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//GPS RX to D1 & GPS TX to D2 and Serial Connection
const int RXPin = 4, TXPin = 5;
const uint32_t GPSBaud = 9600; 
SoftwareSerial gps_module(RXPin, TXPin);

TinyGPSPlus gps; 
WidgetMap myMap(V0); //V0 - virtual pin for Map

BlynkTimer timer;

//Variable  to store the speed, no. of satellites, direction
float gps_speed;
float no_of_satellites;
String satellite_orientation;

char auth[] = "SrnBLffPHDIZ-St8K65KY1kUl4iB3XWh";              
char ssid[] = "mesh_2.4ghz";
char pass[] = "thunderclap";

//unsigned int move_index;         
unsigned int move_index = 1;      
  

void setup()
{
  Serial.begin(115200);
  Serial.println();
  gps_module.begin(GPSBaud);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(5000L, checkGPS); 
}

void checkGPS(){
  if (gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
      Blynk.virtualWrite(V4, "GPS ERROR");  
  }
}

void loop()
{
  while (gps_module.available() > 0) 
  {
    //displays information every time a new sentence is correctly encoded.
    if (gps.encode(gps_module.read()))
    displayInfo();
  }
  
  Blynk.run();
  timer.run();
}

void displayInfo()
{
  if (gps.location.isValid()) 
  {
    //Storing the Latitude. and Longitude
    float a = (gps.location.lat());
    float b = (gps.location.lng()); 
    
    //Send to Serial Monitor for Debugging
    Serial.print("LAT:  ");
    Serial.println(a, 6);  // float to x decimal places
    Serial.print("LONG: ");
    Serial.println(b, 6);
    
    Blynk.virtualWrite(V1, (a, 6));   
    Blynk.virtualWrite(V2, (b, 6)); 
    float longitude=(a, 6);
    float latitude =(b, 6);
    Serial.println (latitude, 6);
    myMap.location(move_index, latitude, longitude, "GPS_Location");
    
    //get speed
    gps_speed = gps.speed.kmph();
    Blynk.virtualWrite(V3, gps_speed);
       
    //get number of satellites
    no_of_satellites = gps.satellites.value();
    Blynk.virtualWrite(V4, no_of_satellites);

    // get the satellite orientation/direction
    satellite_orientation = TinyGPSPlus::cardinal(gps.course.value());
    Blynk.virtualWrite(V5, satellite_orientation);
  }
  
  Serial.println();
}
