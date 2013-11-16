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

Color Color::fromHSB(int _h, int _s, int _b)
{
    Color col = Color();
    col.setHSB(_h, _s, _b);

    return col;
}

Color Color::fromHex(long int _hexCol)
{
    //as 0xrrggbb
    Color col = Color();
    col.r = (_hexCol >> 16) & 0xFF;
    col.g = (_hexCol >> 8) & 0xFF;
    col.b = (_hexCol >> 0 ) & 0xFF;
    return col;
}

Color Color::fromHex(int _hexCol)
{
    //as 0xrrggbb
    Color col = Color();
    col.r = (_hexCol >> 16) & 0xFF;
    col.g = (_hexCol >> 8) & 0xFF;
    col.b = (_hexCol >> 0 ) & 0xFF;
    return col;
}

Color Color::fromHex(unsigned int _hexCol)
{
    //as 0xrrggbb
    Color col = Color();
    col.r = (_hexCol >> 16) & 0xFF;
    col.g = (_hexCol >> 8) & 0xFF;
    col.b = (_hexCol >> 0 ) & 0xFF;
    return col;
}



void Color :: setHSB(int _hue, int _saturation, int _brightness)
{
    // ofClamp all input variables to expected range
    int hue = constrain(_hue, 0, 359);
    int sat = constrain(_saturation, 0, 99);
    int bright = constrain(_brightness, 0, 99);

    if (bright == 0)
    {
        r = 0;
        g = 0;
        b = 0;

        Serial.print("bright 0: ");

    }
    else if (sat == 0)
    {
        r = bright;
        g = bright;
        b = bright;

         Serial.print("sat 0: ");
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
