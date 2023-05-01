#include <FastTrig.h>


//Pins used: 2345,54329876//Change some pins

// Include Libraries
#include <Servo.h>
#include <Keypad.h>



// Define pins for distance sensors
#define trigPin1 2
#define echoPin1 30



// define global variables
long sduration1, sduration2;
float sdistance1, sdistance2;
bool movementL, movementR;
bool enterNums;
String enteredNums;
int x;
float angle;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
Servo turnS;
Servo shootS;
int ena=6;
int in1=32;
int in2=33;
//define the cymbols on the buttons of the keypads
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
movementL = false;
Serial.begin (9600);
Serial.println("START");
// PinModes
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);

pinMode(ena, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
turnS.attach(4);
shootS.attach(5);
// Get Starting Positions


// Use Ultrasonic Left
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
sduration1 = pulseIn(echoPin1, HIGH);

// Calculate distance
sdistance1 = sduration1 * 0.034 / 2;
Serial.println(sdistance1);
enterNums = false;
shootS.write(40);
}

void loop() {
// Define kind of variables
long duration1, duration2;
float distance1, distance2;

// Use Ultrasonic Left
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);

// Calculate distance
distance1 = duration1 * 0.034 / 2;
delay(400);
// Test print
if (enterNums == false){
  getNumbers();
}
if (enterNums == true) {
  getDirection(distance1, sdistance1, x);
  if (movementL == true) {
    shootEmJohn(angle);
  }
  delay(100);
}
}
// Test print function

void getDirection(int d1, int s1, int x)
{
  int angle1;
  if ((d1 < (s1-10)))
  {
  Serial.println("TARGET");
  Serial.println(d1);
  Serial.println(x);
  angle = atan2(d1,x);
  Serial.println(angle);
  angle=angle*(180/3.14159);
  Serial.println(angle);
  movementL=true;
  }
}
void getNumbers()
{
  char customKey=customKeypad.getKey();
  if (customKey){
    if (customKey != 'A'){
      Serial.println(customKey);
      enteredNums = enteredNums+customKey;
      Serial.println(enteredNums.toInt());
    }
    if (customKey == 'A'){
      x = enteredNums.toInt();
      enterNums = true;
    }
  }
  
}
void shootEmJohn(int a)
{
  turnS.write(a);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 255);
  delay(200);
  shootS.write(130);
  delay(1000);
  turnS.write(-a);
  shootS.write(40);
  analogWrite(ena,0);
  movementL=false;  
}


