#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
BlynkTimer timer;
#include <TinyGPS++.h>

const int RXPin = 0, TXPin = 4;//gps
int Vsensor = A0;

int pbuttonPin = 1;// connect output to push button
int relayPin = 3;// Connected to relay 


int val = 0; // push value from pin 2
int lightON = 0;//light status
int pushed = 0;//push status


const uint32_t GPSBaud = 9600; 
SoftwareSerial gps_module(RXPin, TXPin);

TinyGPSPlus gps; 
WidgetMap myMap(V0); //V0 - virtual pin for Map


//Variable  to store the speed, no. of satellites, direction
float gps_speed;
float no_of_satellites;
String satellite_orientation;
unsigned int move_index = 1;//gps





 //volt

//For 0-25v voltage sensor
 float correctionfactor = 8.6800; 
float vout = 0.0; 
float vin = 0.0; 


 // two resistors 30K and 7.5k ohm
float R1 = 30000;  //   
float R2 = 7500; //  
int value = 0; //volt

char auth[] = "SrnBLffPHDIZ-St8K65KY1kUl4iB3XWh";              
char ssid[] = "mesh_2.4ghz";
char pass[] = "thunderclap";



void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, millis() / 1000);
  
}



void setup()
{
  // Debug console
Serial.begin(9600);
  Serial.println();
  gps_module.begin(GPSBaud);
pinMode(Vsensor, INPUT); 

  Blynk.begin(auth, ssid, pass);

    timer.setInterval(1000L,sensorvalue1); 
    timer.setInterval(5000L, checkGPS); 

pinMode(pbuttonPin, INPUT_PULLUP); 
pinMode(relayPin, OUTPUT);
digitalWrite(relayPin, HIGH); 

}
void checkGPS(){//gps
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
   
    if (gps.encode(gps_module.read()))
    displayInfo();
  }
  
  Blynk.run();
  timer.run();

  {
  val = digitalRead(pbuttonPin);// read the push button value

  if(val == HIGH && lightON == LOW){

    pushed = 1-pushed;
    delay(100);
  }    

  lightON = val;

      if(pushed == HIGH){
        Serial.println("Light ON");
        digitalWrite(relayPin, LOW); 
       
      }else{
        Serial.println("Light OFF");
        digitalWrite(relayPin, HIGH);
   
      }     

  delay(100);
}


}
void displayInfo()//gps
{
  if (gps.location.isValid()) 
  {
    //Storing the Latitude. and Longitude
    float latitude = (gps.location.lat());
    float longitude = (gps.location.lng()); 
    
    //Send to Serial Monitor for Debugging
    Serial.print("LAT:  ");
    Serial.println(latitude, 6);  // float to x decimal places
    Serial.print("LONG: ");
    Serial.println(longitude, 6);
    
    Blynk.virtualWrite(V1, String(latitude, 6));   
    Blynk.virtualWrite(V2, String(longitude, 6));  
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
}//gps

void sensorvalue1()//volt
{
int sdata = 0; 
   // read the value at analog input 
   value = analogRead(Vsensor); 
   vout = (value * 5.0) / 1023.0; // see text 
   vin = vout / (R2/(R1+R2));
 
    vin = vin - correctionfactor; 
Serial.print("INPUT V= "); 
Serial.println(vin,4); 
sdata = vin; 
Blynk.virtualWrite(V6, sdata);

}//volt
