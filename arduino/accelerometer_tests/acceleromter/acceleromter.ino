#include <Wire.h>                 // Must include Wire library for I2C
#include "SparkFun_MMA8452Q.h"    //http://librarymanager/All#SparkFun_MMA8452Q

MMA8452Q accel;                   // create instance of the MMA8452 class

int interval = 500;
float acc;

int time;

float deltaV;
int v = -1;

void setup() {
  
  
  Serial.begin(9600);
  Serial.println("MMA8452Q Basic Reading Code!");
  Wire.begin();

  if (accel.begin() == false) {
    Serial.println("Not Connected. Please check connections and read the hookup guide.");
    while (1);
  }
  accel.init(); // Default init: +/-2g and 800Hz ODR
}

float StartTime = millis();
float CurrentTime;
float ElapsedTime;
float velocity = 0;


void loop() {
  if (accel.available()) {      // Wait for new data from accelerometer
    // We need acceleration in Y direction in terms of g units
    acc = accel.getCalculatedY();
    acc = acc / 64 * 980; //converts to cm/s^2
    CurrentTime = millis();
    ElapsedTime = CurrentTime - StartTime;
    // Attempt to calculate velocity
    if (abs(acc) > 1) {
      velocity += acc *(ElapsedTime/1000);
    }
    //Printing data
    delay(interval);
    Serial.print(acc);
    Serial.print('\t');
    Serial.print(ElapsedTime);
    Serial.print('\t');
    Serial.print(velocity);
    Serial.println();
    StartTime = CurrentTime;
    
  }
}