/*Program to display the temperature and humidity values in the serial monitor
The purpose of this program is to use a DHT11 Temperature and Humidity Module to
sense the temperature and humidity and display these two values in the Serial Monitor.
*/
#include "DHT.h"; //Add DHT to library code
#define DHTPIN 7  //Define the digital pin (7) to be used for the DHT module
#define DHTTYPE DHT11 //Define  the version of the DHT sensor being used as DHT11 rather than DHT22
float hum;  //Declare "hum" as the value of the humidity measured by the DHT module
float temp; //Declare "temp" as the value of the temperature measured by the DHT module

DHT dht (DHTPIN, DHTTYPE);  //Declare the DHT module

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Set the baud rate to 9600 bits per second
  dht.begin();  //Allow the sensor to begin gathering the desired information (temperature and humidity)
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);  //Have a 1000 millisecond delay between readings of the temperature and humidity

  hum = dht.readHumidity(); //Read the humidity value under "hum"
  temp = dht.readTemperature(); //Read the temperature value under "temp"

  Serial.print("Humidity: "); //Print the phrase "Humidity: " in the serial monitor
  Serial.print(hum);  //Print the value of the humidity in the serial monitor 
  Serial.print("%, Temp: ");  //Print the phrase "%, Temp: " in the serial monitor
  Serial.print(temp); //Print the value of the temperature in the serial monitor
  Serial.println("C");  //Print the phrase "C" in the serial monitor
}
