#define ECHOPIN 2
#define TRIGPIN 3

float distances[] = { 3, 5, 7, 9, 11 };
int num = sizeof(distances) / sizeof(float);

void setup() {
  // Serial.begin(9600);

  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);

  // 4, 6, 8, 10, 12
  for (int i = 4; i < 4 + num * 2; i += 2) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  float distance = pulseIn(ECHOPIN, HIGH);
  distance = distance * 0.017315f;
  // Serial.print(distance);
  // Serial.print("cm\n");

  // Turn on/off the leds
  for (int i = 0; i < num; i++) {
    if (distance < distances[i]) {
      digitalWrite(i * 2 + num - 1, HIGH);
    } else {
      digitalWrite(i * 2 + num - 1, LOW);
    }
  }

  delay(250);
}

