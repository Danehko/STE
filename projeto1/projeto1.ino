#define led 13
float aux = 0;
float temp = 0;
float a = 0.001112272865;
float b = 0.0002375809102;
float c = 0.00000006852858650;
float d = 0;
float r = 0;
float vin = 0;
float vout = 5;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); // set pin to input
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH); // turn on pullup resistors
  aux = analogRead(A1);
  vin = (5 * aux)/1023;
  r = 10000*((vin/vout)-1);
  d = log(r);
  temp = 1/(a + (b*d) + (c*d*d*d));
  digitalWrite(led, LOW); // turn on pullup resistors
  Serial.print("temperatura: ");
  Serial.println(temp);
  delay(1000);  
}
