/*
  Λειτουργία Φαναριών σε διάβαση πεζών
*/

int Button = 0;

int counter;

void setup()
{
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  // Πράσινη Ζώνη
  digitalWrite(6, HIGH);
  digitalWrite(11, HIGH);
  delay(5000); // Wait for 5000 millisecond(s)
  digitalWrite(11, LOW);
  // Πορτοκαλί Ζώνη
  digitalWrite(12, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(12, LOW);
  // Κόκκινη Ζώνη
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(6, LOW);
  // Διάβαση Πεζών
  digitalWrite(7, HIGH);
  for (counter = 0; counter < 10; ++counter) {
    tone(2, 1245, 100); // play tone 75 (D#6 = 1245 Hz)
    delay(300); // Wait for 300 millisecond(s)
    noTone(2);
  }
  digitalWrite(7, LOW);
  // Τέλος Διάβασης Πεζών
  digitalWrite(6, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
}