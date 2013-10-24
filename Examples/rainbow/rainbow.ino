
#include <LightAnimation.h>

Animator anim; 
KeyFrame rainbow[3]; 



void setup()
{

Color red = Color(255,0,0); 
Color green = Color(0,255,0);
Color blue = Color(0,0,255);


rainbow[0] = KeyFrame(blue,0.0); 
rainbow[1] = KeyFrame(green,0.33); 
rainbow[2] = KeyFrame(red,0.66); 

int pins[3] = {5,3,6}; 

anim.setPins(pins); 
anim.setDuration(5000);
anim.setAnimation(rainbow, 3 );

 
anim.start();
 
Serial.begin(9600); 

}


void loop()
{
anim.update();  
}
