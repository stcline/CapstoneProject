// Include Libraries
#include <Servo.h>


// Define pins for distance sensors
#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
Servo myservo;

// define global variables
long sduration1, sduration2;
float sdistance1, sdistance2;
bool movementL, movementR;

void setup()
{
myservo.attach(9);

Serial.begin (9600);
// PinModes
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
// Get Starting Positions


// Use Ultrasonic Left
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
sduration1 = pulseIn(echoPin1, HIGH);
// Use Ultrasonic Right
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
sduration2 = pulseIn(echoPin2, HIGH);
// Calculate distance
sdistance1 = sduration1 * 0.034 / 2;
sdistance2 = sduration2 * 0.034 / 2;

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
// Use Ultrasonic Right
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
// Calculate distance
distance1 = duration1 * 0.034 / 2;
distance2 = duration2 * 0.034 / 2;

// Test print
getDirection(distance1, distance2, sdistance1, sdistance2);
delay(200);
}
// Test print function
void testPrintDist(int dist1, int dist2)
{
  Serial.print(dist2);
  Serial.print(" - ");
  Serial.print(dist1);
  Serial.println("");
}
void getDirection(int d1, int d2, int s1, int s2)
{
  if ((d1 < (s1-7)) and (movementR == false))
  {
    movementL = true;
    Serial.println("LEFT");
  }
  if ((d2 < (s2-7)) and (movementL == false))
  {
    movementR = true;
    Serial.println("RIGHT");
  }
  
}




