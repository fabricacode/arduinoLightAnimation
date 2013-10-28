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

#include "Color.h"


Color :: Color(){
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

Color::Color(unsigned char _brightness)
{
    r = _brightness;
    g = _brightness;
    b = _brightness;
}

Color::Color(long int _hexCol)
{
    //as 0xrrggbb
    r = (_hexCol >> 16) & 0xFF;
    g = (_hexCol >> 8) & 0xFF;
    b = _hexCol & 0xFF;


}



void Color :: setHSB(int _hue, int _saturation, int _brightness)
{
    // ofClamp all input variables to expected range
    int hue = constrain(_hue, 0, 360);
    int sat = constrain(_saturation, 0, 100);
    int bright = constrain(_brightness, 0, 100);

    // define maximum value for RGB array elements
    float max_rgb_val = H2R_MAX_RGB_val;

    // convert saturation and brightness value to decimals and init r, g, b variables
    float sat_f = float(sat) / 100.0;
    float bright_f = float(bright) / 100.0;

    // If brightness is 0 then color is black (achromatic)
    // therefore, R, G and B values will all equal to 0
    if (bright <= 0) {
        r = 0;
        g = 0;
        b = 0;
    }

    // If saturation is 0 then color is gray (achromatic)
    // therefore, R, G and B values will all equal the current brightness
    if (sat <= 0) {
        r = bright_f * max_rgb_val;
        g = bright_f * max_rgb_val;
        b = bright_f * max_rgb_val;
    }

    // if saturation and brightness are greater than 0 then calculate
    // R, G and B values based on the current hue and brightness
    else {

        if (hue >= 0 && hue < 120) {
            float hue_primary = 1.0 - (float(hue) / 120.0);
            float hue_secondary = float(hue) / 120.0;
            float sat_primary = (1.0 - hue_primary) * (1.0 - sat_f);
            float sat_secondary = (1.0 - hue_secondary) * (1.0 - sat_f);
            float sat_tertiary = 1.0 - sat_f;
            r = (unsigned char)(bright_f * max_rgb_val) * (hue_primary + sat_primary);
            g = (unsigned char)(bright_f * max_rgb_val) * (hue_secondary + sat_secondary);
            b = (unsigned char)(bright_f * max_rgb_val) * sat_tertiary;
        }

        else if (hue >= 120 && hue < 240) {
            float hue_primary = 1.0 - ((float(hue)-120.0) / 120.0);
            float hue_secondary = (float(hue)-120.0) / 120.0;
            float sat_primary = (1.0 - hue_primary) * (1.0 - sat_f);
            float sat_secondary = (1.0 - hue_secondary) * (1.0 - sat_f);
            float sat_tertiary = 1.0 - sat_f;
            r = (unsigned char)(bright_f * max_rgb_val) * sat_tertiary;
            g = (unsigned char)(bright_f * max_rgb_val) * (hue_primary + sat_primary);
            b = (unsigned char)(bright_f * max_rgb_val) * (hue_secondary + sat_secondary);
        }

        else if (hue >= 240 && hue <= 360) {
            float hue_primary = 1.0 - ((float(hue)-240.0) / 120.0);
            float hue_secondary = (float(hue)-240.0) / 120.0;
            float sat_primary = (1.0 - hue_primary) * (1.0 - sat_f);
            float sat_secondary = (1.0 - hue_secondary) * (1.0 - sat_f);
            float sat_tertiary = 1.0 - sat_f;
            r = (unsigned char)(bright_f * max_rgb_val) * (hue_secondary + sat_secondary);
            g = (unsigned char)(bright_f * max_rgb_val) * sat_tertiary;
            b = (unsigned char)(bright_f * max_rgb_val) * (hue_primary + sat_primary);
        }

    }

}
