// A temperature sensor application for Particle Argon and a DHT11 sensor.
#include <Adafruit_DHT.h>
#include <string>

#define DHTPIN D2
#define DHTTYPE DHT11

int temperature;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    
    dht.begin();
}

void loop() {
    
    temperature = 0;
    
    // Use a while loop to throw out bad reads
    while (temperature == 0) {
        
        // Wait to account for sampling rate
        delay(1000);
        
        // Capture temperature
        temperature = round(dht.getTempCelcius());
    }
    
    // Publish to webhook
    Particle.publish("temp", String(temperature), PRIVATE);
    
    // Wait 30 seconds
    delay(30000); 
}
