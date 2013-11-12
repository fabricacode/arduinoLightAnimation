#include <LightAnimation.h>

KeyFrame CyanBlue[2] = {
  KeyFrame(Color(0,255,255),0.0),
  KeyFrame(Color(0,0,255),0.5),
};

KeyFrame RedMagenta[2] = {
  KeyFrame(Color(255,0,0),0.0),
  KeyFrame(Color(255,0,255),0.5),
};

Animator anim; 
int pins[3] = {3,5,6}; 
int duration = 1000; 
int nIterations = 3; 

unsigned long timeInterval = 3000; 
unsigned long lastUpdate = millis(); 

void setup()
{
  anim.setPins(pins); 
  anim.setAnimation(CyanBlue, 2, duration);
  anim.setIterations(nIterations); 
  
}

void loop()
{
  if (millis() - lastUpdate > timeInterval)
  {
    lastUpdate = millis(); 
    
  }
  anim.update(); 
}


