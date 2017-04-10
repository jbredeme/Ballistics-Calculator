/**
 * Author: Jarid Bredemeier
 * Date: Thursday, February 2, 2017
 * File: ballistic_math
 * Copyright © 2017 All rights reserved
 */
 
#ifndef _ballistic_math_h
	#define _ballistic_math_h

	/**
	 * Calcuates the time it takes for a projectile to complete its trajectory
	 *
	 * @pram g - gravitational acceleration
	 * @pram t - angle projectile is launched
	 * @pram v - initial speed of the projectile
	 * @pram y - intiial height of the projectile
	 */
	static inline double time_to_flight(double g, double t, double v, double y) {
		return ((v * sin(t)) + sqrt(pow((v * sin(t)), 2) + (2 * g * y)))/(g);
		
	}

	
	/**
	 * Calculates the total distance traveled by a projectile
	 *
	 * @pram g - gravitational acceleration
	 * @pram t - angle projectile is launched
	 * @pram v - initial speed of the projectile
	 * @pram y - intiial height of the projectile
	 */
	static inline double distance_traveled(double g, double t, double v, double y) {
		return ((v * cos(t))/(g)) * ((v * sin(t)) + (sqrt(pow((v * sin(t)), 2) + (2 * g * y))));
		
	}

#endif