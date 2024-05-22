#include <Arduino.h>
#include <NewPing.h>

#define echoPIN 9
#define trigPIN 8
#define ledPIN 3

  NewPing ultrasonic(trigPIN,echoPIN,50); //max distance 50 CM

void setup() {
  pinMode(ledPIN,OUTPUT);
  Serial.begin(9600);
  Serial.println("Testing Ultrasonic");
}

void loop() {
  delay(200); //200ms between readings
  long distance = ultrasonic.ping_cm();
  Serial.print(F("Distance (cm): "));
  Serial.println(distance);
  if(distance < 20 && distance != 0 ) { //when distance > max distance, it is read as 0, we want to avoid that.
    digitalWrite(ledPIN,HIGH); //Glow if too close
  } else {
    digitalWrite(ledPIN,LOW);
  }
}
