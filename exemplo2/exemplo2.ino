byte byte_recived = 1;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()>0) {
            byte_recived = Serial.read();
            byte_recived = byte_recived + 1;
            Serial.write(byte_recived);
    }
}

