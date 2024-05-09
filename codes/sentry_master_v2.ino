

int in1 = 2;
int in2 = 3;
int enable1 = 5;// pin with ~ symbol
int enable2 = 6;

int channel_1 = 9;  // pin with ~ symbol
int channel_2 = 10; 
void setup() 
{
  pinMode(channel_1, INPUT);
  pinMode(channel_2, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  
  Serial.begin(9600);
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
}
}
