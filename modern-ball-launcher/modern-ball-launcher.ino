/*
        Arduino Brushless Motor Control
     by Dejan, https://howtomechatronics.com
*/

#include <Servo.h>
#define MAX_VALUE 180
#define MIN_VALUE 0
#define MIN_PULSE_LENGTH 1000 // Minimum pulse length in µs
#define MAX_PULSE_LENGTH 2000 // Maximum pulse length in µs
#define POT_PIN A2
#define MOTOR_1_PIN 9
#define MOTOR_2_PIN 10

Servo ESC;     // create servo object to control the ESC

int potValue;  // value from the analog pin

void setup() {
  Serial.begin(9600);
  // Attach the ESC on pin 9
  delay(2000);
  ESC.attach(MOTOR_1_PIN,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  ESC.write(MIN_PULSE_LENGTH);
  delay(1000);
  ESC.write(MAX_PULSE_LENGTH);
}

void loop() {
  potValue = analogRead(POT_PIN);   // reads the value of the potentiometer (value between 0 and 1023)
  potValue = map(potValue, 0, 1023, 180, 0);   // scale it to use it with the servo library (value between 0 and 180)
  if(potValue < 15) potValue = 0;
  ESC.write(potValue);    // Send the signal to the ESC
  Serial.println(potValue);
  delay(100);
}
