#define PULLDOWN 2
#define PULLUP 3

void setup() {
  Serial.begin(9600);
  pinMode(PULLDOWN, INPUT);
  pinMode(PULLUP, INPUT_PULLUP);
}

void loop() {
  int PullupState = digitalRead(PULLUP);
  int PulldownState = digitalRead(PULLDOWN);

  Serial.print("Pullup: ");
  Serial.print(PullupState);
  Serial.print("\t");
  Serial.print("Pulldown: ");
  Serial.print(PulldownState);
  Serial.print("\n");
}
