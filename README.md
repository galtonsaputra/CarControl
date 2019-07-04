# Car Controller

### Description
This solution provides a single entry for a RC 4x4 toy car, broadcasting J2735 messages utilising 802.11ac. A Raspberry Pi 3 Model B+ is mounted on each vehicle, serving as the RC controller, as well as determining actor types (Good/Bad). 

## Background Usage
Within a Wireless Access Vehicular Environment (WAVE), each participating vehicle is equipped with an OnBoard Unit (OBU) to enable vehicular communication (V2V). The prototype developed below uses a RPi to simulate the following OBU function:
* Communicate and receive SAE J2735 messages from connected vehicles in RSU Server
* Wireless control of the vehicle using 802.11ac 
* Provides a hub for sensors + component to be integrated to the car

## Installation</br>
### Development Env Setup
* Visual Studio 2017
* [VNC Viewer](https://www.realvnc.com/en/connect/docs/raspberry-pi.html) - headless setup to enable full remote desktop</br>
For SSH setup please see [here](https://www.raspberrypi.org/documentation/remote-access/ssh/) or [here](https://www.raspberrypi.org/magpi/ssh-remote-control-raspberry-pi/).
* WSL – Windows Subsystem for Linux </br>
The above setup allows remote build and debugging straight from VS into a RaspberryPi. Using WSL, it provides a compatibility layer allowing kernel calls to be translated and executed straight inside a Linux kernal through Windows. If you are using the latest Windows version of Linux, this setup may not be necessary. Please check compatibility and need for installation [here](https://www.theverge.com/2019/5/6/18534687/microsoft-windows-10-linux-kernel-feature).
* Build and debug remotely to your [RaspberryPi](https://docs.microsoft.com/en-us/cpp/linux/connect-to-your-remote-linux-computer?view=vs-2019)</br>

### Physical Setup
**PI Requirements** 
* Raspberry Pi 3 Model B+
* 1 x 32GB MicroSD etched with Raspian Stretch [Kernel version: 4.14]
* 4 x SPDT 3A micro switch with lever wired to RPi GPIO pins
* gcc [v6.3.0]

**Sensors & Wiring Diagram**
- LC298 - Motor Car Controller
- XC4434 - Hall Sensor </br>
The above sensors are wired using the below wiring diagram. </br>
![alt text](https://github.com/galtonsaputra/CarControl/blob/master/CarControl/assets/Wiring%20Diagram%20CarController.PNG "CarControl Wiring Diagram")</br>

### Initial Config
Once the above have been wired and the code have been remotely compiled to the RaspberryPi, please check the following configuration:</br>
- RSU server starts by opening and listening on PORT: 8080
- To ensure pins are mapped to its designated GPIO pins, please run
```Linux cmd
gpio readall
```
- Please note that the pin number specified at code, maps to WiringPi numbering (WPi). Additionally, running the above code will also gives you a Broadcom representation of the pins. 

### Wireless Config
- Ensure that your RaspberryPi and computer is on the same network
- To obtain the IP of your RP, open your router configuration and navigate to DHCP.


## Running the car
1. Open Terminal
2. Navigate to the directory where your build outputs to. </br>
The below navigation path is where VS Cross-Platform Manager builds and outputs to. 
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

### Demonstrator limitation
- Does not utilise 802.11p and does not conform to IEEE1609 Family of Standards.
- Bad speed reading does not mean a vehicle is a bad actor (e.g. faulty sensor).
- Inspecting only J2735 - BSM safety messages and verifying its speed field against independent sensor readings.
