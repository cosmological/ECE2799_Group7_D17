/*Peripheral Thermostat System
Smart Hub - The brains of the system 
*Collects Data from all auxilary sensors and interprets itoa
*Allows for user interaction
**Set sensor target temperatures
**Name sensors
**View sensor information

Group 7
Joseph Asante
Peter Emidy
Abdul Hassan
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct packet {
	int temp1; 	//Temperature being read (internal)
	int temp2; 	//Temperature being read (external)
	int id;		//Identification of the sensor
	int battery;	//Remaining battery percentage
} Packet;

typedef struct sensor {
	char name[20];	//User input name for sensor
	//Data from packet
	int temp1; 	//Temperature being read (internal)
	int temp2; 	//Temperature being read (external)
	int id;		//Identification of the sensor
	int battery;	//Remaining battery percentage
	//Data for HUB
	int priority;		//The priority value of the sensor
	int targetTemp;	//The target temperature for the sensor	
} Sensor;

int main() {
	//Define variables
	while(1) {
		//Interpret and Display incoming data
	}		
}
//Functions
int rand_int(int max) {	//Generates a random between 0 and max
	return (rand() % max);
	
Packet rand_packet(int id) { //returns a random packet from an input id
	Packet ret;
	ret->temp1 = rand_int(90);
	ret->temp2 = rand_int(90);
	ret->id = id;
	ret->battery = rand_int(100);
}
void print_packet(Packet prt) {	//Prints the info of a given packet
	printf("The internal temperature is: %d", prt->temp1);
	printf("The external temperature is: %d", prt->temp2);
	printf("The identification number is: %d", prt->id);
	printf("The battery level is: %d", prt->battery);
}

