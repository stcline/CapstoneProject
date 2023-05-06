# Capstone - Sentury Turret
Robotics Engineering Capstone Project

Brady Sanger and Camden Timmons

May 10, 2023

(insert final product image here)

## Overview

Our device is an automated turret that can sense someone and turn to shoot them. When turning the system on you must first enter a distance on the number pad. This distance is how far the sensor is from the point of rotation, or in other terms the center of the pyramid. This distance is later used for some simple trigonometry. After doing this the turret will start working. If you walk in front of the distance sensor it will take the distance you are away from the sensor as well as the inputed distance you entered earlier to find the centeral angle. In order to find the centeral angle we use inverse tangent or arc tangent.

The equation looks something like:

arctan(Sensed Distance/Inputted Distance) = Centeral Angle in Radians

Diagram of how it works:
![Trig (1)](https://user-images.githubusercontent.com/90796319/236632996-c2adf86e-2c53-4243-b716-d77638e1a450.png)

That is all the basic angle finding, but what about the rest?

Using the angle we get above we turn a servo to that angle, this should turn the actual turret part twords the target. Then we start spinning the flywheel on the turret (two really fast wheels) in opposite directions that way when we feed through a nerf dart it can shoot the dart. Using another servo we push the pre-loaded dart forward into the flywheel propelling it forward.

Flywheel mechanism:

![IMG_7484](https://user-images.githubusercontent.com/90796319/236633412-4746c674-2416-4c64-82b6-c64ea61152d9.jpg)

## System Details

Many parts of this project were manufactured using a 3D printer and with many unique parts you may want to know what they are an what they do!

### Flywheel

The flywheel is a simple device that simply has two motors that spin up wheels. When the nerf dart is pushed into these wheels it is propelled forward. This system is very similar to the real nerf flywheels used in some nerf guns. This image is above, but why not see it again!

![IMG_7484](https://user-images.githubusercontent.com/90796319/236633643-75754146-f234-44ed-bb64-e61d4b635fa1.jpg)

### Magazine

The magazine is what holds the nerf darts as well as pushes the darts into the flywheel. This piece is directly mounted to the flywheel. Using one servo and a custom designed servo horn and a very long 35mm 3M screw as well as a hex nut we are able to push the dart forward into the fly wheel.

(Insert image when printed)





