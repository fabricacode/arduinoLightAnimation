
#include <LightAnimation.h>

Animator anim; 
KeyFrame stairs[3]; 



void setup()
{


Color white0 = Color(10);
Color white1 = Color(100);
Color white2 = Color(255);
Color green = Color(0,255,0); 



stairs[0] = KeyFrame(white0,0.0); 
stairs[1] = KeyFrame(white1,0.33); 
stairs[2] = KeyFrame(green,0.99); 

int pins[3] = {3,5,6}; 

anim.setPins(pins); 
anim.setDuration(5000);
anim.setAnimation(stairs, 3 );
anim.setAlternate(true); 

 
anim.start();
 
Serial.begin(9600); 

}


void loop()
{
anim.update();  
}
