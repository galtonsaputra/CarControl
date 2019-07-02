# Car Controller

### Description:
This solution provides a single entry for a RC 4x4 toy car, broadcasting J2735 messages utilising 802.11ac. A Raspberry Pi 3 Model B+ is mounted on each vehicle, serving as the RC controller, as well as determining actor types (Good/Bad). 

#### Table of Contents
Background </br>
Installation </br>
Actor configuration </br>

## Background
Why this was created?

## Usage Overview</br>
### Development Env Setup
CarController was tested and developed using the following materials and tools: </br>
* Visual Studio 2017 with remote build configuration
* WSL – Windows Subsystem for Linux 
Note that the above setup allows remote build and debugging straight from VS and into the RaspberryPi. Using WSL, it provides a compatibility layer allowing kernel calls to be translated and executed straight inside a Linux environment through Windows. If you are using the latest Windows version of Linux, this may not be the case, as they may come shipped with your built, please check compatibility and need for installation here.
https://www.theverge.com/2019/5/6/18534687/microsoft-windows-10-linux-kernel-feature

### Physical Setup
**PI Requirements** 
* Raspberry Pi 3 Model B+
* 1 x 32GB MicroSD etched with Raspian Stretch [Kernel version: 4.14]
* 4 x SPDT 3A micro switch with lever wired to RPi GPIO pins
* gcc [v6.3.0]

**Car Sensor**
- LC298 - Motor Car Controller
- Arduino 4x4 Car Chassis
- XC 443 Hall Sensor

**Wiring Diagram**
Wiring Diagram - png
</br>
### Initial Config
Once the above have been wired and the code have been compiled to the RaspberryPi, please check the following server configuration:</br>
- RSU server starts by opening and listening on PORT: 8080
- To obtain GPIO pin mapping and its state, please run
```Linux cmd
gpio readall
```
- Please note that the pin number specified at code, mapps to WiringPi numbering (WPi). Additionally, running the above code will also gives you a Broadcom representation of the pins. 


Speed conversion reading
A speed conversion table is needed to translate the current being parsed as the integer to the PWM pin. A linear distance is needed to …

### Demonstrator's limitation
- Does not utilise 802.11p and does not conform to IEEE1609 Family of Standards.
- Bad speed reading does not mean a vehicle is a bad actor (e.g. faulty sensor).
- Inspecting only J2735 - BSM safety messages and verifying its speed field against independent sensor readings.


## Running the car
1. Open Terminal
2. Navigate to the directory where your build outputs to. </br>
The below navigation path is using VS Cross-Platform Manager and where it builds and outputs to. 
```Linux cmd
cd /home/pi/projects/CarControl/bin/ARM/Debug/CarControl.out
```
3. To run the car, paste the following:
```Linux cmd
sudo CarControl.out
```
4. To navigate please use the following controls within the terminal to manouvre
```Controls
8 - Forward/Start
2 - Reverse
4 - Left
6 - Right
5 - Stop
7 - Accelerate
9 - Deccelerate
```
