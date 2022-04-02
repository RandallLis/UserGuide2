/* Program to control the movement of a stepper motor through the use of a joystick.
The purpose of this program is to connect a stepper motor to the y axis of a joystick, therefore causing the 
stepper motor to turn clockwise and counterclockwise depending on the joystick's position along this axis
 */
#include <Stepper.h>  // Add Stepper to library code
#define STEPS 32  // Define how many steps per revolution of the motor
#define IN1  11 // Define digital pin 11 as the pin associated with IN1 on the Stepper Motor Driver Module
#define IN2  10 // Define digital pin 10 as the pin associated with IN2 on the Stepper Motor Driver Module
#define IN3   9 // Define digital pin 9 as the pin associated with IN3 on the Stepper Motor Driver Module
#define IN4   8 // Define digital pin 8 as the pin associated with IN4 on the Stepper Motor Driver Module

Stepper stepper(STEPS, IN4, IN2, IN3, IN1); // Initialize the stepper library

#define joystick A0  // joystick pot output is connected to Arduino A0

void setup(){
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  
int val = analogRead(joystick); // Read value from joystick as an Analog value

  if((val > 500) && (val < 523))  // Stop the motor if the joystick value is between 500 and 523 
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  else {
    while (val >= 523)  // When joystick value from 0-1023 is less than or equal to 523
    {   
      int speed_ = map(val, 523, 1023, 5, 500); // Map the speed between 5 and 500
      stepper.setSpeed(speed_); // Set speed of the motor
      stepper.step(1);  // Move the motor by 1 step (1/32 of a revolution) in the clockwise direction
      val = analogRead(joystick); // Read the new value from the joystick after newest movement
    }
    while (val <= 500)  // move the motor in the other direction
    {
      int speed_ = map(val, 500, 0, 5, 500);  // Map the speed between 5 and 500 
      stepper.setSpeed(speed_); // Set speed of the motor 
      stepper.step(-1); // Move the motor by 1 step (1/32 of a revolution) in the counterclockwise direction
      val = analogRead(joystick); // Read the new value from the joystick after newest movement
    }
  }
}
