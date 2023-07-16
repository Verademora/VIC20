![[Teclado-C-64.png]]

## Rows and Columns

Matrix keyboards layout all inputs in a series of rows and columns. The reference image is accurate to the keyboard I'm working with. I tested each key by manually passing power through the column and watching the rows with LEDs. For example, pin 20 \[Column A\] in the diagram above would be connected to 5v power, pin 7 \[Row 5] would be connected to an LED run through a resistor to ground. The LED would be unpowered until the COMMODORE key was pressed. I used an array of LEDs connected to the rows and manually powered the column one at a time while testing.

From reading, it would seem that most matrix keyboards are polled such that the inputs and outputs are high when no keys are pressed. To accomplish this we'll use the Arduino to pull up the input pins. I uploaded this sketch to an Arduino for testing:

Filename: PullupSerialTest.ino
```cpp
#define PULLUP 3

void setup() {
  Serial.begin(9600);
  pinMode(PULLUP, INPUT);
}

void loop() {
  int PullupState = digitalRead(PULLUP);

  Serial.print("Pullup: ");
  Serial.print(PullupState);
}
```

On our keyboard SIP connector I connected pin 5 (Row 7) to a pull-up resistor connected to 5V power. I connected pin 17 (Column D) to ground. Inline with the pull-up resistor I connected a cable to pin 3 on our Arduino to monitor. When connected and powered, the Serial monitor shows the output is high. If I press the correct key (in our case the 8 key), the output goes low. It's a little iffy but my setup isn't great and the keyboard definitely needs cleaned.

Connecting each pin to a pull-up to keep our outputs high would be a little cumbersome. Thankfully we can have the Arduino act as a pull up.

Filename: PullupSerialTest.ino
```cpp
///...
void setup() {
  Serial.begin(9600);
  pinMode(PULLUP, INPUT_PULLUP);
}
///...
```

When I change the pinMode to INPUT_PULLUP, the Arduino takes the role of the pull-up resistor and I can remove the one from my test board. Once this sketch is uploaded, not only does it work as it should with the correct key bringing the output low, but it also polled more reliably.