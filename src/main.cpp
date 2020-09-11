#include <Arduino.h>

const int redPin = 2;
const int greenPin = 3;
const int bluePin = 4;
const int buttonPin = 5;

int cycle = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(buttonPin, INPUT);
}

void color(int red_light_value, int green_light_value, int blue_light_value) {
  analogWrite(redPin, red_light_value);
  analogWrite(greenPin, green_light_value);
  analogWrite(bluePin, blue_light_value);
}

void loop() {
  delay(500);

  if (digitalRead(buttonPin) == HIGH) {
    if (cycle == 3) {
      cycle = 0;
    } else {
      cycle = cycle+1;
    }
  }

  if (cycle == 0) {
    color(0, 0, 0); // Off
  }

  if (cycle == 1) {
    color(255, 0, 0); // Red
  }

  if (cycle == 2) {
    color(0, 255, 0); // Green
  }

  if (cycle == 3) {
    color(0, 0, 255); // Blue
  }
}
