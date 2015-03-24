#include <LightAnimation.h>

KeyFrame a00[2] = {
  KeyFrame(Color(0,255,255),0.0),
  KeyFrame(Color(0,0,255),0.5),
};

KeyFrame a01[2] = {
  KeyFrame(Color(255,0,0),0.0),
  KeyFrame(Color(255,0,255),0.5),
};


KeyFrame a02[2] = {
  KeyFrame(Color(0,255,0),0.0),
  KeyFrame(Color(255,255,0),0.5),
};

Animator anim; 
int rgbPins[3] = {5,3,6}; 
int duration = 3000; 

int switchPins[3] = {10,11,12}; 
int animIndex = -1; 
int lastAnimIndex = -1; 


void setup()
{
  anim.setPins(rgbPins); 
  anim.setAnimation(a00, 2, duration);

  
  for (int i=0; i< 3; i++)
  {
    pinMode(switchPins[i], INPUT); 
  }
  
  Serial.begin(9600); 
  
}

unsigned long recTime = millis();   

void loop()
{
  for (int i=0; i< 3; i++)
  {
    boolean swVal = digitalRead(switchPins[i]); 
    if (!swVal and millis() - recTime > 1000)
      {
        animIndex = i; 
        recTime = millis(); 

      }
  }
  
  if (animIndex != lastAnimIndex)
  {
    if (animIndex == 0) 
      anim.setAnimation(a00,2,duration); 
    else if (animIndex == 1) 
      anim.setAnimation(a01,2,duration/3); 
    else if (animIndex == 2) 
      anim.setAnimation(a02,2,duration/5); 
     
     lastAnimIndex = animIndex; 
  }
  
  
   anim.update(); 
}


