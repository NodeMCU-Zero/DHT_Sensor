/* Free to use ( From Algobel TI ) 
* feel free to send feed back 
* Thanks for the community for supporting free libries 

|--------------|
|              |
|   DHT 11           |
|--------------|
  |  |  |  |
  1  2  3  4
  
  1 = VCC
  2 = DATA
  3 = NC ( Not Connected)
  4 = GND 
  
  * Connect 1 pin to 3.3 v supply 
  * pin 1 ---/\/\/\/\/\---- pin2  ( 47K Ohms) 
  * pin 4 connect to ground 
  
*/



#include "DHT.h"

#define DHTPIN 14     // what digital pin we're connected to  D5 = 14;

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT Connected...");
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
}
