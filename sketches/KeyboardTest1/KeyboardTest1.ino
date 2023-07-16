COLUMN_PINS[8] = {0, 1, 2, 3, 4, 5, 6, 7};
ROW_PINS[8] = {13, 12, A5, A4, A3, A2, A1, A0};

void setup() {
  Serial.begin(9600);

  for (row = 0; row < 8; row++)
    pinMode(ROW_PINS[row], INPUT_PULLUP);

  for (col = 0; col < 8; col++)
    pinMode(COLUMN_PINS[col], INPUT_PULLUP);
}

void loop() {
}
