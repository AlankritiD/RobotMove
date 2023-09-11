//#include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library
#include <Servo.h> //Servo library. This is standard library. (Sketch -> Include Library -> Servo)
String voice;

//AF_DCMotor motor1 (1, MOTOR12_1KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
//AF_DCMotor motor2 (2, MOTOR12_1KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
Servo myServo; //define servo name
int LED1 = A0; //define LED 1 pin
int LED2 = A1; //define LED 2 pin
int buzzerPin = A2; //define buzzer pin
int m11 = 2;
int m12 = 3;
int m21 = 4;
int m22 = 5;
int m31 = 6;
int m32 = 7;
int m41 = 8;
int m42 = 9;



void setup()
{
  Serial.begin(9600); //start serial communication
  myServo.attach(10); //define our servo pin (the motor shield servo1 input = digital pin 10)
  myServo.write(90); //servo position is 90 degrees
  pinMode(LED1, OUTPUT); //A0 is output pin
  pinMode(LED2, OUTPUT); //A1 is output pin
  pinMode(buzzerPin, OUTPUT); //A2 is output pin
}

void loop()
{
  while (Serial.available()) { //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {
      break; //Exit the loop when the # is detected after the word
    }
    voice += c; //Shorthand for voice = voice + c
  }
   
    forward_car();
    delay(3000); // Wait for 3 seconds
    back_car();
    delay(3000); // Wait for 3 seconds
    left_car();
    delay(3000); // Wait for 3 seconds
    rotateyourhead();
    delay(4000);
    doeverything();
    delay(3000);
    stop_car();
  }

void forward_car()
{
  
  for (int i = 2; i < 11 ; i++)
  {
    digitalWrite(i, LOW);
  }
  digitalWrite(2, HIGH);//LEFT MOTOR FORWARD
  digitalWrite(4, HIGH);//RIGHT MOTOR FORWARD

}

void back_car()
{
  
  for (int i = 2; i < 11 ; i++)
  {
    digitalWrite(i, LOW);
  }
  digitalWrite(3, HIGH);//LEFT MOTOR REVERSE
  digitalWrite(5, HIGH);//LEFT MOTOR REVERSE

}

void right_car()
{
  
  for (int i = 2; i < 11 ; i++)
  {
    digitalWrite(i, LOW);
  }
  digitalWrite(3, HIGH);

}

void left_car()
{
  
  for (int i = 2; i < 11 ; i++)
  {
    digitalWrite(i, LOW);
  }
  digitalWrite(5, HIGH);

}

void stop_car()
{
  for (int i = 2; i < 11 ; i++)
  {
    digitalWrite(i, LOW);
  }
}

void rotateyourhead()
{
  for (int i = 2; i < 11 ; i++)
  {
    digitalWrite(i, LOW);
  }
  digitalWrite(8, HIGH);
  delay(3000);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void doeverything()
{
  for (int i = 2; i < 11 ; i++)
  {
    digitalWrite(i, LOW);
  }
  digitalWrite(2, HIGH);//LEFT MOTOR FORWARD
  digitalWrite(4, HIGH);//RIGHT MOTOR FORWARD
  digitalWrite(6, HIGH);//LEFT MOTOR FORWARD
  digitalWrite(8, HIGH);//RIGHT MOTOR FORWARD
}
