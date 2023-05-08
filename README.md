# Capstone - Sentury Turret
Robotics Engineering Capstone Project

Brady Sanger and Camden Timmons

May 10, 2023

(insert final product image here)

## Design Summmary

![Untitled drawing](https://user-images.githubusercontent.com/90726645/236870412-5f8c3028-96fe-4c1a-ae30-8722c5da99a7.png)

![Untitled drawing (2)](https://user-images.githubusercontent.com/90726645/236871440-a2fec402-5959-4bba-9a42-2d1cc830dc2c.png)

Our device is an automated turret that can sense someone and turn to shoot them. When turning the system on you must first enter a distance on the number pad. This distance is how far the sensor is from the point of rotation, or in other terms the center of the pyramid. This distance is later used for some simple trigonometry. After doing this the turret will start working. If you walk in front of the distance sensor it will take the distance you are away from the sensor as well as the inputed distance you entered earlier to find the centeral angle. In order to find the centeral angle we use inverse tangent or arc tangent.

The equation looks something like:

**arctan(Sensed Distance/Inputted Distance) = Centeral Angle in Radians**

Diagram of how it works can be seen in **Figure 1**. 

That is all the basic angle finding, but what about the rest? Using the angle we get above we turn a servo to that angle, this should turn the actual turret part twords the target. Then we start spinning the flywheel on the turret (two really fast wheels) in opposite directions that way when we feed through a nerf dart it can shoot the dart. Using another servo we push the pre-loaded dart forward into the flywheel propelling it forward.

Refer to **figure 2** to see a flowchart of how our project works. 


## System Details

Many parts of this project were manufactured using a 3D printer and with many unique parts you may want to know what they are an what they do!

### Flywheel

The flywheel is a simple device that simply has two motors that spin up wheels. When the nerf dart is pushed into these wheels it is propelled forward. This system is very similar to the real nerf flywheels used in some nerf guns.  **Figure 3** shows a visual of the flywheel design. 

### Magazine

The magazine is what holds the nerf darts as well as pushes the darts into the flywheel. This piece is directly mounted to the flywheel. Using one servo and a custom designed servo horn and a very long 35mm 3M screw as well as a hex nut we are able to push the dart forward into the fly wheel. There is a guide rail on the design that is shorter than all the other openings. Refer to **Figure 4**.


### Pyramid and Base

The pyramid and base is used to mount the flywheel and magazine as well as hide some of the wires and the arduino mega used for this project. Here is where we put the motor controller, battery pack, arduino mega, and where we mount the turning servo. Here we also have mounted the number pad and the off and on switch. Here we also have our LED's that tell you what's happening. **Figure 5** shows the pyramid and base. 


### Circuit Schematic

With all these different servos, motors, controllers and etc. we need a diagram to see the wiring! Here you can see the pins everything is connected to and where it goes.

(Insert circuit diagram when edited)

### Software Diagram

**Figure 7** shows a diagram to show what the arduino is thinking throughout the entire process after you turn the turret on.

## Design Evaluation

For this capstone there was many requirements you had to hit to get a good grade. Here are the various categories and how we think we did.

### Output Display

For our output we used two LED's that show if you have entered the numbers on the number pad, if you pressed A on the number pad to start normal operation, and if a target is sensed. We think we hit this requirement fairly well however we didn't use any very complex parts and thus we think we did hit this category however it can be approved on.

### Manual User Input

For this we used a keypad which overall is fairly difficult to use. Using this with it also effecting the entire system as well as being shows on the LED's we think we hit this catagory well. We think this could be approved on however if we created a manual mode as well as a sentery mode.

### Automatic Sensor

For our automatic sensor we used a super sonic distance sensor which uses sound to find distance. We think we hit this category well and because of how important this single sensor is to the entire system we think we hit this requitement fairly well.

### Actuators, Mechanisms, and Hardware

Here we used many different actuators. Our project used two micro servos as well as two DC motors. There are all vital parts of our project. We also had a cleverly designed mechanism for pushing the nerf darts as well. We think we hit this right on the dot and that we did very good here.

### Logic, Processing, and Control

We have a lot of code for this project. We are also using many libraries effectivly to simplify our code too. In our code we also have some hard calculations such as finding the centeral angle using arctangent which seemed to be very difficult for the arduino to understand. We think we did fairly well here not only making simple concise code, but also using various hard calclations.

### Other adjustments

There was also many other adjustments that could positively or negatively effect your grade. Here we will mention only things I think we did good/bad on, but nothing we don't think will effect us.

Construction, Quality, Aesthetics, and Visual Appeal

We think we will get extra points here, however we think we could stay nuetral here. Our project overall looks good with almost everything hiding inside besides for things that must absolutely stick out.

Level of Effort

We think we will get extra points here, because we put in a lot of effort to get this project running including many hours of out of class work and designing for many parts of this project.

Cost

We are almost certain we will get this because our project as a total cost between only 30 and 40 dollars which seems to be the lowest in the class.

## Lessons Learned

We learned many lessons on this project, but most of all patience. So many parts of this projuct simply required waiting or very slow progress through a proplem.

One difficult problem we encountered was the magazine design as well as pushing the darts. We went through many different designs and iterations of our magazine to try and let it hold bullets while also pushing them, and for whatever pushing them to not be in the way of the bullet. Originally we had guide rails on the magazine and a servo would slide a special pusher design through the guide. This solution however didn't work because there was too much friction of the plastics on eachother and it couldn't glide through. Our solution was to use a screw and a hex nut mounted to our special servo horn that could slide through the guide rail while also staying straight.

We also learned lessons in work time usage. Pushing a large project twords the end even when it isn't your fault can still majorly effect your time usage and your priorites. Our project got largly delayed by sickness as well as shipping and broken parts leading to us having to rush tword the end. This is a bad method and I'd recommend more planning before entering a large project like this.

## Parts List

- 2 Motors (CHECK WITH CLINE)
- 2 Tower Pro Micro Servo 99, SG90 (Can be found on Amazon) $15.95 Model Num: SG90A2
- 1 Songhe 4 x 4 Matrix Array Membrane Switch Keypad Keyboard (Can be found on Amazon) $1.80 Model Num: Keyboard
- 1 Gikfun MTS102 2 Position 3 Pins Mini Toggle Switch (Can be found on Amazon) $0.90 Model Num: LYSB01BWL7Z44-ELECTRNCS
- 1 Elegoo Arduino Mega 2560 (Can be found on Amazon) $20 Model Num: EL-CB-003
- 1 Qunqi L298N Motor Driver (Can be found on Amazon) $4 Model Num: MK-050-2
- 1 Qunqi 400 tie Point Experiment Mini Breadboard (Can be found on Amazon) $6 Model Num: 8541770369
- OWOFYDR 100 pcs 5mm Green LED Diode Lights (Only need 2 out of 100, Can be found on Amazon) $0.14 per LED, 7 per pack Model Num:OWO-LED-1008
- REV 35 mm Screw (REV Robotics online store) $0.23 for one, 11.50 for pack Model Num: REV-41-1125-PK50 
- REV M3 nut (REV Robotics online store) $0.055 for one, 5.50 for pack Model Num: REV-41-1126-PK100

### Non-Specific Parts

- Solder
- Soldering Iron
- Hot glue
- Hot glue gun
- Wires
- Wire
- Wire cutters
- Shrink Wrap / Electrical Tape
- Heat Gun (If using shrink wrap)
- Drill
- 3D printer
- Wire Nuts
- Lot's or patience
- 9v Power Source

## Instructions on how to make it

First off, print all of the parts in the CAD file. This should take a while, but it is all needed. We recommend using ABS or likewise filiments like ASA. The only part that needs to be duplicated is the wheel, we need two of those. Depending on your 3D printers limitations you may need supports on some places and not others.

### Flywheel

Lets make the flywheel!

This part is kind of hard so pay attention. 

First lets get the motors mounted. This part is kind of awkward so you may need a helping hand. You need to hold the motors in the holes at the top of the flywheel frame so that it barely pokes out. Then hot glue this down. Repeat this on the other side. Refer to **Figure 3** to see how it should look.


Now the wheels are friction fit so it will be hard to put those on. Just push them on so that the side with the extra nub is pointing down. Refer to the image above. At this point I recommend making sure that when you push through nerf darts they actually contact the wheels. If they do then we can move on! If not you may need to re-glue the motors.

Now you need to solder wires to the little tabs on the motors. Simply solder any wire on and try not to bend the tabs because they are very fragile. 

Now let's add the magazine. You simply need to glue this peice on to the rail the nerf dart and lay in. You can see where on **Figure 8**

Now here is where we got droven crazy. You need to put your servo horn on your servo and fish it into the casing on the mag so that the horn is facing down. Now you need to turn the servo horn in a way so that you can put a screw in it, however you do not want it to enter the actual mag yet. Now slowly start turning the hex nut up the servo horn and then place it in the guide rail as seen in **Figure 9**.

Then lift the screw and place it in the guide rail. Slowly tighten the nut until the nut and screw head are both nearly touching the servo horn. It should look like **Figure 10**.

## Wiring

Now using the wiring diagram shown above you need to wire everything together. It's gonna suck, but trust me it will be worth it. This will probably be most of your time though. **Figure 11** and **12** show a couple photo's of the internals.

This should give a general idea on how to lay it out however feel free to customize placements.

Here you can also mount the turnS servo that connects to pin 4. This should be mounted to the top of the pyramid.
Also put the number pad on the outside and drill a hole next to it for you to put your switch. Refer to **Figure 13**

Now all you have left is to place the flywheel on the top of the turnS servo. We recommend to fill the hole for mounting with hot glue and the putting it on. Once doing this and then wiring it up your all done!

## Appendix
**Figure 1 (Equation diagram)**
![Trig (1)](https://user-images.githubusercontent.com/90796319/236632996-c2adf86e-2c53-4243-b716-d77638e1a450.png)

**Figure 2 (Flowchart)**

![Screenshot 2023-05-05 8 45 22 AM](https://user-images.githubusercontent.com/90726645/236860682-773ab67a-9cd7-43cb-9b15-efd395f15891.png)

**Figure 3 (Flywheel)**
![IMG_7484](https://user-images.githubusercontent.com/90796319/236633643-75754146-f234-44ed-bb64-e61d4b635fa1.jpg)

**Figure 4 (Magazine)**
![IMG-9581](https://user-images.githubusercontent.com/90726645/236862679-7712c94e-277b-4f4b-956a-b6c7589ea782.jpg)

**Figure 5 (Pyramid and Base)**
![IMG_7485](https://user-images.githubusercontent.com/90796319/236634032-0495928d-9c54-4fb2-8527-d5d895ce1d8a.jpg)

**Figure 7 (Software diagram)**

![W](https://user-images.githubusercontent.com/90796319/236634588-83be4c4c-efef-413d-98c5-b242709320e2.jpg) 

**Figure 8 (Magazine Placement)**
![IMG_7486](https://user-images.githubusercontent.com/90796319/236637957-ba5493f5-0131-4cb0-9d17-55a9cc7a80ef.jpg)

**Figure 9 (Servo Horn Placement)**
![IMG_7487](https://user-images.githubusercontent.com/90796319/236638454-7f8b14ac-03b8-4b92-bc51-8e96bebc6e0f.jpg)

**Figure 10 (Screw Placemen)**
![IMG_7488](https://user-images.githubusercontent.com/90796319/236638685-70ab4740-ee16-4452-b838-63852ffd313e.jpg)  

**Figure 11 (Wiring pt. 1)**
![IMG_7490](https://user-images.githubusercontent.com/90796319/236638865-d2ae459d-eea6-4d94-bd0a-724d4f91b943.jpg)

**Figure 12 (Wiring pt. 2)**
![IMG_7489](https://user-images.githubusercontent.com/90796319/236638871-105eca3e-c3a3-4d4c-b98b-56272b1de57f.jpg)

**Figure 13 (Pyramid and Number Pad)**
![IMG_7485](https://user-images.githubusercontent.com/90796319/236638974-d58c3481-1675-422e-8aec-b6fef2787c54.jpg)





