//write up storage as actual write up is on a IDE

#include <Servo.h>

Servo finger;
const int SERVO_PIN = 9;

void setup() {
  Serial.begin(9600);
  finger.attach(SERVO_PIN);
  finger.write(0);
  Serial.println("Ready. Type an angle 0-180.");
}

void loop() {
  if (Serial.available() > 0) {
    String line = Serial.readStringUntil('\n');
    line.trim();
    if (line.length() == 0) return;

    int angle = constrain(line.toInt(), 0, 180);
    finger.write(angle);

    Serial.print("Moved to ");
    Serial.println(angle);
  }
}

