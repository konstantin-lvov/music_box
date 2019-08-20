int speakerPin = 3;
int var_resistor = A1;
int btn_1_pin = 2;
int btn_2_pin = 4;

int current_b = 0;
bool btn_1 = false;
bool btn_2 = false;

int change_tone = 0;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(btn_1_pin, INPUT);
  pinMode(btn_2_pin, INPUT);

  digitalWrite(btn_1_pin, HIGH);
  digitalWrite(btn_2_pin, HIGH);

  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);

  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

}

void loop() {

  for (int i = 6; i <= 12; i++) {

    if (digitalRead(i) == HIGH) {
      change_tone = analogRead(var_resistor);
      btn_1 = digitalRead(btn_1_pin);
      btn_2 = digitalRead(btn_2_pin);
      current_b = i;
      playNote(i);
    }

  }
}


void playTone(int tone) {

  if (btn_1 == HIGH && btn_2 == HIGH) {

    while (digitalRead(current_b)) {
      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(tone);
      digitalWrite(speakerPin, LOW);
      delayMicroseconds(tone);
    }

  }
  if (btn_1 == LOW && btn_2 == HIGH) {

    for (long i = 0; i < 300000; i = i + tone * 2) {
      
      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(tone);
      digitalWrite(speakerPin, LOW);
      delayMicroseconds(tone);
    }

  }
  if (btn_1 == HIGH && btn_2 == LOW) {
    
    for (long i = 0; i < 200000; i = i + tone * 2) {
      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(tone);
      digitalWrite(speakerPin, LOW);
      delayMicroseconds(tone);
    }
    
  }
  
  if (btn_1 == LOW && btn_2 == LOW) {
    
    for (long i = 0; i < 100000; i = i + tone * 2) {
      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(tone);
      digitalWrite(speakerPin, LOW);
      delayMicroseconds(tone);
    }
    
  }

}

void playNote(int note) {
  
  int names[] = { 12, 11, 10, 9, 8, 7, 6 };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014 };//for digital

  // проиграть тон, соответствующий ноте
  for (int i = 0; i < 7; i++) {
    if (names[i] == note) {
      if (change_tone > 500) {
        playTone(tones[i] + change_tone * 2);
      } else {
        playTone(tones[i] - (500 - change_tone) * 2);
      }

    }
  }
}
