/* This is a code for acceleromter testing on a smaller robot with an LCD screen for data vizualisation */

// Library import
#include <wire.h>               // I2C communication
#include "SparkFun_MMA8452Q.h"  // Proccess results from the accelerometer board
#include <LiquidCrystal.h>      // Enables use of LCD Display

// Create an instance of the MMA8452 class
MMA8452Q accel;

// Initialize LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Variables



// Setup
void setup() {
  lcd.begin(16, 2);             // set up the LCD's number of columns and rows
  wire.begin();                 // start I2C communcation
  accel.init();                 // Default init: +/-2g and 800Hz ODR
}


// Loop
void loop() {

}
