#define led1 8
#define led2 9
#define sw1 2
#define sw2 3

void setup() {
   pinMode(sw1, INPUT);           // set pin to input
   pinMode(sw2, INPUT);           // set pin to input
   pinMode(led1, OUTPUT);           // set pin to input
   pinMode(led2, OUTPUT);           // set pin to input
   digitalWrite(led1, LOW);       // turn on pullup resistors
   digitalWrite(led2, LOW);       // turn on pullup resistors
   
}

void loop() {
  if ( digitalRead(sw1) == LOW) {
     digitalWrite(led1, HIGH);       // turn on pullup resistors
  }
  else {
     digitalWrite(led1, LOW);       // turn on pullup resistors
  }
  if ( digitalRead(sw2) == HIGH) {
     digitalWrite(led2, HIGH);       // turn on pullup resistors
  }
  else {
     digitalWrite(led2, LOW);       // turn on pullup resistors
  }   
}
