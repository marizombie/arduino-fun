#define SPEED 6
#define OUT1 7
#define OUT2 8
#define OUT3 9
#define OUT4 10

void setup() {
  // put your setup code here, to run once:
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 252; i++) {
    if (i < 63) {
      //forward
      engineRun(OUT1, OUT4, OUT2, OUT3);
    }
    if (i >= 63 && i < 126) {
      //backward
      engineRun(OUT2, OUT3, OUT1, OUT4);
    }
    if (i >= 126 && i < 189) {
      //right
      engineRun(OUT1, OUT2, OUT3, OUT4);
    }
    if (i >= 189) {
      //left
      engineRun(OUT3, OUT4, OUT1, OUT2);
    }
    analogWrite(SPEED, 300);
    delay(100);
  }
}

void engineRun(int high1, int high2, int low1, int low2) {
  digitalWrite(high1, HIGH);
  digitalWrite(high2, HIGH);
  digitalWrite(low1, LOW);
  digitalWrite(low2, LOW);
}
