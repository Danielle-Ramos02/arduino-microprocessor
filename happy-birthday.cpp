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

// Notes for "Happy Birthday"
int melody[] = {
  264, 264, 297, 264, 352, 330, // "Happy birthday to you"
  264, 264, 297, 264, 396, 352, // "Happy birthday to you"
  264, 264, 528, 440, 352, 330, 297, // "Happy birthday dear [Name]"
  466, 466, 440, 352, 396, 352 // "Happy birthday to you"
};

// Duration of each note (ms)
int noteDurations[] = {
  300, 150, 600, 600, 600, 1200,
  300, 150, 600, 600, 600, 1200,
  300, 150, 600, 600, 600, 600, 1200,
  300, 150, 600, 600, 600, 1200
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
