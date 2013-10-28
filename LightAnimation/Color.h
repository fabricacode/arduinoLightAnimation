/*
RGB led animation for Arduino

uses code from https://github.com/julioterra/HSB_Color for RGB to HSB color conversion
and https://github.com/joushx/Arduino-RGB-Tools for fading functions

Copyright (c) 2012 Amico Leonardo - leonardo.amico@gmail.com


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/



#ifndef Color_h
#define Color_h



#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define H2R_MAX_RGB_val 255.0


class Color
{

  public:
	Color();
    Color(unsigned char _r, unsigned char _g, unsigned char _b);
    Color(unsigned char _brightness);
    Color(long int _hexCol);
    Color(int _hexCol);
    Color(unsigned int _hexCol);
    //Color(int _hue, int _saturation, int _brightness, bool bHSV=true);
    //https://github.com/julioterra/HSB_Color for color conversion
    void setHSB(int _hue, int _saturation, int _brightness); //hue: 0 - 359; saturation: 0 - 99; brightness: 0 - 99

//    void setHue(int _hue);
//    void setBrightness(int _brightness);
//    int getHue();
//    int getBrightness();

    unsigned char r;
    unsigned char g;
    unsigned char b;


};



#endif


