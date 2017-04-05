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

int timer = 0; //variable to keep track of time 
/*Function: Function is used for any setup code to run once. This will set up all inputs and outputs etc
*/
void setup(){
	setOnAndOffButton;
	setModeButton;
	setConnectionButton;
}

void loop(){
	//Do main Code Stuff here
	if(digitalRead(setOnAndOffButton) == HIGH){
		display(1);
	}else{
		display(2);
	}
	if(digitalRead(seConnectionButton) == HIGH){		
		//call hub connection function
			timer++;						
}

/*Function: This function  

void buttonPress(){
}

/*Function: This function connects or disconnects the device to and from the hub. It will be called whenever 
the connect button is pressed. When connection is made, the function lights up the connection light on the device.
*/  
void connectionToHub(){
//light up connection made light
}

/*Function: This function is used to display on the seven seg display. It takes in a value of either 1, 2, 3, 4 or 5.
A value of 1 means display ON, 2 means display OFF, 3 means display temperature, 4 means battery level, and 5 means 
display device identification.
*/
void display(int dispChoice){
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

