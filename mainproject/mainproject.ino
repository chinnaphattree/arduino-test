int light = 2;
int trig = 4;
int echo = 5;
int buzzer = 12;


void alert(short n){
  digitalWrite(buzzer,HIGH);
  delay(n);
  digitalWrite(buzzer,LOW);
}

void alertnlight(short n){
  digitalWrite(2,HIGH);  
      digitalWrite(12,HIGH);
      delay(n);
      digitalWrite(2,LOW);  
      digitalWrite(12,LOW);
}

void shoot(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);  
}



//----------------function----------------//

void setup(){
  pinMode(light, OUTPUT); // led
  pinMode(trig,OUTPUT); //trig
  pinMode(echo,INPUT); //echo
  pinMode(buzzer,OUTPUT); //buzzer
  Serial.begin(9600);
  
}

//-- set --//
//-------------------------------------------------------------------------//
//-------code below-------//

void loop(){
  int rl = analogRead(A0);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  shoot();

//----receive----//
  int duration = pulseIn(echo, HIGH); 
  int distance = duration * 0.034 / 2; 

//---------display---------//
  Serial.println(rl);
  Serial.println(distance);
  Serial.println(" ");
//---------display---------//

  if(rl<=800){ //light
    if(distance<=30) alert(500);
  }else{
    if(distance<=30) alertnlight(500);
  }
  delay(500);
}