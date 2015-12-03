#include <toneAC.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include "pitches.h"



// constants won't change. They're used here to
// set pin numbers:
// BLUE CABLE SOUNDS
//const int muiscPin = 9; 


//GREEN CABLE
const int sensorPin = A9;  

// YELLOW CABLE
const int lightPin = 6;
const int pixelCount = 1;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(pixelCount, lightPin, NEO_GRB + NEO_KHZ800);
bool pressed = false;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int sensorValue = 0; 

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


void setup() {
  // iterate over the notes of the melody:
    pinMode(sensorPin, INPUT);
    pixels.begin();


}
    int intensity = 1;

    //above this means it is at rest
    //int restValue = 100;

 
    //below this means it is stretched
    //int stretchValue = 80;
    float initSensorRead;
    float treshold;

  
    int counter = 0;
    int mapCounter;
    int thisNoteCounter = 1;
    int thisNote;

    bool first = true;
    int firstCounter = 0;


    int counterIncrement = 5000;
    int counterDecrement = 200;
    int counterStopTreshold = 10000;
    int counterMax = 15000;

    
void loop() {


    if(firstCounter < 10){
       initSensorRead = analogRead(sensorPin);
       treshold = initSensorRead - (initSensorRead / 5);
       firstCounter++;
    }
    sensorValue = analogRead(sensorPin);


  
    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH:
    //if (sensorValue < stretchValue && !pressed  && counter < 20000) {
    if (sensorValue < treshold && !pressed  && counter < counterMax) {
        counter = counter + counterIncrement;
        pressed = true;
    }
    //if (sensorValue > restValue && pressed){
    if (sensorValue > treshold && pressed){
      pressed = false;
    }

    mapCounter = counter;
    intensity = map(mapCounter, 0, counterStopTreshold, 10, 0);
    
    if (counter > counterStopTreshold){
      intensity = 0;
    }
    
    Serial.print("Autoset treshold value: ");
    Serial.print(treshold);
    Serial.print("\n");
    
    Serial.print("Sensor value: ");
    Serial.print(sensorValue);
    Serial.print("\n");
    
    Serial.print("Counter: ");
    Serial.print(counter);
    Serial.print("\n");
    
    Serial.print("Intensity: ");
    Serial.print(intensity);

    
    thisNote = thisNoteCounter % 8;
    Serial.print("\n");
    if(intensity){
        pixels.setPixelColor(0, pixels.Color(25 * intensity, 25 * intensity, 25 * intensity)); // Moderately bright green color.
        pixels.show();
       //toneAC( frequency [, volume [, length [, background ]]] ) - Play a note.
        unsigned long noteDuration = 1000 / noteDurations[thisNote];
        toneAC(melody[thisNote], intensity, noteDuration);
        int pauseBetweenNotes = noteDuration * 1.30;
        //delay(pauseBetweenNotes /10 );
        thisNoteCounter++;
          if( counter > counterDecrement){
              counter -= counterDecrement;
          }
       } else {
        delay(250);
        pixels.setPixelColor(0, pixels.Color(0,0,0)); // Moderately bright green color.
        pixels.show();
        if( counter > counterDecrement){
              counter -= counterDecrement * 2;
         }
       }
   }

