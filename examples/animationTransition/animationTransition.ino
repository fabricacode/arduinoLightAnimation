
#include <LightAnimation.h>

KeyFrame a00[2] = {
  KeyFrame(Color::red,0.0), 
  KeyFrame(Color::green,0.5)
  
}; 

KeyFrame a01[1] = {
  KeyFrame(Color::blue, 0.0)
}; 
  

Animator anim; 
int pins[3] = {3,5,6};

void setup()
{
  anim.setPins(pins); 
  anim.setDuration(5000);
  anim.setAnimation(a01, 2 );
}

unsigned long time = millis(); 
boolean bA = false; 

void loop()
{
  anim.update(); 
  
  if (millis() - time > 8000)
  {
    time = millis(); 
    if (bA)
    {
      anim.setAnimation(a00, 2 );
      bA = false; 
    }
    else
    {
      anim.setAnimation(a01, 1 );
      bA = true; 
    }   
  }
}
