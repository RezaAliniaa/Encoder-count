#define ENCODER_A 2
#define ENCODER_B 3
volatile long int encoder_count = 0;
void setup() {
  Serial.begin(115200); // Serial for Debugging
  pinMode(ENCODER_A, INPUT_PULLUP); // ENCODER_A as Input
  pinMode(ENCODER_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), encoder, RISING);
}

void loop() {
  Serial.println(encoder_count);

}

void encoder() {
  if (digitalRead(ENCODER_B) == HIGH) // if ENCODER_B is high increase the count
    encoder_count++; // increment the count
  else // else decrease the count
    encoder_count--;  // decrement the count
}
