/**
 * Author: Jarid Bredemeier
 * Date: Thursday, February 2, 2017
 * File: main.c
 * Copyright © 2017 All rights reserved
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include\ballistic_math.h"

int main(int argc, char *argv[]) {
	const double MAX_HEIGHT = 1000.0;			//<= Maximum Height Value
	const double MIN_HEIGHT = 0.0;				//<= Minimum Height Value
	const double MAX_ANGLE = 90.0;				//<= Maximum Angle
	const double MIN_ANGLE = -90.0;				//<= Minimum Angle
	const double MAX_VELOCITY = 299792458.0;	//<= Maximum Velocity
	const double MIN_VELOCITY = 0.0;			//<= Minimum Velocity
	const double PI = 3.14159;					//<= PI Value Precision 5
	const double G = 9.81;						//<= Gravitational Acceleration
	double y = 0.0;								//<= Initial Height
	double t = 0.0;								//<= Angle Degrees
	double v = 0.0;								//<= Velocity
	int flag = 0;								//<= Loop Boolean
	char response[32];							//<= Repeat Calculation Boolean
	
	// Display initial message
	printf("\n*** Simple Ballistics Calculator ***\n");	
	
	do {

		do {
			// Prompt user input
			printf("\nStep 1 of 3: Please enter in a value for the inital height of the projectile (meters):\n");
			int ic = fscanf(stdin, "%lf", &y);
			
			// Input type miss-match
			if(ic <= 0) {
				fprintf(stderr, "Error, input type mismatch. Numeric values only.");
				return -1;
				
			}
			
			// Check if input is within acceptable range
			if((y <= MIN_HEIGHT) || (y > MAX_HEIGHT)) {
				printf("** Error: Input out of range. Height must be greater than %.3lf, or less than or equal to %.3lf.\n", MIN_HEIGHT, MAX_HEIGHT);
				flag = 0;
				
			} else {
				flag = 1;
				
			}
				
		} while(flag == 0);
		
		
		do {
			// Prompt user input
			printf("Step 2 of 3: Please enter a value for the angle at which the projectile is launched (-90 to 90 degrees):\n");
			int ic = fscanf(stdin, "%lf", &t);
			
			// Input type miss-match
			if(ic <= 0) {
				fprintf(stderr, "Error, input type mismatch. Numeric values only.");
				return -1;
				
			}
			
			// Check if input is within acceptable range
			if((t < MIN_ANGLE) || (t > MAX_ANGLE)) {
				printf("** Error: Input out of range. Angle must be greater than or equal to %.3lf, or less than or equal to %.3lf.\n", MIN_ANGLE, MAX_ANGLE);
				flag = 0;
				
			} else {
				flag = 1;
				
			}
				
		} while(flag == 0);
		
		
		do {
			// Prompt user input
			printf("Step 3 of 3: Please enter a value for the initial speed at which the projectile is launched (meters per second):\n");
			int ic = fscanf(stdin, "%lf", &v);
			
			// Input type miss-match
			if(ic <= 0) {
				fprintf(stderr, "Error, input type mismatch. Numeric values only.");
				return -1;
				
			}
			
			// Check if input is within acceptable range
			if((v < MIN_VELOCITY) || (v >= MAX_VELOCITY)) {
				printf("** Error: Input out of range. Velocity must be greater than %.3lf, or less than %.3lf.\n", MIN_VELOCITY, MAX_VELOCITY);
				flag = 0;
				
			} else {
				flag = 1;
				
			}
				
		} while(flag == 0);

		
		// Calculate results, convert to radians
		double tof = time_to_flight(G, (t * (PI/180)), v, y);
		double dt = distance_traveled(G, (t * (PI/180)), v, y);
		
		// Display results
		printf("\n*** Calculations ***\n");
		printf("Initial Height: %.3lf meters.\n", y);
		printf("Initial Angle: %.3lf degrees.\n", t);
		printf("Initial Velocity: %.3lf m/s.\n", v);
		printf("Time To Flight: %.3lf seconds.\n", tof);
		printf("Distance Traveled: %.3lf meters.\n", dt);
		
		printf("Would you like to make another calculation? (Yes\\No)\n");
		fscanf(stdin, "%s", response);

	} while((response[0] == 89) || (response[0] == 121));
	
	return 0;
	
}
