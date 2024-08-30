#include "DHT.h"

#define DPIN 4        //Pin to connect DHT sensor (GPIO number) D2
#define DTYPE DHT11   // Define DHT 11 or DHT22 sensor type
#define LED_PIN1 5     // Pin for the LED
#define LED_PIN2 12

#define ldr_pin A0
#define LED_PIN3 16

DHT dht(DPIN,DTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_PIN1, OUTPUT); // Set the LED pin as output
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(ldr_pin, INPUT);
}

void loop() {
  delay(1000);
  
  float tc = dht.readTemperature(false);  //Read temperature in C
  float hu = dht.readHumidity();          //Read Humidity

  Serial.print("Light: ");
  Serial.print(analogRead(ldr_pin));
  Serial.print(" Lux, ");

  Serial.print(" Temp: ");
  Serial.print(tc);
  Serial.print(" C, ");
  Serial.print(" Hum: ");
  Serial.print(hu);
  Serial.println("%");

  if (tc > 29 ) {
    digitalWrite(LED_PIN1, HIGH); // Turn the LED on
  } else {
    digitalWrite(LED_PIN1, LOW);  // Turn the LED off
  }

  if( hu > 86 ){
    digitalWrite(LED_PIN2, HIGH);
  } else{
    digitalWrite(LED_PIN2, LOW);
  }

  if(analogRead(ldr_pin) > 500){
    digitalWrite(LED_PIN3, HIGH);
  } else {digitalWrite(LED_PIN3, LOW);}
}