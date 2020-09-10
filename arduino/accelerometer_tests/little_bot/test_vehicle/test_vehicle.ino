/* This is a code for acceleromter testing on a smaller robot with an LCD screen for data vizualisation */

// Library import
#include <Wire.h>               // I2C communication
#include "SparkFun_MMA8452Q.h"  // Proccess results from the accelerometer board
#include <LiquidCrystal.h>      // Enables use of LCD Display

// Create an instance of the MMA8452 class
MMA8452Q accel;

// Initialize LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Variables
const int buttonPin = 8;
int buttonStatus = 0;
int buttonState = 0;

const int interval = 50;

const int motorPin = 9;
int speed;


// Setup
void setup() {
  lcd.begin(16, 2);             // set up the LCD's number of columns and rows
  Wire.begin();                 // start I2C communcation
  accel.init();                 // Default init: +/-2g and 800Hz ODR
  pinMode(buttonPin, INPUT);    // Initialize button pin for input
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  lcd.print("Button is ");
  
}


// Loop
void loop() {
  buttonCheck();
  lcd.setCursor(10,0);
  lcd.print(buttonStatus);
  delay(interval);

  printAcceleration();
  
}

// Extra functions
void buttonCheck() {
  buttonState = digitalRead(buttonPin);
  if ((buttonState == HIGH) && (buttonStatus == 1)) { 
    buttonStatus = 0;
   }
  else if ((buttonState == HIGH) && (buttonStatus == 0)) { 
    buttonStatus = 1;
  }
}

void printAcceleration() {
  Serial.print(accel.getCalculatedX());
  Serial.print('\t');
  Serial.print(accel.getCalculatedY());
  Serial.print('\t');
  Serial.print(accel.getCalculatedZ());
  Serial.print('\t');
  Serial.print(accel.getCalculatedX() + accel.getCalculatedY() + accel.getCalculatedZ());
  Serial.println();
}

void powah(int status) {
  if (status == 1) {
    analogWrite(motorPin, speed);
  }
  else if (status == 0) {
    analogWrite(motorPin, 0);
  }
}
