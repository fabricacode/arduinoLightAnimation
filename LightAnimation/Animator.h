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

#ifndef ANIMATOR_H
#define ANIMATOR_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "KeyFrame.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define STEPTIME 50 //update every XX ms


class Animator
{
    public:
        Animator(); //set default pwmPins, duration
        void setPins(const int* _pwmPins); //should be pwm pins. 3
        void setAnimation(const KeyFrame* _animation, size_t size);
        void setDuration(unsigned long _duration);
        void start();
        void update();// pass millis() here


        Color getColor();
        KeyFrame* getAnimation();

    private:

        KeyFrame* animation;
        int* animationSteps; //same n elements of animation. each element is the step when that keframe occurs
        int nKeyFrames;
        
    
        unsigned long duration;
        unsigned long lastCounterUpdate;
        int step;
        int nSteps;
        bool bDirectionUp;
        int animationIndex;
    
        bool bAlternate; 

        float rInc;
        float gInc;
        float bInc;

        float r;
        float g;
        float b;
    

        Color currentColor;


        int pwmPins[3];


        void writeRGBPins(const Color &col);


        bool bAnimationTransition;
    int nAnimationTransitionSteps;





};

#endif // ANIMATOR_H
