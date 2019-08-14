#define led 13
long int vout_d = 0;
long int tempk = 0;
long int temp = 0;
long int d = 0;
long int r = 0;
long int r0 = 10000;
long int vin = 5;
long int vout = 0;
long int B = 3950;
long int t0 = 29815;
long int tempf = 0;
long int a1 = 0;
long int a2 = 0;
long int a3 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); // set pin to input
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH); // turn on pullup resistors
  vout_d = analogRead(A1);
  //vout = ((vin * vout_d)/1023)*100;
  d =(102300/vout_d)-100;
  r = r0*d;
  a1=1/t0;
  a2=1/B;
  a3=log(r/r0);
  tempk = a1+a2*a3;
  Serial.println(a3);
  tempf = (tempk-27315)/100;
  digitalWrite(led, LOW); // turn on pullup resistors
  Serial.print("temperatura: ");
  Serial.println(tempf);
  delay(2000);  
}
