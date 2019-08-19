#define led 13
unsigned long time_i;
unsigned long time_f;
unsigned long time_t;
float vout_d = 0;
float tempk = 0;
float temp = 0;
float d = 0;
float r = 0;
float r0 = 10000;
float vin = 5;
float vout = 0;
float a1 = 0;
float a2 = 0;
float a3 = 0;
float B = 3950;
float t0 = 298.15;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); // set pin to input
}

void loop() {
  // put your main code here, to run repeatedly:
  time_i = micros();
  digitalWrite(led, HIGH); // turn on pullup resistors
  vout_d = analogRead(A1);
  vout = (vin * vout_d)/1023;
  r = r0*((vin/vout)-1);
  a1=1/t0;
  a2=1/B;
  a3=log(r/r0);
  tempk = (a1+a2*a3);
  temp = 1/tempk;
  digitalWrite(led, LOW); // turn on pullup resistors
  Serial.print("temperatura: ");
  Serial.println(temp-273.15);
  time_f = micros();
  time_t = time_f - time_i;
  Serial.println(time_t);
  delay(2000);  
}
