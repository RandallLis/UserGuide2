/* Program to make a DC motor turn clockwise and counterclockwise with IC (L293D)
The purpose of this program is to cause the DC motor to alternate between moving 
clockwise and counterclockwise every 1000 milliseconds
 */
int MotorPin1 = 9;  // Declare "MotorPin1" as a variable for pin 9 
int MotorPin2 = 10; // Declare "MotorPin2" as a variable for pin 10

void setup() {
  // put your setup code here, to run once:
pinMode(MotorPin1, OUTPUT); // Identify digital pin 9 (MotorPin1) as an output
pinMode(MotorPin2, OUTPUT); // Identify digital pin 10 (MotorPin2) as an output

}

void loop() {
  // The DC motor will spin clockwise for 1000 milliseconds
digitalWrite(MotorPin1, HIGH);  // Sets MotorPin1 to the HIGH state 
digitalWrite(MotorPin2, LOW); // Sets MotorPin2 to the LOW state 
delay(1000);  // Stays in this state for 1000 milliseconds

  // The DC motor will now spin counterclockwise for 1000 milliseconds
digitalWrite(MotorPin1, LOW); // Sets MotorPin1 to the LOW state
digitalWrite(MotorPin2, HIGH);  // Sets MotorPin2 to the HIGH state
delay(1000);  // Stays in this state for 1000 milliseconds
}
