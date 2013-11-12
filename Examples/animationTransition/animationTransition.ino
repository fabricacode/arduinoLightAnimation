
#include <LightAnimation.h>

Animator anim; 

KeyFrame a00[2]; 
KeyFrame *a01; 
KeyFrame a02[1]; 


void setup()
{
  
  //
  Color blue = Color(0,0,255); 
  Color green = Color(0,255,0); 
  Color red = Color(255,0,0); 

  a00[0] = KeyFrame(blue,0.0); 
  a00[1] = KeyFrame(green,0.5); 
  
  a01[0] = KeyFrame(red,0.5); 


int pins[3] = {3,5, 6}; 
  
  anim.setPins(pins); 
  anim.setDuration(5000);
  anim.setAnimation(a01, 2 );

   
   anim.start();
   
   Serial.begin(9600); 

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
      anim.setAnimation(a02, 1 );
      bA = true; 
    }
      
  }


}
