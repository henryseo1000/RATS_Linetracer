int green1 = 2;
int green2 = 3;
int green3 = 4;
int green4 = 5;
int value0;
int value1;
int value2;
int value3;

void setup() {
  
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

  if (value0 <= 40) {
    digitalWrite(green4,LOW);
    digitalWrite(green3,HIGH);
    digitalWrite(green2,HIGH);
    digitalWrite(green1,HIGH);
  }
  if (value1 <= 40) {
    digitalWrite(green4,HIGH);
    digitalWrite(green3,LOW);
    digitalWrite(green2,HIGH);
    digitalWrite(green1,HIGH);
  }
  if (value2 <= 40){
    digitalWrite(green4,HIGH);
    digitalWrite(green3,HIGH);
    digitalWrite(green2,LOW);
    digitalWrite(green1,HIGH);
  }
  if (value3 <= 40) {
    digitalWrite(green4,HIGH);
    digitalWrite(green3,HIGH);
    digitalWrite(green2,HIGH);
    digitalWrite(green1,LOW);
  }
  //else{
  //  digitalWrite(green1,HIGH);
  //  digitalWrite(green2,HIGH);
  //  digitalWrite(green3,HIGH);
  //  digitalWrite(green4,HIGH);
  //}

  
}
