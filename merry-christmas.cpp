// LED pins
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;

// LED array
int leds[] = {led1, led2, led3, led4, led5, led6};
int numLeds = 6;

// Piezo buzzer pin
int buzzer = 7;

// Notes for "We Wish You a Merry Christmas" (partial melody)
int melody[] = {
  392, 392, 440, 392, 523, 494, // "We wish you a merry Christmas"
  392, 392, 440, 392, 587, 523, // "We wish you a merry Christmas"
  392, 392, 784, 659, 523, 494, 440, // "We wish you a merry Christmas"
  698, 698, 659, 523, 587, 523  // "And a Happy New Year!"
};

// Duration of each note (ms)
int noteDurations[] = {
  300, 300, 600, 600, 600, 600,
  300, 300, 600, 600, 600, 600,
  300, 300, 300, 300, 300, 300, 600,
  300, 300, 300, 300, 600, 600
};

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);
}

void loop() {
  for (int i = 0; i < sizeof(melody)/sizeof(melody[0]); i++) {
    int ledIndex = i % numLeds; // cycle through LEDs

    // Turn on LED
    digitalWrite(leds[ledIndex], HIGH);

    // Play the note
    tone(buzzer, melody[i], noteDurations[i]);

    // Wait for the note to finish
    delay(noteDurations[i]);

    // Turn off LED
    digitalWrite(leds[ledIndex], LOW);

    // Short pause between notes
    delay(50);
  }

  // Small pause before repeating the song
  delay(1000);
}
