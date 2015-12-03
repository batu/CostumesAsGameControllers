#include <toneAC.h>
#include "pitches.h"
void setup() {
  // put your setup code here, to run once:

}
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
unsigned long noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


void loop() {

       for (int thisNote = 0; thisNote < 8; thisNote++) {
          // toneAC( frequency [, volume [, length [, background ]]] ) - Play a note.
          unsigned long noteDuration = 1000 / noteDurations[thisNote];
          toneAC(melody[thisNote],10, noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
       }
}
