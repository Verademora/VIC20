int RevPinMap[8] = {0, 8, 2, 3, 4, 5, 6, 7};
int PinMap[8] = {7, 6, 5, 4, 3, 2, 8, 0};

void setup() {
  Serial.begin(9600);
  for (int pin = 0; pin < 8; pin++)
    pinMode(PinMap[pin], INPUT_PULLUP);
}

void loop() {
  int ThisPin;
  int PinState;

  for (int Row = 0; Row < 8; Row++) {
    ThisPin = PinMap[Row];
    PinState = digitalRead(ThisPin);

    Serial.print("Pin ");
    Serial.print(Row);
    Serial.print(": ");
    Serial.print(PinState);
    Serial.print("\n");
  }
  delay(1000);
}
