void setup() {
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP); // D3 as input with internal pull-up resistor
  Serial.begin(9600);       // Start serial communication at 9600 bps
}

void loop() {
  // Read the state of the micro switch
  int switchStateA = digitalRead(3);
  int switchStateB = digitalRead(5);

    // Check if the switch is pressed (LOW)
    if (switchStateA == LOW) {
      // Send 'upshift' string over serial if the switch is pressed
      Serial.write('upshift');
    }
    if (switchStateA == LOW) {
      // Send 'downshift' string over serial if the switch is pressed
      Serial.write('downshift');
    }
  // Optional: Add a short delay to debounce the switch
  delay(50);
}
