int key_index = 0;
int COLUMN_PINS[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int ROW_PINS[8] = {13, 12, A5, A4, A3, A2, A1, A0};

void setup() {
  Serial.begin(9600);

  for (int row = 0; row < 8; row++)
    pinMode(ROW_PINS[row], INPUT_PULLUP);

  for (int col = 0; col < 8; col++)
    pinMode(COLUMN_PINS[col], INPUT_PULLUP);
}

void loop() {
  int row_pin;
  int key_state;
  for (int row = 0; row < 8; row++) {
    row_pin = ROW_PINS[row];
    pinMode(row_pin, OUTPUT);
    digitalWrite(row_pin, LOW);
    for (int col = 0; col < 8; col++) {
        key_index = col + (row * 8);
        key_state = digitalRead(COLUMN_PINS[col]);
        Serial.print("Key ");
        Serial.print(key_index);
        Serial.print(" Output: ");
        Serial.print(key_state);
        Serial.print("\n");
        delay(300);
      }
    }
    digitalWrite(row_pin, HIGH);
    delay(1);
    pinMode(row_pin, INPUT_PULLUP);
}
