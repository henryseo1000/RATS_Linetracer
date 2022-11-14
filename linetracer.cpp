#define SENSOR_0 A0
#define SENSOR_1 A1
#define SENSOR_2 A2
#define SENSOR_3 A3
#define SENSOR_4 A4


#define state = 0
#define ENA  10
#define ENB  11
#define IN1  7
#define IN2  8
#define IN3  9
#define IN4  12

#define Kp 20
#define MOTOR_OFFSET_A 100
#define MOTOR_OFFSET_B 70


void read_sensor();
void monitoring_sensor();
void on_led_white();
void on_led_black();
void pControl(int current_line);
int current_line_white();
int sensor_value[5];
int standard_whitebackground[5] = {465, 552, 360, 295, 306};


void setup() {
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

}

void loop(){
    read_sensor();
    monitoring_sensor();
    on_led_white();
    int current_line = current_line_white();
    
    pControl(current_line);
}


void read_sensor() {
  sensor_value[0] = analogRead(SENSOR_0);
  sensor_value[1] = analogRead(SENSOR_1);
  sensor_value[2] = analogRead(SENSOR_2);
  sensor_value[3] = analogRead(SENSOR_3);
  sensor_value[4] = analogRead(SENSOR_4);

}

void monitoring_sensor(){
  Serial.print(sensor_value[0]);
  Serial.print(" ");
  Serial.print(sensor_value[1]);
  Serial.print(" ");
  Serial.print(sensor_value[2]);
  Serial.print(" ");
  Serial.print(sensor_value[3]);
  Serial.print(" ");
  Serial.print(sensor_value[4]);
  Serial.println(" ");
 
  
}

void on_led_white(){
  if( sensor_value[0] > standard_whitebackground[0] )
    digitalWrite(2, LOW);
  else 
    digitalWrite(2, HIGH);
  if( sensor_value[1] > standard_whitebackground[1] )
    digitalWrite(3, LOW);
  else 
    digitalWrite(3, HIGH);
  if( sensor_value[2] > standard_whitebackground[2] )
    digitalWrite(4, LOW);
  else 
    digitalWrite(4, HIGH);
  if( sensor_value[3] > standard_whitebackground[3] )
    digitalWrite(5, LOW);
  else 
    digitalWrite(5, HIGH);
  if( sensor_value[4] > standard_whitebackground[4] )
    digitalWrite(6, LOW);
  else 
    digitalWrite(6, HIGH);
}



void pControl(int current_line){
  int TGT_LINE,error; 
  error = TGT_LINE - current_line;
  int control_value = Kp * error;

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, MOTOR_OFFSET_A - control_value);
  analogWrite(ENB, MOTOR_OFFSET_B + control_value);
}

int current_line_white(){
  if( sensor_value[0] > standard_whitebackground[0])
    return 1;
  
  else if( sensor_value[1] > standard_whitebackground[1])
    return 2;

  else if( sensor_value[2] > standard_whitebackground[2] )
    return 3;
  
  else if( sensor_value[3] > standard_whitebackground[3] )
    return 4;
  
  else if( sensor_value[4] > standard_whitebackground[4] )
   return 5;
  
  }