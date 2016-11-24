// This program shown how to control arduino from PC Via Bluetooth
// Connect ...
// arduino>>bluetooth
// D11   >>>  Rx
// D10   >>>  Tx
//Written By Mohannad Rawashdeh
//for http://www.genotronex.com/

// you will need arduino 1.0.1 or higher to run this sketch

#include <SoftwareSerial.h>// import the serial library

SoftwareSerial mySerial=SoftwareSerial(10, 11); // RX, TX
int ledpin=13; // led on D13 will show blink on / off
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)
int ledState = LOW;             // ledState used to set the LED
long Counter=0; // counter will increase every 1 second
boolean connectedvar = false;
void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  mySerial.println("Bluetooth On please wait....");
  pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis;
  boolean connectedvar=false;
  previousMillis=millis();
  connectedvar=mySerial.available();
  while(connectedvar){
    currentMillis = millis();
 
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledpin, ledState);
    currentMillis=(currentMillis-previousMillis)/1000;
    mySerial.println(currentMillis);
    mySerial.println(mySerial.available());
    //}
  }
 
  delay(100); 
}


