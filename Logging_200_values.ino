/* Program to read temperature and humidity values and store these readings in a CSV file
The purpose of this program is to use a DHT11 sensor to sense the temperature and humidity, open an SD 
card, create a file, deposit these values in this file. and close the file before repeating this process. 
 */
#include <SPI.h>  // Add SPI communication to library code
#include <SD.h> // Add SD to library code
#include "DHT.h"; // Add DHT to library code
#define DHTPIN 7  // Define the digital pin (7) to be used for the DHT module
#define DHTTYPE DHT11 // Define the version of the DHT sensor being used as DHT11 rather than DHT22

DHT dht (DHTPIN, DHTTYPE);  // Declare the DHT module

float hum;  // Declare "hum" as the value of the humidity measured by the DHT module
float temp; // Declare "temp" as the value of the temperature measured by the DHT module

File myFile;  // Interact with the file

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Set the baud rate to 9600 bits per second
  dht.begin();  // Allows the sensor to begin process of taking readings of temperature and humidity 

  while (!Serial) {   // wait for serial port to connect
    ; 
}
  Serial.print("Initializing SD card...");  // Print the phrase "Initializing SD card..." in the serial monitor to let us know it is trying to reach the SD card

  if (!SD.begin(4)) {   // If initialization is unsuccessful
    Serial.println("initialization failed!"); // Print the phrase "initialization failed!" to the serial monitor
    while (1); 
  }
  Serial.println("initialization done."); // If initialization is successful, print the phrase "initialization done." to the serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
  delay (1000); // Have a 1000 millisecond delay between readings
  temp = dht.readTemperature(); // Read the temperature value under "temp"
  hum = dht.readHumidity(); // Read the humidity value under "hum"
  
  myFile = SD.open("readings.txt", FILE_WRITE); // Open the file named "readings.txt" within the SD card to be able to write within the file

  if (myFile) {   // If the file is opened successfully
    Serial.print("Writing to readings.txt..."); // Print the phrase "Writing to readings.txt..." to the serial monitor after the file has been opened
    myFile.print(temp); // Print the temp value into the "readings.txt" file 
    myFile.print(",");  // Print a comma into the "readings.txt" file directly after the temp value
    myFile.println(hum);  // Print the hum value into the "readings.txt" file directly after the comma, then skip to the next line for the following reading
    myFile.close(); // Close the file
    Serial.println("done.");  // Print the phrase "done." to the serial monitor to indicate that the reading has been successfully stored in the SD card
  } 
    else {  // If the file is not opened successfully
    Serial.println("error opening readings.txt"); // Print the phrase "error opening readings.txt" to the serial monitor
  }
}
