
void setup() {
  Serial.begin(9600);
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(12, INPUT_PULLUP);
  off();
  displayNum(0);
}

void off() {
  for (int i = 2; i <= 9; i++) {
    digitalWrite(i, HIGH);
  }
}

void on(int startNum, int endNum, int skip = 10, int skip2 = 10) {
  for (int i = startNum; i <= endNum; i++) {
    if (i != skip && i != skip2) {
      digitalWrite(i, LOW);
    }
  }
}

void displayNum(int num) {
  switch (num) {
    case 0:
      on(3, 8);
      break;
    case 1:
      on(5, 6);
      break;
    case 2:
      on(3, 9, 5, 8);
      break;
    case 3:
      on(4, 9, 8);
      break;
    case 4:
      on(5, 9, 7);
      break;
    case 5:
      on(4, 9, 6);
      break;
    case 6:
      on(3, 9, 6);
      break;
    case 7:
      on(5, 7);
      break;
    case 8:
      on(3, 9);
      break;
    case 9:
      on(4, 9);
      break;
    default:
      break;
  }
}

int num = 0;
bool wasPressed = false;
void loop() {

  bool pressed = digitalRead(12);
  if (pressed && !wasPressed) {
    num++;
    delay(5);
    wasPressed = true;
    off();
  }
  else if (!pressed && wasPressed) {
    off();
    displayNum(num);
    delay(5);
    wasPressed = false;
  }
  if (num >  9) {
    num = 0;
  }
}
