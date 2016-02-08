/*
  Minime.h - Library for driving a "minime-like" device with two servos for driving and steering
 Created by Teddy Ort
 */

#include <Minime.h>

Minime myMinime;

void setup(){
  myMinime.attach(8,7);
}

void loop(){
  myMinime.drive(100,100);
  delay(5000);
  myMinime.stop();
  while(1);
}
