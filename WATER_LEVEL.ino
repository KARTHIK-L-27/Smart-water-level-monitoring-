int trigPin = 9;
int echoPin = 10;

int lowLED = 5;
int midLED = 6;
int highLED = 7;
int buzzer = 8;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(lowLED, OUTPUT);
  pinMode(midLED, OUTPUT);
  pinMode(highLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; // cm

  // Reset outputs
  digitalWrite(lowLED, LOW);
  digitalWrite(midLED, LOW);
  digitalWrite(highLED, LOW);
  digitalWrite(buzzer, LOW);

  if (distance > 20) {            // LOW level
    digitalWrite(lowLED, HIGH);
  } else if (distance > 10) {     // MEDIUM level
    digitalWrite(midLED, HIGH);
  } else {                        // FULL level
    digitalWrite(highLED, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  delay(1000);
}
