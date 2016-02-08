/*
  Minime.h - Library for driving "minime-like" devices that use two servos for differential drive
  Created by Teddy Ort
*/
#ifndef Minime_h
#define Minime_h

#include "Arduino.h"
#include "Servo.h"

class Minime
{
  public:
    void attach(const int leftPin, const int rightPin, const int leftNeutral, const int rightNeutral, const int leftMax, const int rightMax);
    void drive(int pwrLeft, int pwrRight);
	void stop();
	void straight(int pwr);
	void turn(int pwr);
  private:
    int _leftPin;
	int _rightPin;
	int _leftNeutral;
	int _rightNeutral;
	int _leftMax;
	int _rightMax;
	int _pwrLeft;
	int _pwrRight;
	
	Servo _servoRight;		// initialize  servo right
	Servo _servoLeft;		// initialize  servo left
};

#endif