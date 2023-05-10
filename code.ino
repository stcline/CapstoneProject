// Include Libraries
#include <Servo.h>
#include <Keypad.h>
// Define pins for distance sensor
#define trigPin1 13
#define echoPin1 50
#define led1 36 
#define led2 35
// define global variables
long sduration1;
float sdistance1;
bool movement;
bool enterNums;
bool l1ON;
String enteredNums;
// Inputed value from NumPad
int x;
// Angle for turnS servo
float angle;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
// Setting up servos
Servo turnS;
Servo shootS;
// Motor Controller variables
int ena=6;
int in1=32;
int in2=33;
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {22, 23, 24, 25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {26, 27, 28, 29}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
void setup()
{
// Making sure bool is false
movement = false;
Serial.begin (9600);
// PinModes
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(ena, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
// Attaching servos to pins
turnS.attach(4);
shootS.attach(5);
// Use Ultrasonic Sensor start run
// This gets the sdistance used later
delay(100);
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
sduration1 = pulseIn(echoPin1, HIGH);

// Calculate distance
sdistance1 = sduration1* 0.034 / 2;
// Confirming bool is false
enterNums = false;
l1ON = false;
// Draw back mag servo
shootS.write(35);
}

void loop() {
// Define kind of variables
long duration1, duration2;
float distance1, distance2;

// Use Ultrasonic Sensor
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);

// Calculate distance
distance1 = duration1 * 0.034 / 2;
// Delay to not overload arduino
delay(200);
// Testing to see if numbers on numpad have been entered
if (enterNums == false){
  getNumbers();
}
// If numbers have been entered then it getDirection below, if that true it used the function to shoot 
if (enterNums == true) {
  getDirection(distance1, sdistance1, x);
  if (movement == true) {
    shootEmJohn(angle);
  }
  delay(100);
}
}
// Used to find the difference between the original distance and what it sensed now
void getDirection(int d1, int s1, int x)
{
  if ((d1 < (s1-10)))
  {
  //Serial.println("TARGET"); //These are all testing prints that are useful if you don't know if it's working
  //Serial.println(d1);
  //Serial.println(x);
  //Uses arc tangent to calculate centeral angle, more on the README.md 
  angle = atan2(d1,x);
  // Turns radian mesure to degrees
  angle=angle*(180/3.14159);
  movement=true;
  }
}
void getNumbers()
{ 
  // Checks if there is a custom key entered
  char customKey=customKeypad.getKey();
  // If there is then it continues
  if (customKey){
    // If custom key isn't A than add it to the variable enteredNums
    if (customKey != 'A'){
      enteredNums = enteredNums+customKey;
      // To turn on the LEDS
      if (l1ON == false){
        digitalWrite(led1, HIGH);
        l1ON = true;
      }
      else{
        digitalWrite(led2, HIGH);
      }
    }
    // If the button pressed is A than turn entered nums into an interger, and adjust lights
    if (customKey == 'A'){
      x = enteredNums.toInt();
      enterNums = true;
      l1ON = false;
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
  }
  
}
void shootEmJohn(int a)
{
  //Turn servo
  turnS.write(a);
  //Start motors
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 255);
  delay(1000);
  //Push dart
  shootS.write(160);
  delay(1000);
  //Return to original position
  turnS.write(90);
  shootS.write(35);
  analogWrite(ena,0);
  movement=false;  
}

