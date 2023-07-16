/*
SerialTest

Read digital input on pin 2 and print result to Serial Monitor
*/

int pushButton = 2;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pushButton, INPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  for (int i = 0; i < 100; i++) {
    buttonState = digitalRead(pushButton);
    Serial.println(buttonState);
    delay(10);
  }
  digitalWrite(LED_BUILTIN, LOW);
  for (int i = 0; i < 100; i++) {
    buttonState = digitalRead(pushButton);
    Serial.println(buttonState);
    delay(10);
  }
}
