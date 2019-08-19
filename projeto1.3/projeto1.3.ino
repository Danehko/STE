#define led 13
#define B 39500000
#define r10k 10000
#define vin 10230000
#define rinf 176

//unsigned long time_i;
//unsigned long time_f;
//unsigned long time_t;

unsigned long rntc = 0;
unsigned long vout_d = 0;
unsigned int tempk = 0;
unsigned int lnr = 0;
byte tempc = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); // set pin to input
}

void loop() {
  //time_i = micros();
  
  digitalWrite(led, HIGH); // turn on pullup resistors
  vout_d = analogRead(A1);
  rntc = r10k*((vin/vout_d)-10000);
  lnr = log(rntc/rinf)*100;
  tempk = B/(lnr);
  tempc = (tempk - 27315)/100;
  digitalWrite(led, LOW); // turn on pullup resistors
  //time_f = micros();
  
  //time_t = time_f - time_i;
  //Serial.print("temperatura: ");
  //Serial.println(tempc);
  //Serial.print("tempo: ");
  //Serial.println(time_t);
  delay(2000);  
}
