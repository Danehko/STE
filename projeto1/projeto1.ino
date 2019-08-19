#define led 13
#define a 0.001112272865
#define b 0.0002375809102
#define c 0.00000006852858650
#define r10k 10000
#define vin 5

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
  pinMode(led, OUTPUT); // set pin to input
}

void loop() {
  time_i = micros();
  
  digitalWrite(led, HIGH);
  vout_d = analogRead(A1);
  vout = (5 * vout_d)/1023;
  rntc = r10k*((vin/vout)-1);
  tempk = 1/(a + (b*(log(rntc))) + (c*(log(rntc))*(log(rntc))*(log(rntc))));
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
