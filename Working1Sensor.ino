#include <Servo.h>

#include <Key.h>
#include <Keypad.h>
long sduration1, sduration2;
float sdistance1, sdistance2;
int trigPin1 = 12;
int echoPin1 = 11;
bool enterNums;
String enteredNums;
int x;
float angle;
const byte ROWS = 4; //four rows
const byte COLS = 4;
Servo turnS;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  Serial.println("START");
  // PinModes
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  enterNums = false;
  turnS.attach(10);

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  sdistance1 = sduration1 * 0.034 / 2;
  Serial.println(sdistance1);
}

void loop() {
  long duration1, duration2;
  float distance1, distance2;

  // Use Ultrasonic Left
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  if (enterNums == false){
    getNumbers();
  }
  if (enterNums == true) {
  getDirection(distance1, sdistance1);
  delay(200);
  
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
      turnS.write(angle);
    }
    if (customKey == 'A'){
      x = enteredNums.toInt();
      enterNums = true;
    }
  }
  
}
void getDirection(int d1, int s1)
{
  int angle1;
  if ((d1 < (253-10)))
  {
  Serial.println("LEFT");
  angle = atan(d1/x);
  Serial.println(angle);
  angle=angle*(180/3.14159);
  Serial.println(angle);
  }
}
