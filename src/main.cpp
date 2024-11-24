#include <Arduino.h>

const int segPins[] = {3, 5, 6, 9, 10, 11, 12};
const int buttonPins[] = {A0, A1, A2, A3, A4, A5, 8};

const int digitPatterns[8][7] = {
     {0, 1, 1, 0, 0, 0, 0}, // 1
    {0, 0, 1, 0, 1, 0, 1}, // n
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {0, 0, 0, 0, 0, 0, 1}, // -
};

void displayGear(int number)
{
  const int *pattern = digitPatterns[number];
  if (number == 0)
  {
    for (int i = 0; i < 7; i++)
    {
      digitalWrite(segPins[i], pattern[i]);
    }
  }else if (number == 1)
  {
    for (int i = 0; i < 7; i++)
    {
      digitalWrite(segPins[i], pattern[i]);
    }
  }else if (number == 2)
  {
    for (int i = 0; i < 7; i++)
    {
      digitalWrite(segPins[i], pattern[i]);
    }
  }else if (number == 3)
  {
    for (int i = 0; i < 7; i++)
    {
      digitalWrite(segPins[i], pattern[i]);
    }
  }else if (number == 4)
  {
    for (int i = 0; i < 7; i++)
    {
      digitalWrite(segPins[i], pattern[i]);
    }
  }
  else if (number == 5)
  {
    for (int i = 0; i < 7; i++)
    {
      digitalWrite(segPins[i], pattern[i]);
    }
  }
  else if (number == 6)
  {
    for (int i = 0; i < 7; i++)
    {
      digitalWrite(segPins[i], pattern[i]);
    }
  }else if(number == 8){
    for (int i = 0; i < 7; i++)
    {
      digitalWrite(segPins[6], pattern[i]);
    }
  }
}

void clearDisplay()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], LOW);
  }
}

void setup()
{
  for (int i = 0; i < 7; i++)
  {
    pinMode(segPins[i], OUTPUT);
  }

  for (int i = 0; i < 7; i++)
  {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  Serial.begin(9600);
}

void loop()
{
  clearDisplay();
  for (int i = 0; i < 7; i++)
  {
    int buttonState = digitalRead(buttonPins[i]);

    if (buttonState == LOW)
    {
      displayGear(i);
      delay(200);
      break;
    }else{
      displayGear(8);
    }
  }
}
