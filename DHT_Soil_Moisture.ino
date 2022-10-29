
#include <math.h> 
#include <DHT.h>
#define moisturePin A1
#define DHTPIN 2 //digital
#define DHT_TYPE DHT22  
const float Vcc = 5.0f;
const float airVolts = 2.9f;
const float waterVolts = 1.4f;
DHT dht(DHTPIN, DHT_TYPE);

void setup() {
  dht.begin(); //Initialise the DHT sensor
  Serial.begin(9600); // Initialise Serial debug output
  while (!Serial && millis() < 10000)
    ; //Wait a maximum of 10s for Serial to open
}
void loop() {
  float soilVolts = Vcc*analogRead(moisturePin)/1024;
  int moisturePercent = map(soilVolts, airVolts, waterVolts, 0, 100);
  Serial.print("moisture = ");
  Serial.println(moisturePercent); 
  
  
  int humidity = dht.readHumidity();
  Serial.print("humidity = ");
  Serial.println(humidity);
 
  int temperature = dht.readTemperature();
  Serial.print("temperature = ");
  Serial.println(temperature);


  
  delay(2000);
}
