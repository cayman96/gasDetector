// to musimy zawrzeć jak chcemy korzystać z funkcji od arduino
#include <Arduino.h>
//piny na led, buzzer i analogowe wejście
#define led 0
#define buzz 1
#define sensor 1 //UWAGA, to jest pin P2, ale z jakiegoś powodu ATTiny85 rozpoznaje analogowe wejście jako 1. Odsyłam do pinoutu.
// czas na mignięcie
unsigned long prevTime = 0;
const long ivl = 10000;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  //start odmierzania czasu
  unsigned long currTime = millis();
  //odczyt z czujnika
  float sensor_val = analogRead(sensor);
  //konwersja na wolty
  float v = sensor_val*(5.00/1023.0);
  //jeśli napięcie wejściowe wyniesie 3.00 lub więcej to alarm
  if(v >= 3.00) {
    digitalWrite(led, HIGH);
    tone(buzz,1400,200);
    delay(200);
    digitalWrite(led,LOW);
    delay(300);
    };
  //mrygnięcie od czasu do czasu, domyślnie co 10 sekund
  if(currTime - prevTime >= ivl){
    prevTime = currTime;
    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led, LOW);
    }
}
