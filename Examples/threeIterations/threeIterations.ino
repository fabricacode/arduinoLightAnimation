#include <LightAnimation.h>

KeyFrame CyanBlue[2] = {
  KeyFrame(Color(0,0,255),0.0),
  KeyFrame(Color(0,255,255),0.999),
};



Animator anim; 
int pins[3] = {3,5,6}; 
int duration = 3000; 
int nIterations = 3; 
  

void setup()  
{
  anim.setPins(pins); 
  anim.setAnimation(CyanBlue, 2, duration);
  anim.setIterations(nIterations); 
  Serial.begin(9600); 
}

void loop()
{
  anim.update(); 
}


