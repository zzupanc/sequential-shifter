void setup() {
  pinMode(3, INPUT_PULLUP); // D3 as input with internal pull-up resistor
  pinMode(4, INPUT_PULLUP); // D4 as input with internal pull-up resistor
  Serial.begin(9600);       // Start serial communication at 9600 bps
}



void loop() {
  // Read the state of the micro switches
  int switchStateA = digitalRead(3);
  int switchStateB = digitalRead(4);

  // Check if switch A is pressed (LOW)
  if (switchStateA == LOW) {
    // Send 'upshift' string over serial if the switch is pressed
    Serial.println("upshift");
    delay(500);
  }

  // Check if switch B is pressed (LOW)
  if (switchStateB == LOW) {
    // Send 'downshift' string over serial if the switch is pressed
    Serial.println("downshift");
    delay(500);
  }

  // Optional: Add a short delay to debounce the switches
  delay(50);
}
