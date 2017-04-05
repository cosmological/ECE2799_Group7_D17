/*Peripheral Thermostat System
Auxillary Device
*Collects temperature data and sends it to HUB
*Interprets data from internal and external temperature sensors
**Puts data into packet
**Sends packet

Group 7
Joseph Asante
Peter Emidy
Abdul Hassan
*/

//declare variables, some variables for the LEDs and buttons will be added later
int timer = 0; //variable to keep track of time 
int connectVar = 0;
int mode = 0;
/*Function: Function is used for any setup code to run once. This will set up all inputs and outputs etc
*/
void setup(){
	setOnAndOffButton;
	setModeButton;
	setConnectionButton;
	setLEDS;
}

void loop(){
	//Do main Code Stuff here
	
	//Code for turning system on and off
	if(digitalRead(setOnAndOffButton) == HIGH){ //Do this when the power button is pressed
		turnOnPowerLED; //turn on power LED
		turnOn7segDisplay;//turn on 7 seg display
		display(1);//display ON on the 7 seg display
	}else if(digitalRead(setOnAndOffButton) == LOW){ //Do this when the power button is unpressed
		display(2);//display OFF on the 7 seg display
		turnOff7segDisplay;//turn off 7 seg display
		turnOffPowerLED; //turn off power LED
	}
	
	//Code for making connection to the hub
	if(digitalRead(setConnectionButton) == HIGH){//Do this when the connection button is pressed		
		connectionVar++;
	}
	if(connectionVar%2 == 1){	
		if(connectionToHub(1) == 1){ //Do this if connection to the hub is successful
			turnOnConnectionMadeLED; //turn on LED to indicate that connection was made
			sendPacket(deviceInfo);
		}
	}else if (connectionVar%2 == 0){ //if the connection button is unpressed
		if(connectionToHub(0) == 1){ //Do this if disconnection is successful
			turnOffConnectionLED; //trun connection LED off
		}
	}
		
	//Code for measuring temperature	
	if(timer%5 == 0){
		acquireTemp();
		sendPacket(temperatureReading);
	}
	
	//Code for changing mode
	if(digitalRead(setModeNutton) == HIGH){
		mode++;
	}
	if(mode%3 == 0){
		display(3); //display temperature
	}else if (mode%3 == 2){
		display(4);//display battery level
	}else{
		display(5);//display device ID
	}
	timer++;					
}

/*Function: This function connects or disconnects the device to and from the hub. It will be called whenever 
the connect button is pressed. When connection is made, the function lights up the connection light on the device.
Arguments: When conOrDiscon is set to 1, connection to the hub is attempted. When set to zero, it is diconnected.
Returns: 1 if connection was made or zero if connection was not made*/  
int connectionToHub(int conOrDiscon){
	if(conOrDiscon == 0){ //Do this if conOrDiscon is 0
		turnOffConnection;//turn off connection to the HUB
	}else{ //Do this if conOrDiscon is 0		
		turnOnConnection;//turn on connection to the HUB
	}
}

/*Function: This function is used to display on the seven seg display. It takes in a value of either 1, 2, 3, 4 or 5.
A value of 1 means display ON, 2 means display OFF, 3 means display temperature, 4 means battery level, and 5 means 
display device identification.
*/
void display(int dispChoice){
	if(dispChoice == 1){
		displayON; //write ON unto the 7 seg display
	}else if (disChoice == 2){
		displayOFF; //write OFF unto the 7 seg display
	}else if(dispChoice == 3){
		displayTemperatureReading; //write temperature read on the 7 seg display
	}else if(dispChoice == 4){
		displayBatteryLevel; //show battey level on 7 seg display
	}else{
		displayDeviceID; //show device ID on 7 seg display
	}
}

/*Function: This function triggers the temperature sensor to measure the temperature of its surrounding
every five minutes
Returns: An integer which is the recorded value of the temperature
*/
int acquireTemp(){
}

/*Function: This function receives information (data) from the temperature sensor and sends 
it to the hub. Function will be called everytime after temperature is measured by the sensor (every 5 minutes)
*/
void sendPacket(packet){
}

