#include <LightAnimation.h>

KeyFrame CyanBlue[2] = {
  KeyFrame(Color(0,0,155),0.5),
  KeyFrame(Color(0,155,155),0.0),
  
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
}

void loop()
{
  anim.update(); 
}


