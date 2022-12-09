#include <FastLED.h>
#define LED_PIN 3
#define NUM_LEDS 144

CRGB leds[NUM_LEDS];

#define sensorPin1 7
#define sensorPin2 8
                                                                                                          
int relay1=6;
int relay2=5;
int sensorState1 = 0;
int sensorState2 = 0;
int count=0;
int ledState1 = HIGH;
int ledState2 = HIGH;
unsigned long previousMillis = 0;
const long interval = 5000;
unsigned long previousMillis1 = 0;
const long interval1 = 4000;
unsigned long previousMillis2 = 0;
const long interval2 = 3000;
void setup()
{
FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
FastLED.clear();
FastLED.show();
  pinMode (sensorPin1,
INPUT_PULLUP);
  pinMode (sensorPin2, INPUT_PULLUP);
 pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
 digitalWrite(relay1, ledState1);
     digitalWrite(relay2, ledState2);
 Serial.begin(9600); 
}

void loop()
{  
  sensorState1 = digitalRead(sensorPin1);
  sensorState2 = digitalRead(sensorPin2);

  if(sensorState1 == LOW){
    count+=1; 
    delay(500);
  }

  if(sensorState2 == LOW){
    count-=1; 
    delay(500);
  }
  

   if(count<=0)
  {
    digitalWrite(relay1, HIGH);
     digitalWrite(relay2, HIGH);
  Serial.println("No Visitort");
  }
  else if (count>0 && count<=5){
    Serial.println(count);
    unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState1 == HIGH) {
      ledState1 = LOW;
      ledState2 = HIGH;
    } else {
      ledState1 = HIGH;
       ledState2 = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(relay1, ledState1);
     digitalWrite(relay2, ledState2);
  }
  }
  else if (count>=6 && count<=10){
   
    Serial.println(count);
    unsigned long currentMillis1 = millis();

  if (currentMillis1 - previousMillis1 >= interval1) {
    // save the last time you blinked the LED
    previousMillis1 = currentMillis1;

    // if the LED is off turn it on and vice-versa:
    if (ledState1 == HIGH) {
      ledState1 = LOW;
      ledState2 = HIGH;
    } else {
      ledState1 = HIGH;
       ledState2 = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(relay1, ledState1);
     digitalWrite(relay2, ledState2);
    for (int i=0; i<NUM_LEDS; i++ )
{
leds[i] = CRGB(255, 0, 255 );
FastLED.setBrightness(2*i);
FastLED.show();
delay (20);
} 
for (int i=NUM_LEDS; i> 0; i-- )
{
leds[i] = CRGB(255, 0, 255 );
FastLED.setBrightness(2*i);
FastLED.show();
delay (20);

}
  }
  }
  else if (count>=11){
    Serial.println(count);
   
    unsigned long currentMillis2 = millis();

  if (currentMillis2 - previousMillis2 >= interval2) {
    // save the last time you blinked the LED
    previousMillis2 = currentMillis2;

    // if the LED is off turn it on and vice-versa:
    if (ledState1 == HIGH) {
      ledState1 = LOW;
      ledState2 = HIGH;
    } else {
      ledState1 = HIGH;
       ledState2 = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(relay1, ledState1);
     digitalWrite(relay2, ledState2);
        for (int i=0; i<NUM_LEDS; i++ )
{
leds[i] = CRGB(0, 255-2*i, 20*i );
FastLED.setBrightness(6*i);
FastLED.show();

} 
for (int i=NUM_LEDS; i> 0; i-- )
{
leds[i] = CRGB(20*i, 0, 255-20*i );
FastLED.setBrightness(60-2*i);
FastLED.show();


}
  }
  }
  else {
   Serial.println(count);  
  }
}
