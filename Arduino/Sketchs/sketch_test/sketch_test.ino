int ledPin = 13;                 // LED connected to digital pin 13
int phase[4];

void setup() {
  // put your setup code here, to run once:

  phase[0] = 2;
  phase[1] = 3;
  phase[2] = 4;
  phase[3] = 5;

  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  
  for(unsigned char i = 0; i < 4; i++)
  {
    pinMode(phase[i], OUTPUT);
    digitalWrite(phase[i], LOW);
  }

  Serial.begin(115200, SERIAL_8N1); //Open UART
  Serial.write("Init done.\r\n"); //Write on UART
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(ledPin, !digitalRead(ledPin));

  for(unsigned char i = 0; i < 4; i++)
  {
    digitalWrite(phase[i], HIGH);
    delay(1);
    digitalWrite(phase[i], LOW);
    delay(1);
  }
  

  //digitalWrite(ledPin, HIGH);   // sets the LED on
  //delay(100);                  // waits for 100 ms
  //digitalWrite(ledPin, LOW);    // sets the LED off
  //delay(100);                  // waits for 100 ms
  
  //Serial.write("Coucou!\r\n"); //Write on UART
}
