#define led 13
unsigned long time_i;
unsigned long time_f;
unsigned long time_t;
long int vout_d = 0;
long int d = 0;
long int r = 0;
long int r0 = 10000;
long int vin = 5;
long int vout = 0;
long int B = 3950;
long int t0 = 29815;
long int tempf = 0;
float a1 = 0;
float a2 = 0;
float a3 = 0;
float aux = 0;
long int tempk = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); // set pin to input
}

void loop() {
  time_i = micros();
  digitalWrite(led, HIGH); // turn on pullup resistors
  vout_d = analogRead(A1);
  d =(102300/vout_d)-100;
  r = r0*d;
  a1=1/(t0/100);
  a2=1/B;
  a3=log(r/(r0*100));
  aux = 1/(a1+a2*a3);
  tempk = aux;
  tempf = (tempk-27315)/100;
  digitalWrite(led, LOW); // turn on pullup resistors
  Serial.print("temperatura: ");
  Serial.println(tempf);
  time_f = micros();
  time_t = time_f - time_i;
  Serial.print("tempo: ");
  Serial.println(time_t);
  delay(2000);  
}
