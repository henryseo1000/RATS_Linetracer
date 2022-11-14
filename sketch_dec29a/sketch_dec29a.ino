int value0;
int value1;
int value2;
int value3;                                                 

void setup() {
  Serial.begin(9600);
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
}
