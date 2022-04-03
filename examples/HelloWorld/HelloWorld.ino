#include <Arduino.h>
#include <Morse.h>

Morse morse(13);

void setup()
{
}

void loop()
{
  morse.space();
  morse.dot(); morse.dot(); morse.dot(); morse.dot(); morse.newLetter(); //H
  morse.dot(); morse.newLetter(); //E
  morse.dot(); morse.dash(); morse.dot(); morse.dot(); morse.newLetter(); //L

  morse.morseString("Lo");
  morse.space();
  morse.morseString("World");

  morse.space();
  morse.space();
}
