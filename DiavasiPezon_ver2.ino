/*
  ΔΙΑΒΑΣΗ ΠΕΖΩΝ
*/

int Button = 0;

int counter;

void setup()
{
  pinMode(4, INPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  // θέσεις 11 Πράσινο, 12 Πορτοκαλί, 13 Κόκκινο
  // Αυτοκινήτων
  // θέσεις 7 Πράσινο, 8 Κόκκινο Πεζών

  // Μεταβλητή Button για το κουμπί
  // Διαβάζει αν πατήθηκε το κουμπί στη θέση 4
  Button = digitalRead(4);
  // Έλεγχος αν πατήθηκε το κουμπί
  // Button = 0 σημαίνει ότι δεν πατήθηκε το κουμπί
  if (Button == 0) {
    // Πράσινη Ζώνη Αυτοκινήτων
    digitalWrite(6, HIGH);
    digitalWrite(11, HIGH);
  } else {
    delay(2000); // Wait for 2000 millisecond(s)
    // Πορτοκαλί Ζώνη Αυτοκινήτων
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    delay(3000); // Wait for 3000 millisecond(s)
    // Κόκκινη Ζώνη Αυτοκινήτων
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    // Διάβαση Πεζών
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    // Ενεργοποιεί το ηχείο 20 φορές με διακοπή
    for (counter = 0; counter < 20; ++counter) {
      tone(2, 698, 100); // play tone 65 (F5 = 698 Hz)
      delay(300); // Wait for 300 millisecond(s)
    }
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    // Τέλος Διάβασης πεζών
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(13, LOW);
  }
}
