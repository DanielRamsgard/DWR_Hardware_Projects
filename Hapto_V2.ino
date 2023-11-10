int timeInMicro;
int distanceInCm;
int trig = 3;
int echo = 4;
void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
}
void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  timeInMicro = pulseIn(echo, HIGH);
  distanceInCm = ((timeInMicro/29)/2);
  switch (distanceInCm){
    case 0 ... 10:
    digitalWrite(1, HIGH);
    delay(1000);
    break;
    case 11 ... 40:
    analogWrite(0, 1023);
    delay(1000);
    break;
    case 41 ... 50:
    digitalWrite(0, 800);
    delay(1000);
    break;
    case 51 ... 70:
    digitalWrite(0, 500);
    delay(1000);
    break;
    default:
    break;
  }
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
}