# LASSIE

**L**ong r**A**nge **S**elf-**S**tabilizing **I**nertial and **E**ffigy sensor based quadcopter (LASSIE) is designed with the goal of creating a quadcopter that is both fun to fly and capable of autonomous path determination based upon image data. 

![A Quadcopter](https://en.wikipedia.org/wiki/File:Lassie.jpg)

## Usage

The software for this is designed to be run on a teensy 4.1 (as described in the [Hardware](#hardware) section). All contol logic is intended to be implemented on this hardware. Additional libraries can be compiled and used using the following steps: 

1. Clone the repository to your device:

```
git clone git@github.com:thomaskost17/LASSIE.git
```

2. Setup dependencies:

```
./setup.sh
```

3. compile project:

```
TODO: ** CMAKE INSTRUCTIONS TO COMPILE AND VIEW RESULTS **
```

## Hardware

The hardware and associated documentation can be found in the `hardware_documentation` directory. A short summary of the hardware is provided below:

 - NRF24L01 Wireless Reciever
 - Teensy 4.1
 - Raspberry Pi Zero W
 - MPU6050
 - Logitec Webcam
 - Tof Sensor (tenative)
 
 Note: The design for the transmitter and quadcopter itself can be found on EasyEDA. The scematics will be linked once finalized.

## Control Law

## Estimation

