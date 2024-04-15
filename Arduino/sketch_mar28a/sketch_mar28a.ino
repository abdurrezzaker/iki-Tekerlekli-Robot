#define pot A0
#define motorSolPin1 3
#define motorSolPin2 4
#define motorSagPin1 5
#define motorSagPin2 6
#define speedSolPin 9
#define speedSagPin 10
int speed = 0;
String komut = "";

void setup() {

  pinMode(motorSolPin1, OUTPUT);
  pinMode(motorSolPin2, OUTPUT);
  pinMode(motorSagPin1, OUTPUT);
  pinMode(motorSagPin2, OUTPUT);
  pinMode(speedSolPin, OUTPUT);
  pinMode(speedSagPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Komut giriniz");
}

void loop() {

  speed = analogRead(pot) / 4;
  analogWrite(speedSolPin, speed);
  analogWrite(speedSagPin, speed);

  if (Serial.available()) {

    char okunanKarakter = Serial.read();
    if (okunanKarakter != '-') {
      Serial.print(okunanKarakter);
      komut += okunanKarakter;
    } else {
      Serial.println();
      komutYurut();
    }
  }
}
void komutYurut() {

  if (komut.equals("ileri")) {
    digitalWrite(motorSolPin1, LOW);
    digitalWrite(motorSolPin2, HIGH);
    digitalWrite(motorSagPin1, LOW);
    digitalWrite(motorSagPin2, HIGH);
  } else if (komut.equals("geri")) {
    digitalWrite(motorSolPin1, HIGH);
    digitalWrite(motorSolPin2, LOW);
    digitalWrite(motorSagPin1, HIGH);
    digitalWrite(motorSagPin2, LOW);
  } else if (komut.equals("sag")) {
    digitalWrite(motorSolPin1, HIGH);
    digitalWrite(motorSolPin2, LOW);
    digitalWrite(motorSagPin1, LOW);
    digitalWrite(motorSagPin2, LOW);
  } else if (komut.equals("sol")) {
    digitalWrite(motorSolPin1, LOW);
    digitalWrite(motorSolPin2, LOW);
    digitalWrite(motorSagPin1, LOW);
    digitalWrite(motorSagPin2, HIGH);
  } else if (komut.equals("spin")) {
    digitalWrite(motorSolPin1, LOW);
    digitalWrite(motorSolPin2, HIGH);
    digitalWrite(motorSagPin1, HIGH);+
    digitalWrite(motorSagPin2, LOW);
  }
  komut = "";
}
