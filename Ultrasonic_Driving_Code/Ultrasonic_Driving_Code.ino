/*

*/ 
  int phase_a = 2;
  int level_a = 3;
  int phase_b = 4;
  int level_b = 5;
  
  int set_mode = 7;
  
  int ultraOutR = 9;
  int ultraInR = 10;
  
  int ultraOutF = 11;
  int ultraInF = 12;
  
  long durationR, distCMR;
  long durationF, disCMF;
  
void setup() 
{
  //Motor A Setup
  pinMode(phase_a, OUTPUT);
  pinMode(level_a, OUTPUT);
  
  //Motor B Setup
  pinMode(phase_b, OUTPUT);
  pinMode(level_b, OUTPUT);
  
  //Mode
  pinMode(set_mode, OUTPUT);
  
  //Right Ultrasonic Setup
  pinMode(ultraOutR, OUTPUT);
  pinMode(ultraInR, INPUT);
  
  //Front Ultrasonic Setup
  pinMode(ultraOutF, OUTPUT);
  pinMode(ultraInF, INPUT);
}

void loop() {
  
  //send pulse right
  digitalWrite(ultraOutR, LOW);
  delayMicroseconds(5);
  digitalWrite(ultraOutR, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraOutR, LOW);
 
  //get duration right
  pinMode(ultraInR, INPUT);
  durationR = pulseIn(ultraInR, HIGH);
  
  //convert to cm right
  distCMR = (durationR / 2) / 29.1;
  
  //send pulse forward
  digitalWrite(ultraOutF, LOW);
  delayMicroseconds(5);
  digitalWrite(ultraOutF, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraOutF, LOW);
 
  //get duration forward
  pinMode(ultraInF, INPUT);
  durationF = pulseIn(ultraInF, HIGH);
  
  //convert to cm forward
  distCMF = (durationF / 2) / 29.1;
  
  if(distCMR < 8 && distCMF > 8)
  {
  //Motor A Forward
  digitalWrite(phase_a, HIGH);
  analogWrite(level_a, 100);
  
  //Motor B Forward
  digitalWrite(phase_b, HIGH);
  analogWrite(level_b, 89);
  }
  else if(distCMR > 8 && distCMF > 8)
  {
  delay(1000);
  //Motor A Turn Right
  digitalWrite(phase_a, LOW);
  analogWrite(level_a, 100);
  
  //Motor B Turn Right
  digitalWrite(phase_b, HIGH);
  analogWrite(level_b, 100);
  
  delay(430);
  }
  
  else if(distCMR < 8 && distCMF < 8)
  {
  //Motor A Turn Left
  digitalWrite(phase_a, HIGH);
  analogWrite(level_a, 100);
  
  //Motor B Turn left
  digitalWrite(phase_b, LOW);
  analogWrite(level_b, 100);
  
  delay(430);
  }
}
