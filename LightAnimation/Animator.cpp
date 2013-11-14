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

#include "Animator.h"

Animator::Animator()
{
    //default things
    duration = 1000;

    nIterations = 1;
    iterations = 0;
    bInfiniteIterations = true;


    nAnimationTransitionSteps = 10;
    pwmPins[0] = 2;
    pwmPins[1] = 3;
    pwmPins[2] = 4;
    r = 0;
    g = 0;
    b = 0;
    rInc = 0;
    gInc = 0;
    bInc = 0;
    bAnimationTransition = false;

    bDirectionUp = true;
    bAlternate = false;
    animationIndex = 0;

    animation = NULL;
    animationSteps = NULL;



}

Animator::~Animator()
{
    delete [] animation;
    delete [] animationSteps;

}

void Animator::setPins(const int* _pwmPins)
{
    for (int i=0; i< 3; i++)
        pwmPins[i] = _pwmPins[i];
}

void Animator::setDuration(unsigned long _duration)
{
    duration = _duration;

}

void Animator::setAnimation(const KeyFrame* _animation, size_t size)
{

    if (animation != NULL)
        delete [] animation;
    if (animationSteps != NULL)
        delete [] animationSteps;

    nKeyFrames = size;
    animation = new KeyFrame[nKeyFrames];
    animationSteps = new int[nKeyFrames];
    for (int i=0; i<nKeyFrames; i++)
    {
        animation[i] = _animation[i];
        animationSteps[i] = floor((animation[i].perc*duration)/STEPTIME); //for each animation's keyframe perc tim the step when it's supposed to start
    }

    bAnimationTransition = true;
    //diff between newly set animation first color
    int rDiff = animation[0].col.r - r;
    int gDiff = animation[0].col.g - g;
    int bDiff = animation[0].col.b - b;


    rInc = (float)rDiff/nAnimationTransitionSteps;
    gInc = (float)gDiff/nAnimationTransitionSteps;
    bInc = (float)bDiff/nAnimationTransitionSteps;
    start();

}

void Animator::setAnimation(const KeyFrame* _animation, size_t size, unsigned long _duration)
{
    if (animation != NULL)
        delete [] animation;
    if (animationSteps != NULL)
        delete [] animationSteps;

    duration = _duration;
    //allocate memory / check if right
    nKeyFrames = size;
    animation = new KeyFrame[nKeyFrames];
    animationSteps = new int[nKeyFrames];
    for (int i=0; i<nKeyFrames; i++)
    {
        animation[i] = _animation[i];
        animationSteps[i] = floor((animation[i].perc*duration)/STEPTIME); //for each animation's keyframe perc tim the step when it's supposed to start
    }

    bAnimationTransition = true;
    //diff between newly set animation first color
    int rDiff = animation[0].col.r - r;
    int gDiff = animation[0].col.g - g;
    int bDiff = animation[0].col.b - b;


    rInc = (float)rDiff/nAnimationTransitionSteps;
    gInc = (float)gDiff/nAnimationTransitionSteps;
    bInc = (float)bDiff/nAnimationTransitionSteps;
    start();

}

void Animator::setIterations(int _nIterations)
{
    bInfiniteIterations = false;
    iterations = 0;
    if (_nIterations < 1)
        nIterations = 1;
    else if (_nIterations > MAXNITERATIONS)
        bInfiniteIterations = true;
    else
        nIterations = _nIterations;
}
void Animator::setIterationsInfinite(bool _bInfiniteIterations)
{
    bInfiniteIterations = _bInfiniteIterations;
}

void Animator::setAlternate(bool _bAlternate)
{
    bAlternate = _bAlternate;
}

void Animator::setTransitionDuration(unsigned long _transitionDuration)
{
    nAnimationTransitionSteps = (float)_transitionDuration/STEPTIME;
}





void Animator::start()
{

    //time related stuff
    nSteps = (float)duration/STEPTIME;
    lastCounterUpdate = millis();
    step = 0;
    iterations = 0;
}

void Animator::update()
{
    if (bInfiniteIterations || iterations < nIterations)
    {
        //update color every STEPTIME ms
        if (millis() - lastCounterUpdate > STEPTIME)
        {

            lastCounterUpdate = millis();
            //update colors
            r += rInc;
            g += gInc;
            b += bInc;

            currentColor = Color(r,g,b);
            writeRGBPins(currentColor);



            if (!bAnimationTransition)
            {
                if (bAlternate)
                {
                    //check if I'm in a new keyframe
                    if (step == animationSteps[animationIndex])
                    {
                        int stepsToNextKeyFrame;
                        int nextAnimationIndex;
                        if (bDirectionUp)
                        {
                            if (animationIndex==nKeyFrames-1)
                            {
                                nextAnimationIndex = animationIndex; //no changes
                                stepsToNextKeyFrame = (nSteps-step-1)*2;
                                //bDirectionUp = false;
                            }
                            else
                            {
                                nextAnimationIndex = animationIndex+1;
                                stepsToNextKeyFrame = animationSteps[nextAnimationIndex] - step;
                            }

                        }
                        else //direction down
                        {
                            if (animationIndex== 0)
                            {
                                nextAnimationIndex = animationIndex;
                                stepsToNextKeyFrame = step*2;
                            }
                            else
                            {
                                nextAnimationIndex = animationIndex -1;
                                stepsToNextKeyFrame = step - animationSteps[nextAnimationIndex];
                            }

                        }
                        //set color
                        r = animation[animationIndex].col.r;
                        g = animation[animationIndex].col.g;
                        b = animation[animationIndex].col.b;

                        //calculae new rInc
                        int rDiff = animation[nextAnimationIndex].col.r - animation[animationIndex].col.r;
                        int gDiff = animation[nextAnimationIndex].col.g - animation[animationIndex].col.g;
                        int bDiff = animation[nextAnimationIndex].col.b - animation[animationIndex].col.b;
                        rInc = (float)rDiff/stepsToNextKeyFrame;
                        gInc = (float)gDiff/stepsToNextKeyFrame;
                        bInc = (float)bDiff/stepsToNextKeyFrame;

                        animationIndex = nextAnimationIndex;


                    }



                    //update step
                    if (bDirectionUp)
                    {
                        step++;
                        if (step == nSteps-1)
                        {
                            if (bInfiniteIterations)
                                bDirectionUp = false;
                            else
                            {
                                bDirectionUp = false;
                                iterations++;

                            }
                        }
                    }
                    else //direction down
                    {

                        step--;
                        if (step==0)
                            {
                            if (bInfiniteIterations)
                                bDirectionUp = true;
                            else
                            {
                                bDirectionUp = true;
                                iterations++;

                            }
                        }
                    }



                }

                else //not alternate
                {
                    if (step == animationSteps[animationIndex])
                    {
                        int stepsToNextKeyFrame;

                        int nextAnimationIndex;

                        //for not to make a transition to the next keyframe, which is on a not wanted iteration


                        if (iterations == nIterations -1 && animationIndex == nKeyFrames - 1)
                            nextAnimationIndex = animationIndex;
                        else
                             nextAnimationIndex = (animationIndex+1)%nKeyFrames;

                        if (animationIndex==nKeyFrames-1)
                        {
                            stepsToNextKeyFrame = (nSteps - step) + animationSteps[nextAnimationIndex];
                        }
                        else
                        {
                            stepsToNextKeyFrame = animationSteps[nextAnimationIndex] - step;
                        }

                        if (stepsToNextKeyFrame < 1)
                            stepsToNextKeyFrame = 1;

                        //set color
                        r = animation[animationIndex].col.r;
                        g = animation[animationIndex].col.g;
                        b = animation[animationIndex].col.b;
                        //calculate new rInc
                        int rDiff = animation[nextAnimationIndex].col.r - animation[animationIndex].col.r;
                        int gDiff = animation[nextAnimationIndex].col.g - animation[animationIndex].col.g;
                        int bDiff = animation[nextAnimationIndex].col.b - animation[animationIndex].col.b;
                        rInc = (float)rDiff/stepsToNextKeyFrame;
                        gInc = (float)gDiff/stepsToNextKeyFrame;
                        bInc = (float)bDiff/stepsToNextKeyFrame;

                        animationIndex = nextAnimationIndex;


                    }
                    //update step
                    step++;

                    // check if I did a loop already
                    if (step == nSteps)
                    {
                        if (bInfiniteIterations)
                            step = 0;
                        else
                        {
                            iterations++;
                            step = 0;
                        }


                    }





                }


            }

            else //it's a transition between two animations
            {
                step ++;
                if (step == nAnimationTransitionSteps-1)
                {
                    step = 0;
                    bAnimationTransition = false;
                    rInc = 0;
                    gInc = 0;
                    bInc = 0;
                    animationIndex = 0;
                    r = animation[0].col.r;
                    g = animation[0].col.g;
                    b = animation[0].col.b;

                }
            }

        }

    }



}

Color Animator::getColor()
{

    return currentColor;

}


KeyFrame* Animator::getAnimation()
{
    return animation;
}

void Animator::writeRGBPins(const Color &col)
{
    analogWrite(pwmPins[0],col.r);
    analogWrite(pwmPins[1],col.g);
    analogWrite(pwmPins[2],col.b);

}
