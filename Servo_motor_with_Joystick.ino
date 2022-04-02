/* Program to control the movement of a servo motor through the use of a joystick.
The purpose of this program is to connect a servo motor to the y axis of a joystick, therefore 
causing the servo motor to turn 180 degrees depending on the joystick's position along this axis
 */
#include <Servo.h>  // Add Servo to library code
int y_pin = A0; // Delcare "y_pin" as a variable for analog pin 0 (A0) 

Servo servo;  // Declare the servo module by calling it servo

int val;  // Declare val as a variable for the joystick value

void setup() {
  // put your setup code here, to run once:
servo.attach(11); // Start the servo which is connected to digital pin 11
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(y_pin);  // Read value of the y_pin of the joystick
val = map(val, 0, 1023, 0, 180);  // Convert the value read from 0-1023 to 0-180
servo.write(val); // Write this value to the servo for it to move accordingly
}
