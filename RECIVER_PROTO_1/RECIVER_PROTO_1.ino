

int in1 = 2;//motor1 REVERSE PIN
int in2 = 4;//motor2
int channel_1 = 0;  // pin with ~ symbol motor input
int channel_2 = 1; //motor inputint in3 = 2;
int enable1   = 3;// PWM OUTpin with ~ symbol  motor speed
int enable2   = 5;//motor speedint in4 = 4;


int in5 = A0;
int in6 = A1;
int in7 =A2;
int in8 =A3;
int in9 =A4;
int in10 =A5;
int out5 = 6;
int out6 = 7;
int out7 =8;
int out8 =9;
int out9 =10;
int out10 =11;




void setup() 
{
  {

  pinMode(channel_1, INPUT);
  pinMode(channel_2, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  
  Serial.begin(9600);
}
{//aux ports

  pinMode(in5, INPUT);
  pinMode(in6, INPUT);
  pinMode(in7, INPUT);
  pinMode(in8, INPUT);
  pinMode(in9, INPUT);
  pinMode(in10, INPUT);
  pinMode(out5, OUTPUT);  
  pinMode(out6, OUTPUT);
  pinMode(out7, OUTPUT);
  pinMode(out8, OUTPUT);
  pinMode(out9, OUTPUT);
  pinMode(out10, OUTPUT);
 
  Serial.begin(9600);
 }
}

void loop() {{
  
  int pwm = 0;
  int value = pulseIn(channel_1, HIGH, 25000);
  
  if(value==0)
  {
      digitalWrite(in1, LOW);

      analogWrite(enable1, 0);
  }
  
  else if(value > 1500)
  {
      pwm = map(value, 1500, 2010, 20, 255); 

      digitalWrite(in1, HIGH);
      analogWrite(enable1, pwm);
  }
  
  else if(value < 1480)
  {
      pwm = map(value, 1480, 990, 20, 255); 
      digitalWrite(in1, LOW);
      analogWrite(enable1, pwm);
  }
  
  else
  {
      digitalWrite(in1, LOW);
      analogWrite(enable1, 0);
  }
  
  delay(10);
}
{
  int pwm1 = 0;
  int value1 = pulseIn(channel_2, HIGH, 25000);
  
  if(value1==0)
  {
      
      digitalWrite(in2, LOW);
      analogWrite(enable2, 0);
  }
  
  else if(value1 > 1500)
  {
      pwm1 = map(value1, 1500, 2010, 20, 255); 
      digitalWrite(in2, HIGH);
      analogWrite(enable2, pwm1);
  }
  
  else if(value1 < 1480)
  {
      pwm1 = map(value1, 1480, 990, 20, 255); 

      digitalWrite(in2, LOW);
      analogWrite(enable2, pwm1);
  }
  
  else
  {

      digitalWrite(in2, LOW);
      analogWrite(enable2, 0);
  }
  
  delay(10);
  
  {
  int (out5, HIGH); 
  int value5 = pulseIn(in5, HIGH, 25000);
  
  
  if(value5 > 1500)
  {
       digitalWrite(out5, LOW);   
  }
   else
  {  
      digitalWrite(out5, HIGH);
  }
  

  delay(10);
}
 {
  int (out6, HIGH); 
  int value6 = pulseIn(in6, HIGH, 25000);
  
  
  if(value6 > 1500)
  {
       digitalWrite(out6, LOW);   
  }
   else
  {  
      digitalWrite(out6, HIGH);
  }
  

  delay(10);
}
 {
  int (out7, HIGH); 
  int value7 = pulseIn(in7, HIGH, 25000);
  
  
  if(value7 > 1500)
  {
       digitalWrite(out7, LOW);   
  }
   else
  {  
      digitalWrite(out7, HIGH);
  }
  

  delay(10);
}
 {
  
  int value8 = pulseIn(in8, HIGH, 25000);
  
  
  if(value8 < 1500)
  {
       digitalWrite(out8, LOW);   
  }
   else
  {  
      digitalWrite(out8, HIGH);
  }
  delay(10);
 }
   {
  int (out9, HIGH); 
  int value9 = pulseIn(in9, HIGH, 25000);
  
  
  if(value9 > 1500)
  {
       digitalWrite(out9, LOW);   
  }
   else
  {  
      digitalWrite(out8, HIGH);
  }
  

  delay(10);
}
 {
  int (out10, HIGH); 
  int value10 = pulseIn(in10, HIGH, 25000);
  
  
  if(value10 > 1500)
  {
       digitalWrite(out10, LOW);   
  }
   else
  {  
      digitalWrite(out10, HIGH);
  }
  

  delay(10);
}
  

  
}
}
