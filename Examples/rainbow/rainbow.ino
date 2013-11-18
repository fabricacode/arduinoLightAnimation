
#include <LightAnimation.h>

Color red = Color(255,0,0); 
Color green = Color(0,255,0);
Color blue = Color(0,0,255); 

KeyFrame rainbow[3] = {
  KeyFrame(red, 0.0), 
  KeyFrame(green, 0.33), 
  KeyFrame(blue, 0.66)
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
