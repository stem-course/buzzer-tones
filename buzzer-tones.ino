/*
  Code by: www.munphurid.com
  M.Hashir and Wardah Arshad

  This is a code that generate different tunes on buzzer at pin 11

  Hardware:
  -Arduino
  -buzzer

  Connections:
  -Connect +ve of buzzer to pin 11 of Arduino
  -Connect -ve of buzzer to GND of Arduino
*/

int buzzer = 11;                                               //Buzzer is connected to pin11

#include "pitches.h"

int melody[] = {                                                // notes in the melody:
  2000, 2000, 2000, 2000, 2000                                   //Enter notes or frequencies here
};

int noteDurations[] = {                                         // note durations: 4 = quarter note, 8 = eighth note, etc.:
  4, 8, 8, 4, 4, 4, 4, 4                                        //Enter duration of each note or frequency
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {           // iterate over the notes of the melody:

    // to calculate the note duration, take one second
    // divided by the note type.
    int noteDuration = 1000 / noteDurations[thisNote];          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    tone(buzzer, melody[thisNote], noteDuration);


    int pauseBetweenNotes = noteDuration * 1.30;                // to distinguish the notes, set a minimum time between them.
    delay(pauseBetweenNotes);                                   // the note's duration + 30% seems to work well:
    noTone(buzzer);                                             // stop the tone playing:
    delay(10);
  }
  // no need to repeat the melody.
}
