#define PIN_LED 7
int count = 0;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, 0);
  delay(1000);
  while (count <= 5 ) {
  digitalWrite(PIN_LED, 0);
  delay(100);
  digitalWrite(PIN_LED, 1);
  delay(100);
  count++;
  }
  digitalWrite(PIN_LED, 1);
}

void loop() {}
