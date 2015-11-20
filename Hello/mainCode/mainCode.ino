/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


// constants won't change. They're used here to
// set pin numbers:
const int sensorPin = A9;     // the number of the pushbutton pin
const int pixelPin = 12;
bool pressed = false;

// variables will change:
int sensorValue = 0;         // variable for reading the pushbutton status
int counter = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, pixelPin, NEO_GRB + NEO_KHZ800);


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

void loop() {
  
      // read the state of the pushbutton value:
    sensorValue = analogRead(sensorPin);

    

    pixels.show(); // This sends the updated pixel color to the hardware.

    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH:
    if (sensorValue < 300 && !pressed ) {
        counter = counter + 1200;
        pressed = true;
    }
    if (sensorValue > 350 && pressed){
      pressed = false;
    }

    if( counter > 3000){
        pixels.setPixelColor(0, pixels.Color(0,250,0)); // Moderately bright green color.
        pixels.show();
         for (int thisNote = 0; thisNote < 8; thisNote++) {
  
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(6, melody[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(6);
      counter = 100;
       }
   }
   if (counter > 0){
         pixels.setPixelColor(0, pixels.Color(0,0,0)); // Moderately bright green color.
         pixels.show();
         counter--;
   }
   
   Serial.print(sensorValue);
   Serial.print("\n");

}
