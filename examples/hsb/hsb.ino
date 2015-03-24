
#include <LightAnimation.h>

Color c0 = Color::fromHSB(30, 90, 40);
Color c1 = Color::fromHSB(0, 90, 80);

KeyFrame a[2] = {
    KeyFrame(c0, 0.0), 
    KeyFrame(c1, 0.5), 
}; 
Animator anim; 
int pins[3] = {3,5,6}; 
int duration = 3000; 

void setup()
{
  anim.setPins(pins); 
  anim.setAnimation(a, 2 , duration);
}


void loop()
{
  anim.update();  
}
