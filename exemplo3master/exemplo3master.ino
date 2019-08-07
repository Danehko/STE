//master
int num = 0;
void setup() {
  Serial3.begin(9600);
}

void loop() {
  num = 0;
  Serial3.write(num);
  delay(2000);
  num = 1;
  Serial3.write(num);
  delay(2000);
}


       


