#define led 13
#define B 3950
#define r10k 10000
#define vin 5
#define rinf 0.0176

unsigned long time_i;
unsigned long time_f;
unsigned long time_t;

float vout = 0;
float vout_d = 0;
float tempk = 0;
float tempc = 0;
float rntc = 0;
float lnr = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  time_i = micros();
  
  digitalWrite(led, HIGH); // turn on pullup resistors
  vout_d = analogRead(A1);
  vout = (vin * vout_d)/1023;
  rntc = r10k*((vin/vout)-1);
  lnr = log(rntc/rinf);
  tempk = B/(lnr);
  tempc = tempk - 273.15;
  digitalWrite(led, LOW); // turn on pullup resistors
  time_f = micros();
  
  time_t = time_f - time_i;
  Serial.print("temperatura: ");
  Serial.println(tempc);
  Serial.print("tempo: ");
  Serial.println(time_t);
  delay(2000);  
}
