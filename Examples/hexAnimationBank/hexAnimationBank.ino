#include <LightAnimation.h>
#include "animations.h"

Animator anim; 
int pins[3] = {3,6,5};
int duration = 5000; 
void setup()
{
  anim.setPins(pins); 
  anim.setAnimation(hell, 2, duration);
  //anim.setAnimation(rainbow, 8, duration);
}

void loop()
{
  anim.update();  
}
