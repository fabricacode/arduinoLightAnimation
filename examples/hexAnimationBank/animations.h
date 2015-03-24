#ifndef ANIMATIONS
#define ANIMATIONS

#include <LightAnimation.h>


//hell
  KeyFrame hell[2] = {
  KeyFrame(Color::fromHex(0xff0000),0.0),
  KeyFrame(Color::fromHex(0xff6600),0.5),
};

//strobo
  KeyFrame strobo[5] = {
  KeyFrame(Color::fromHex(0xffffff),0.0),
  KeyFrame(Color::fromHex(0xffffff),0.1),
  KeyFrame(Color::fromHex(0x0000ff),0.25),
  KeyFrame(Color::fromHex(0xffffff),0.5),
  KeyFrame(Color::fromHex(0xffffff),0.6),
};

//rainbow
KeyFrame rainbow[8] = {
  KeyFrame(Color::fromHex(0xffff00),0.0),
  KeyFrame(Color::fromHex(0xff0000),0.125),
  KeyFrame(Color::fromHex(0x9900cc),0.25),
  KeyFrame(Color::fromHex(0x0000ff),0.375),
  KeyFrame(Color::fromHex(0x00ff00),0.5),
  KeyFrame(Color::fromHex(0x0000ff),0.625),
  KeyFrame(Color::fromHex(0x9900cc),0.750),
  KeyFrame(Color::fromHex(0xff0000),0.875),
 
};


#endif
