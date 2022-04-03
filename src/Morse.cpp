/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
  Update by Michael A. Pedersen (Cra7y) added ability to morse a string
  automatically
*/

#include "Morse.h"

#include "Arduino.h"

Morse::Morse(int pin, bool inverted, unsigned int dotDelay,
             unsigned int dashDelay, unsigned int spaceDelay,
             unsigned int morseDelay, unsigned int letterDelay) {
    pinMode(pin, OUTPUT);
    _pin = pin;
    _inverted = inverted;
    _dotDelay = dotDelay;
    _dashDelay = dashDelay;
    _spaceDelay = spaceDelay;
    _morseDelay = morseDelay;
    _letterDelay = letterDelay;
}

void Morse::dot() {
    setPin(HIGH);
    delay(_dotDelay);
    setPin(LOW);
    delay(_morseDelay);
}

void Morse::dash() {
    setPin(HIGH);
    delay(_dashDelay);
    setPin(LOW);
    delay(_morseDelay);
}

void Morse::space() { delay(_spaceDelay); }

void Morse::newLetter() { delay(_letterDelay); }

void Morse::setPin(bool state) {
    if (_inverted) {
        state = (!state);
    }
    digitalWrite(_pin, state);
}

void Morse::morseString(String word) {
    word.toLowerCase();
    for (int i = 0; i < word.length(); i++) {
        char curLetter = word.charAt(i);
        if (curLetter == ' ') {
            space();
        } else {
            int index = findLetterIndex(curLetter);
            if (index > 0) {
                morseArray(_morseLetters[index]);
            }
        }
    }
}

int Morse::findLetterIndex(char toFind) const {
    int i = 0;
    while (true) {
        if (_letters[i] == toFind) {
            return i;
        } else if (_letters[i] == '\0') {
            return -1;
        } else {
            i++;
        }
    }
}

void Morse::morseArray(const int (&letter)[5]) {
    for (int i = 0; i < 5; i++) {
        if (letter[i] == DOT) {
            dot();
        } else if (letter[i] == DASH) {
            dash();
        } else {
            newLetter();
            break;
        }
    }
}
