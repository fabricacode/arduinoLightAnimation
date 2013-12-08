arduinoLightAnimation
=====================

CSS3 style color animation library for controlling RGB leds on Arduino https://vimeo.com/79962595
For information on how to install a library for the Arduino IDE check here: arduino.cc/en/Guide/Libraries

CSS3 animation comparison
-------

- animation-duration 
	- CSS3: Specifies how many seconds or milliseconds an animation takes to complete one cycle. Default 0. 
	- aLA: Specifies how many milliseconds an animation takes to complete one cycle. Default 1000ms. 
		- can be set either when the animation is set: 

			```
			myAnimator.setAnimation(animationKeyFrameArray, nKeyFrames, duration_ms); 
			```
		- or BEFORE to set the animation: 

			```
			myAnimator.setDuration(duration_ms);
			myAnimator.setAnimation(animationKeyFrameArray, nKeyFrames); 
			```

- animation-timing-function
	- CSS3: Describes how the animation will progress over one cycle of its duration. Default "ease"
	- aLA: Now only linear

- animation-delay
	- CSS3: Specifies when the animation will start. Default 0
	- aLA: Start to update after a delay will suffice. 

- animation-iteration-count
	- CSS3: Specifies the number of times an animation is played. Default 1
	- aLA: Specifies the number of times an animation is played. Default infinite; 
		- in setup, for setting number of iterations

			```
			myAnimator.setIterations(nIterations); 
			```
		- for setting infinite iterations 

			```
			myAnimator.setIterationsInfinite(true); 
			```
		- or restore past number of iterations

			```
			myAnimator.setIterationsInfinite(false); 
			```
- animation-direction
	- CSS3: Specifies whether or not the animation should play in reverse on alternate cycles. Default "normal" 
		http://www.w3schools.com/cssref/css3_pr_animation-direction.asp
	- aLA: Specifies if the animation is played always from begin to end "normal" or alternately from begin to end, then from end to begin "alternate". Default is "normal". 
		- in setup, for setting the "alternate" mode. 

			```
			myAnimator.setAlternate(true); 
			```
		- "normal" mode

			```
			myAnimator.setAlternate(false); 
			```
		
		
- animation-play-state
	- CSS3: Specifies whether the animation is running or paused. Default "running"
	- aLA: Not updating works as a pause. 

Other features and info
-------


- Order for setting animation keyframe is not relevant
- Transition when animation are changed on runtime 
	- Set time of trasition between different animations

	```
	myAnimator.setTransitionDuration(unsigned long _transitionDuration)
	```
- Can put colors in rgb, hex, hsb
- Putting "delay" function will interfere with the timing of the animation, since the update function is supposed to be executed each cycle. 

=====================

Check the Examples for an idea of how to use the library 



