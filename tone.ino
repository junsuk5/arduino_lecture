int melody[] = {
  62, 49
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4
};

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  
}

void serialEvent() {
  delay(5000);
  playSound();
  String name = Serial.readString();
  Serial.println("[" + name + "]님 자리를 안내해 드리겠습니다");
}

void playSound() {
  for (int thisNote = 0; thisNote < 2; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
