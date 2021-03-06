/**
 *  File: main.cpp
 * 
 *  Author: Thomas Kost
 *  
 *  Date: 25 March 2021
 *  
 *  @brief main loop for LASSIE
 *
 */

#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <Wire.h>
#include <MotorMixer.h>

// Define and declare globals

// Pin numbers
#define LF_MOTOR 2
#define RF_MOTOR 4
#define LR_MOTOR 5
#define RR_MOTOR 6
#define CSN      8
#define CE       10
#define LOW_POWER_LED 32

// Memory Allocation

// Motor Mixer
MotorMixer motors(LF_MOTOR, RF_MOTOR, LR_MOTOR, RR_MOTOR);

// Comms Global Variables
RF24 radio(CE, CSN);   // nRF24L01 (CE, CSN)
const byte address[6] = "00001";

unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;

struct Data_Package {
  // Max size of this struct is 32 bytes - NRF24L01 buffer limit
  unsigned short j1PotX;
  unsigned short j1PotY;
  unsigned short j2PotX;
  unsigned short j2PotY;

 // note can combine button states into a single byte (only need one bit per reading)
  byte j1Button;
  byte j2Button;
  byte pot1;
  byte pot2;
  byte tSwitch1;
  byte tSwitch2;
  byte button1;
  byte button2;
  byte button3;
  byte button4;
};
// Allocate Reciever Data buffer
Data_Package data;

// function declarations
void resetData();

void setup() {
  Serial.begin(9600);

  // Setup Radio:
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening(); //  Set the module as receiver
  resetData();
}

void loop() {
  // Check whether there is data to be received
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package)); // Read the whole data and store it into the 'data' structure
    lastReceiveTime = millis(); // At this moment we have received the data
  }
  // Check whether we keep receving data, or we have a connection between the two modules
  currentTime = millis();
  if ( currentTime - lastReceiveTime > 1000 ) { // If current time is more then 1 second since we have recived the last data, that means we have lost connection
    resetData(); // If connection is lost, reset the data. It prevents unwanted behavior, for example if a drone has a throttle up and we lose connection, it can keep flying unless we reset the values
  }
  // Print the data in the Serial Monitor
  Serial.print("j1PotX: ");
  Serial.print(data.j1PotX);
  Serial.print("; j1PotY: ");
  Serial.print(data.j1PotY);
  Serial.print("; button1: ");
  Serial.print(data.button1);
  Serial.print("; j2PotX: ");
  Serial.println(data.j2PotX); 
}



void resetData() {
  // Reset the values when there is no radio connection - Set initial default values
  data.j1PotX = 127;
  data.j1PotY = 127;
  data.j2PotX = 127;
  data.j2PotY = 127;
  data.j1Button = 1;
  data.j2Button = 1;
  data.pot1 = 1;
  data.pot2 = 1;
  data.tSwitch1 = 1;
  data.tSwitch2 = 1;
  data.button1 = 1;
  data.button2 = 1;
  data.button3 = 1;
  data.button4 = 1;
}