
#include <LightAnimation.h>

KeyFrame rainbow[3] = {
  KeyFrame(Color::red, 0.0), 
  KeyFrame(Color::green, 0.33), 
  KeyFrame(Color::blue, 0.66)
}; 

Animator anim; 
int pins[3] = {3,5,6}; 
int duration = 3000; 

void setup()
{
  anim.setPins(pins); 
  anim.setAnimation(rainbow, 3 , duration);
  
  Serial.begin(9600); 
}


void loop()
{
  
  anim.update();  
}
