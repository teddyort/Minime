#include "Arduino.h"
#include "Minime.h"
#include "Servo.h"

void Minime::attach(const int leftPin, const int rightPin, const int leftNeutral, const int rightNeutral, const int leftMax, const int rightMax){
	//Setup the pins
	_leftPin = leftPin;
	_rightPin = rightPin;
	_leftNeutral = leftNeutral;
	_rightNeutral = rightNeutral;
	_leftMax = leftMax;
	_rightMax = rightMax;
	
	pinMode (_rightPin, OUTPUT);	// want right servo pin to be an output
	pinMode (_leftPin, OUTPUT);		// want left servo pin to be an output
	_servoRight.attach(_rightPin);	// attach pin to the rigth servo 
	_servoLeft.attach(_leftPin);	// attach pin to the left servo
	_servoRight.writeMicroseconds(rightNeutral);
	_servoLeft.writeMicroseconds(leftNeutral);
	_pwrLeft = 0;
	_pwrRight = 0;
	stop();

}

void Minime::drive(int pwrLeft, int pwrRight){
	if(pwrLeft != _pwrLeft){
		_servoLeft.writeMicroseconds(map(pwrLeft,-100,100, _leftNeutral-_leftMax, _leftNeutral+_leftMax));
		_pwrLeft = pwrLeft;
	}
	if(pwrRight != _pwrRight){
		_servoRight.writeMicroseconds(map(pwrRight,-100,100,_rightNeutral+_rightMax, _rightNeutral-_rightMax));
		_pwrRight = pwrRight;
	}		
}

void Minime::stop()
{
  drive(0,0);
}

void Minime::straight(int pwr){
  drive(pwr,pwr);
}

void Minime::turn(int pwr){
  drive(-pwr, pwr);
}