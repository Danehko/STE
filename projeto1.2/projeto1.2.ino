#define led 13
float aux = 0;
float tempk = 0;
float temp = 0;
float d = 0;
float r = 0;
float r0 = 10000;
float vin = 5;
float vout = 0;
float B = 3950;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); // set pin to input
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH); // turn on pullup resistors
  aux = analogRead(A1);
  vout = (5 * aux)/1023;
  r = r0*((vin/vout)-1);
  tempk = (1/298.15)+((1/B)*log(r/r0));
  temp = 1/tempk;
  Serial.println(log((r*100)/r0));
  digitalWrite(led, LOW); // turn on pullup resistors
  Serial.print("temperatura: ");
  Serial.println(temp-273.15);
  delay(2000);  
}
