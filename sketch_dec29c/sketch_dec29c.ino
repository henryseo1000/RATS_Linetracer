int green1 = 2;
int green2 = 3;
int green3 = 4;
int green4 = 5;
int value0;
int value1;
int value2;
int value3;
int ENPin1 = 10; 
int IN1Pin2 = 8; 
int IN2Pin2 = 7; 
int ENPin2 = 9; 
int IN1Pin1 = 12; 
int IN2Pin1 = 11; 

void setup() { 
  pinMode(IN1Pin1, OUTPUT); 
  pinMode(IN2Pin1, OUTPUT); 
  pinMode(IN1Pin2, OUTPUT); 
  pinMode(IN2Pin2, OUTPUT); 
  Serial.begin(9600);
  pinMode(green1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(green3, OUTPUT);
  pinMode(green4, OUTPUT);
  pinMode(A0, INPUT);                        
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

}

void go() {
  analogWrite(ENPin1, 100); //최대 속도 
  analogWrite(ENPin2, 100); //최대 속도
  digitalWrite(IN1Pin1, HIGH); 
  digitalWrite(IN2Pin1, LOW); 
  digitalWrite(IN1Pin2, HIGH); 
  digitalWrite(IN2Pin2, LOW); 
}

void left() {
  analogWrite(ENPin1, 100); //최대 속도 
  analogWrite(ENPin2, 0); //최대 속도
  digitalWrite(IN1Pin1, HIGH); 
  digitalWrite(IN2Pin1, LOW); 
  digitalWrite(IN1Pin2, HIGH); 
  digitalWrite(IN2Pin2, LOW); 
}

void right() {
  analogWrite(ENPin1, 0); //최대 속도 
  analogWrite(ENPin2, 100); //최대 속도
  digitalWrite(IN1Pin1, HIGH); 
  digitalWrite(IN2Pin1, LOW); 
  digitalWrite(IN1Pin2, HIGH); 
  digitalWrite(IN2Pin2, LOW); 
}

void back() {
  analogWrite(ENPin1, 200); //최대 속도 
  analogWrite(ENPin2, 200); //최대 속도
  digitalWrite(IN1Pin1, LOW); 
  digitalWrite(IN2Pin1, HIGH); 
  digitalWrite(IN1Pin2, LOW); 
  digitalWrite(IN2Pin2, HIGH); 
}

void brake() {
  analogWrite(ENPin1, 200); //최대 속도 
  analogWrite(ENPin2, 200); //최대 속도
  digitalWrite(IN1Pin1, HIGH); 
  digitalWrite(IN2Pin1, HIGH); 
  digitalWrite(IN1Pin2, HIGH); 
  digitalWrite(IN2Pin2, HIGH);
}

void loop() { 
  value0 = analogRead(A0);
  value1 = analogRead(A1);
  value2 = analogRead(A2);      
  value3 = analogRead(A3);

  Serial.print(value0);
  Serial.print(" "); Serial.print(value1);
  Serial.print(" "); Serial.print(value2);
  Serial.print(" "); Serial.println(value3);
  delay(100);

  if (value3 <= 65) {
    digitalWrite(green1,LOW);
  }
  else {
    digitalWrite(green1,HIGH);
  }
  if (value2 <= 65) {
    digitalWrite(green2,LOW);
  }
  else {
    digitalWrite(green2,HIGH);
  }
  if (value1 <= 65){
    digitalWrite(green3,LOW);
  }
  else {
    digitalWrite(green3,HIGH);
  }
  if (value0 <= 65) {
    digitalWrite(green4,LOW);
  }
  else {
    digitalWrite(green4,HIGH);
  }

  if (value1 <=65 or value2 <=65) {
    go();
  }
  if (value0 <= 65) {
    left();
  }
  if (value3 <= 65){
    right();
  }
}
