/*
RGB led animation for Arduino


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

#include "Color.h"



Color :: Color()
{
    r = 0;
    g = 0;
    b = 0;
}


Color :: Color(unsigned char _r, unsigned char _g, unsigned char _b)
{
    r = _r;
    g = _g;
    b = _b;
}

Color::Color(unsigned char _grey)
{
    r = _grey;
    g = _grey;
    b = _grey;
}

Color Color::fromHex(unsigned long _hexCol)
{
    Color col;
    col.setHex(_hexCol);
    return col;
}

Color Color::fromHSB(int _h, int _s, int _b)
{
    Color col;
    col.setHSB(_h,_s,_b);
    return col;
}


void Color :: setHSB(int _hue, int _saturation, int _brightness)
{
    int hue = constrain(_hue, 0, 359);
    int sat = constrain(_saturation, 0, 99);
    int bright = constrain(_brightness, 0, 99);

    if (bright == 0)
    {
        r = 0;
        g = 0;
        b = 0;


    }
    else if (sat == 0)
    {
        r = bright;
        g = bright;
        b = bright;

    }

    else
    {
        float hueSix = hue*6. / 360.0;
        float satNorm = sat*1. / 100.0;
        int hueSixCategory = (int) floor ( hueSix);
        float hueSixReminder = hueSix - hueSixCategory;

        unsigned char pv = (unsigned char) ((1.f - satNorm)* bright);
        unsigned char qv = (unsigned char) ((1.f - satNorm* hueSixReminder)*bright);
        unsigned char tv = (unsigned char) ((1.f - satNorm* (1 - hueSixReminder))*bright);
        unsigned char brightNorm = (int)((bright/99.0 )*255.0);



        switch (hueSixCategory)
        {
        case 0: // r
            r = brightNorm;
            g = tv;
            b = pv;
            break;
        case 1: // g
            r = qv;
            g = brightNorm;
            b = pv;
            break;
        case 2:
            r = pv;
            g = brightNorm;
            b = tv;
            break;
        case 3: // b
            r = pv;
            g = qv;
            b = brightNorm;
            break;
        case 4:
            r = tv;
            g = pv;
            b = brightNorm;
            break;
        case 5: // back to r
            r = brightNorm;
            g = pv;
            b = qv;
            break;
        }



    }
}

void Color::setHex(unsigned long _hexCol)
{

    r = (_hexCol >> 16) & 0xff;
    g = (_hexCol >> 8) & 0xff;
    b = (_hexCol) & 0xff;


}


const Color Color::white(255);
const Color Color::red(255, 0, 0);
const Color Color::green(0,255, 0);
const Color Color::blue(0,0,255);
const Color Color::yellow(255,255,0);
const Color Color::magenta(255,0,255);
const Color Color::cyan(0,255,255);
