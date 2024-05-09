//int a = A4;
//int b =9;

int channel;
int in5 = A0;
int in6 = A1;
int in7 =A2;
int in8 =A3;
int in9 =A4;
int in10 =A5;
int out5 = 4;
int out6 = 5;
int out7 =6;
int out8 =7;
int out9 =8;
int out10 =9;
int channel5;
int channel6;
int channel7;
int channel8;
int channel9;
int channel10;

void setup() {
  //pinMode(a ,INPUT);
 // pinMode(b ,OUTPUT);
  pinMode(in5, INPUT);
  pinMode(in6, INPUT);
  pinMode(in7, INPUT);
  pinMode(in8, INPUT);
  pinMode(in9, INPUT);
  pinMode(in10, INPUT);

  pinMode(out5, INPUT_PULLUP);  
  pinMode(out6, INPUT_PULLUP);
  pinMode(out7, INPUT_PULLUP);
  pinMode(out8, INPUT_PULLUP);
  pinMode(out9, INPUT_PULLUP);
  pinMode(out10, INPUT_PULLUP);  
  pinMode(out5, OUTPUT);  
  pinMode(out6, OUTPUT);
  pinMode(out7, OUTPUT);
  pinMode(out8, OUTPUT);
  pinMode(out9, OUTPUT);
  pinMode(out10, OUTPUT);
    Serial.begin(9600);
  
  
}

void loop() {

  {
    channel5 = (pulseIn(in5 ,HIGH));
  
  if (channel5 > 1500)
  {
    digitalWrite(out5,HIGH);
  }
  if (channel5 < 1300)
  {
    digitalWrite(out5,LOW);       
  }}

  {
    channel6 = (pulseIn(in6 ,HIGH));
  
  if (channel6 > 1500)
  {
    digitalWrite(out6,HIGH);
  }
  if (channel6 < 1300)
  {
    digitalWrite(out6,LOW);       
  }}
  {
    channel7 = (pulseIn(in7 ,HIGH));
  
  if (channel7 > 1500)
  {
    digitalWrite(out7,HIGH);
  }
  if (channel7 < 1300)
  {
    digitalWrite(out7,LOW);       
  }}
  {
    channel8 = (pulseIn(in8 ,HIGH));
  
  if (channel8 > 1500)
  {
    digitalWrite(out8,HIGH);
  }
  if (channel8 < 1300)
  {
    digitalWrite(out8,LOW);       
  }}
  {
    channel9 = (pulseIn(in9 ,HIGH));
  
  if (channel9 > 1500)
  {
    digitalWrite(out9,HIGH);
  }
  if (channel9 < 1300)
  {
    digitalWrite(out9,LOW);       
  }}
  {
    channel10 = (pulseIn(in10 ,HIGH));
  
  if (channel10 > 1500)
  {
    digitalWrite(out10,HIGH);
  }
  if (channel10 < 1300)
  {
    digitalWrite(out10,LOW);       
  }}
  
 

}
