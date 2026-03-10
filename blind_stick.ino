// Blind Stick using Arduino Uno
// Ultrasonic Sensor + Buzzer

#define trigPin 9
#define echoPin 10
#define buzzer 6

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Receive echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance (cm)
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Buzzer logic
  if (distance <= 20 && distance > 0) {
    digitalWrite(buzzer, HIGH);   // Continuous beep (very close)
  }
  else if (distance <= 50) {
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);                   // Slow beep (medium distance)
  }
  else {
    digitalWrite(buzzer, LOW);    // No obstacle
  }

  delay(100);
}
