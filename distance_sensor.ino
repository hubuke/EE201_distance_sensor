// Booker Hu EE201
// https://wokwi.com/projects/345889030173360722

#define PIN_TRIG 5
#define PIN_LED 3
#define PIN_ECHO 6

void setup() {
  // put your setup code here, to run once:


  pinMode(PIN_LED, OUTPUT); // led digital output
  pinMode(PIN_ECHO, INPUT); // distance sensor output
  pinMode(PIN_TRIG, OUTPUT); //

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  // int pot = analogRead(A3);

  // Start a new measurement:
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  int distance = pulseIn(PIN_ECHO, HIGH) / 58; // distance in centimeter

  // float freq = 5.0 * pot / 1024.0;
  float freq = 5 - 5.0 * (distance - 3) / 400;
  int duration = 0;
  if (freq > 0) {
    duration = 1.0 / freq * 1000 / 2;
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
  if (duration > 3000) {
    duration = 3000;
  }
  delay(duration);
  Serial.print("current freq is ");
  Serial.println(freq);
  digitalWrite(PIN_LED, LOW);
  delay(duration);
}
