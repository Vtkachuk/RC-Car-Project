
int ledPin = 6;
int state = 0;

void setup() {
  //bluetooth
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  
  //motor
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  //bluetooth
  if(Serial.available() > 0){
    state = Serial.read();
  }

  if(state == '0'){
    digitalWrite(ledPin, LOW);
    Serial.println("LED: OFF");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, 0);
  }
  else if(state == '1'){
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, 100);
  }
  else if(state == '2'){
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, 100);
  }
  else if(state == '3'){
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(9, 150);
  }
   else if(state == '4'){
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(9, 150);
  }

  
//  //motor
//  digitalWrite(8, HIGH);
//  digitalWrite(7, LOW);
//  digitalWrite(13, HIGH);
//  digitalWrite(12, LOW);
//  analogWrite(9,200);
//  for (int i=0; i <=255; i++){
//    analogWrite(11,i);
//    delay(100);
//    
//  }
//  
//  
//  digitalWrite(8, LOW);
//  digitalWrite(7, HIGH);
//  digitalWrite(12, HIGH);
//  digitalWrite(13, LOW);
//  analogWrite(9, 200);
//  analogWrite(11,80);
//  delay(3000);
//  
}
