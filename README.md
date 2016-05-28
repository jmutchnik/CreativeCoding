Jeffrey Mutchnik

04.11.16

EDPX 3701: Creative Coding

Dan Wilcox



Exercise 1:

Draw a face in openFrameworks using only the 2d drawing commands, color settings, and draw settings. Use variables and at least 10 different graphical elements.


I chose to create a robot face using different colors and shapes.



Exercise 2:

Create a project that contains: mouse interaction, key interaction, & animation.


- Mouse position is mapped to the radius of the circle

- Circle is animated using sin & cosine

- Key press leaves a trail, and produces random rectangles.


Exercise 3:

Make a simple project using 2 addons, 1 of which you should download from GitHub. Combine the addons so that both are used in conjunction in some way.



Addons Included: ofxGui, ofxLiquidFun


ofxLiquidFun:
- If you drag the mouse, particles are created
- Press "c" for circles to appear
-Press "b" for boxes to appear"

ofxGui:

-creates GUI panel
- sliders that control the size & color of the circles and boxes


Exercise 5: Create a simple project which utilizes computer vision to do one or more of the following:

-process an image or images
-detection motion
-track movement


This is a simple sketch that uses ofxOpenCV to produce various filters of the images from the webcam.



Project 1: Develop a project using generative art. 


This is a music visualizer that loads in audio tracks. 

Press "1" - Play Track 1
Press "2" - Play Track 2
Press "3" - Play Track 3

Press "c" - Change Color


ofxFFT:

The different shapes are being manipulated by the amplitude from each audio file to create a unique output. 



Project 2: Develop a project that uses interactivity. 


This is another music visualizer/beat machine using OSC with Ableton Live, and FFT. 

1. Load clips into Ableton Live
2. Run the App
3. Each shape is connected to the clip from Ableton and if pressed, it will play the clip and produce a visual output using FFT.



Audio is ran from Ableton Live into Soundflower to OpenFrameworks.


