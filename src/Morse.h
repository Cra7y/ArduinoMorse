/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
  Update by Michael A. Pedersen (Cra7y) added ability to morse a string
  automatically
*/

#ifndef Morse_h
#define Morse_h

#define DOT 0
#define DASH 1
#define EMPTY 3

#include "Arduino.h"

class Morse {
   public:
    Morse(int pin, bool inverted = false, unsigned int dotDelay = 250,
          unsigned int dashDelay = 1000, unsigned int spaceDelay = 4000,
          unsigned int morseDelay = 1000, unsigned int letterDelay = 2000);
    void dot();
    void dash();
    void space();
    void newLetter();
    void morseString(String word);

   private:
    int _pin;
    bool _inverted;
    unsigned int _dotDelay;
    unsigned int _dashDelay;
    unsigned int _spaceDelay;
    unsigned int _morseDelay;
    unsigned int _letterDelay;
    void setPin(bool state);
    int findLetterIndex(char toFind) const;
    void morseArray(const int (&letter)[5]);
    const char _letters[37] = "abcdefghijklmnopqrstuvwxyz1234567890";
    const int _morseLetters[36][5] = {
        {DOT, DASH, EMPTY, EMPTY, EMPTY}, // a 
        {DASH, DOT, DOT, DOT, EMPTY}, // b
        {DASH, DOT, DASH, DOT, EMPTY}, // c 
        {DASH, DOT, DOT, EMPTY, EMPTY}, // d 
        {DOT, EMPTY, EMPTY, EMPTY, EMPTY}, // e 
        {DOT, DOT, DASH, DOT, EMPTY}, // f 
        {DASH, DASH, DOT, EMPTY, EMPTY}, // g 
        {DOT, DOT, DOT, DOT, EMPTY}, // h 
        {DOT, DOT, EMPTY, EMPTY, EMPTY}, // i 
        {DOT, DASH, DASH, DASH, EMPTY}, // j 
        {DASH, DOT, DASH, EMPTY, EMPTY}, // k 
        {DOT, DASH, DOT, DOT, EMPTY}, // l 
        {DASH, DASH, EMPTY, EMPTY, EMPTY}, // m 
        {DASH, DOT, EMPTY, EMPTY, EMPTY}, // n 
        {DASH, DASH, DASH, EMPTY, EMPTY}, // o 
        {DOT, DASH, DASH, DOT, EMPTY}, // p 
        {DASH, DASH, DOT, DASH, EMPTY}, // q 
        {DOT, DASH, DOT, EMPTY, EMPTY}, // r 
        {DOT, DOT, DOT, EMPTY, EMPTY}, // s 
        {DASH, EMPTY, EMPTY, EMPTY, EMPTY}, // t 
        {DOT, DOT, DASH, EMPTY, EMPTY}, // u 
        {DOT, DOT, DOT, DASH, EMPTY}, // v 
        {DOT, DASH, DASH, EMPTY, EMPTY}, // w 
        {DASH, DOT, DOT, DASH, EMPTY}, // x 
        {DASH, DOT, DASH, DASH, EMPTY}, // y 
        {DASH, DASH, DOT, DOT, EMPTY}, // z 
        {DOT, DASH, DASH, DASH, DASH}, // 1 
        {DOT, DOT, DASH, DASH, DASH}, // 2 
        {DOT, DOT, DOT, DASH, DASH}, // 3 
        {DOT, DOT, DOT, DOT, DASH}, // 4 
        {DOT, DOT, DOT, DOT, DOT}, // 5 
        { DASH, DOT, DOT, DOT, DOT }, // 6 
        { DASH, DASH, DOT, DOT, DOT }, // 7 
        {DASH, DASH, DASH, DOT, DOT }, // 8 
        {DASH, DASH, DASH, DASH, DOT}, // 9 
        { DASH, DASH, DASH, DASH, DASH} // 0 
        };
};

#endif
