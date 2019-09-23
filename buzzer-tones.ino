/*
  Code by:
  M.Hashir and Wardah Arshad

  This is a code that generates different tunes using buzzer at pin 11

To do:
Also download pitches.h from this repository and put it in the same folder with this code.

  Hardware:
  -Arduino
  -buzzer

  Connections:
  -Connect longer leg of buzzer to pin 11 of Arduino
  -Connect shorter leg of buzzer to GND of Arduino
*/

int buzzer = 11;                                               //Buzzer is connected to pin 11

#include "pitches.h"

int melody[] = {                                               
  2000, 3000, 2000, 4000, 2000, 3000, 4000, 2000                //These are frequencies of sound in Hertz which will be played
};

int noteDurations[] = {                                         // note durations: 4 = quarter note, 8 = eighth note, etc.:
  4, 8, 8, 4, 4, 4, 4, 4                                        //This is duration corresponding to each frequency for which buzzer sounds. Note: 8 is shorter than 1
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {           //Do not edit
    
    int noteDuration = 1000 / noteDurations[thisNote];          
    tone(buzzer, melody[thisNote], noteDuration);               //Plays one note for a small duration

    int pauseBetweenNotes = noteDuration * 1.30;                // Do not edit
    delay(pauseBetweenNotes);                                   // Do not edit
    noTone(buzzer);                                             // stop the tone playing:
    delay(10);                                                  //Wait
  }
delay(1000);    //Wait for 1s before tune is played again
}
