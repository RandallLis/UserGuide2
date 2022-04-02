/* Program to turn a DC motor on and off with the help of a relay.
Through the use of a 9V battery to allow the DC motor to run, this motor will turn on and off 
according to the program below when the designated digital pin turns on and off.
 */
void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);  // Identify digital pin 13 as an output
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13, HIGH); // Turn on the DC motor when digital pin 13 is HIGH
delay(3000);  // Stay in this state for 1000 milliseconds
digitalWrite(13, LOW);  // Turn off the DC motor when digital pin 13 is LOW
delay(3000);  // Stay in this state for 1000 milliseconds
}
