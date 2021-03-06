#include <Servo.h>

// defines pins numbers

//Ulrasonic
const int trigPin1 = 3;
const int echoPin1 = 2;
const int trigPin2 = 5;
const int echoPin2 = 4;

int distance1;
int distance2;

//servo motors
Servo servo1;
Servo servo2;

int servo1PosCur = 0;
int servo1PosNext = 0;

int servo2PosCur = 0;
int servo2PosNext = 0;

void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  servo1.attach(7);
  servo2.attach(8);
}

void loop() {
  Serial.println("-------------------------");
  Serial.println("Reading Distance...");
  distance1 = getDistance(trigPin1,echoPin1);
  distance2 = getDistance(trigPin2,echoPin2);
  
  Serial.println("Turning Servo...");
  distance1 = constrain(distance1, 5, 35);
  distance1 = map(distance1, 0, 35, 0, 180);
  servo1PosNext = distance1;
  turnServo(servo1PosCur,servo1PosNext,1);
  servo1PosCur = distance1;

  distance2 = constrain(distance2, 5, 35);
  distance2 = map(distance2, 0, 35, 0, 180);
  servo2PosNext = distance2;
  turnServo(servo2PosCur,servo2PosNext,2);
  servo2PosCur = distance2;
  delay(100);
}


int getDistance(int trigPin,int echoPin){
  long duration;
  int distance;
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  return distance;
}

void turnServo(int cur,int next,int servoNo){
  int pos = 0;
  if( cur == next );
  else if(cur > next){
    for(pos = cur; pos >= next; pos--){
      if(servoNo == 1 ){
        servo1.write(pos);  
      }
      else{
        servo2.write(pos);  
      }
      delay(15);  
    }  
  }
  else{
    for(pos = cur; pos <= next; pos++){
      if(servoNo == 1 ){
        servo1.write(pos);  
      }
      else{
        servo2.write(pos);  
      }
      delay(15);  
    }  
  }
  
}
