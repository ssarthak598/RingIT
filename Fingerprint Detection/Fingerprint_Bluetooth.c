#include <SoftwareSerial.h>
#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"
char *idi;
// Hardware setup - FPS connected to:
//    digital pin 4(arduino rx, fps tx)
//    digital pin 5(arduino tx - 560ohm resistor fps tx - 1000ohm resistor - ground)
//    this brings the 5v tx line down to about 3.2v so we dont fry our fps
SoftwareSerial mySerial(10, 11);
SoftwareSerial RF(2, 3);
FPS_GT511C3 fps(4, 5);

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  RF.begin(9600);
  delay(100);
  fps.Open();
  fps.SetLED(true);
}

void loop()
{

  // Identify fingerprint test
  if (fps.IsPressFinger())
  {
    fps.CaptureFinger(false);
    int id = fps.Identify1_N();
    if (id <200)
    {
      Serial.print("Verified ID:");
      Serial.println(id);
      mySerial.print(id);
      RF.println(id);
     
      
    }
    else
    {
      Serial.println("Finger not found");
    }
  }
  else
  {
    Serial.println("Please press finger");
  }
  delay(100);
}

