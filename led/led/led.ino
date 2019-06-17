
#define TIME_LIMIT 10000
int cnt = 0;
int err = 0;
int err_sum = 0;
int last;
int val = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

  pinMode(8, OUTPUT);

  Serial.begin(9600);

  randomSeed(analogRead(0));
}

int new_random(int val, int a, int b) {
  int newval;
  while (val == (newval = random(a, b)));
  return newval;
}

void loop() {

  int sw1 = digitalRead(5);
  int sw2 = digitalRead(6);
  int sw3 = digitalRead(7);

  val = new_random(val, 2, 5);

  digitalWrite(val, HIGH);

  //  Serial.print("ran-");
  //  Serial.println(val);

  while (!(((val == 2) && (sw1 == 0)) || ((val == 3) && (sw2 == 0)) || ((val == 4) && (sw3 == 0)))) {
    if ( millis() > TIME_LIMIT) {
      break;
    }
    sw1 = digitalRead(5);
    sw2 = digitalRead(6);
    sw3 = digitalRead(7);
  }

  digitalWrite(val, LOW);


  cnt++;
  // Serial.print("Cnt-");
  // Serial.println(cnt);
  if ( millis() > TIME_LIMIT) {
    last = millis();
    Serial.print("Cnt-");
    Serial.print(cnt);
    Serial.print(" time-");
    Serial.print(last);

    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    delay(1000);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    while (1);
  }

}
