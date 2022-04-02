/*Program to display the temperature and humidity values on the LCD
The purpose of this program is to use a DHT11 Temperature and Humidity Module to
sense the temperature and humidity and display these two values on the LCD.
*/
#include "DHT.h"; // Add DHT to library code
#include <LiquidCrystal.h>  // Add LCD to library code

LiquidCrystal lcd (12, 11, 5, 4, 3, 2); // Declare these pins to connect to the LCD display

#define DHTPIN 7  // Define the digital pin (7) to be used for the DHT module
#define DHTTYPE DHT11 // Define  the version of the DHT sensor being used as DHT11 rather than DHT22

float hum;  // Declare "hum" as the value of the humidity measured by the DHT module
float temp; // Declare "temp" as the value of the temperature measured by the DHT module

DHT dht (DHTPIN, DHTTYPE);  // Declare the DHT module

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Set the baud rate to 9600 bits per second
  lcd.begin(16,2);  // Identify the LCD display as having 16 columns and 2 rows 
  dht.begin();  // Allow the sensor to begin gathering the desired information (temperature and humidity)
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);  // Have a 1000 millisecond delay between readings of the temperature and humidity

  hum = dht.readHumidity(); // Read the humidity value under "hum"
  temp = dht.readTemperature(); // Read the temperature value under "temp"

  lcd.setCursor(0,0); // Set the starting point of the following print to the coordinate 0,0
  lcd.print("Temp:  Humidity:"); // Print the phrase "Temp:  Humidity:" on the LCD
  
  lcd.setCursor(0,1); // Set the starting point of the following print to the coordinate 0,1
  lcd.print(temp); // Print the value of the temperature on the LCD
  
  lcd.setCursor(5,1); // Set the starting point of the following print to the coordinate 5,1
  lcd.print("C"); // Print the phrase "C" on the LCD
  
  lcd.setCursor(7,1); // Set the starting point of the following print to the coordinate 7,1
  lcd.print(hum); // Print the value of the humidity on the LCD 
  
  lcd.setCursor(12,1);  // Set the starting point of the following print to the coordinate 12,1
  lcd.print("%"); // Print the phrase "%" on the LCD
}
