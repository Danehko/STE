#define led 13
#define r0 10000
#define r10k 10000
#define vin 5
#define B 3950
#define t0 298.15

unsigned long time_i;
unsigned long time_f;
unsigned long time_t;

float vout_d = 0;
float vout = 0;
float tempk = 0;
float tempc = 0;
float rntc = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  time_i = micros();
  
  digitalWrite(led, HIGH);
  vout_d = analogRead(A1);
  vout = (vin * vout_d)/1023;
  rntc = r10k*((vin/vout)-1);
  tempk = 1/((1/t0)+(1/B)*(log(r/r0)));
  tempc = tempk - 273.15;
  digitalWrite(led, LOW);
  time_f = micros();
  
  time_t = time_f - time_i;
  Serial.print("temperatura: ");
  Serial.println(tempc);
  Serial.print("tempo: ");
  Serial.println(time_t);
  delay(2000);  
}
