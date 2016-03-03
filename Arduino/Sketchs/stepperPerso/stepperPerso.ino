#define INTER_STEP_DELAY 900
#define INTRA_STEP_DELAY 0

unsigned char stepperPin[4] = {8,9,10,11};
unsigned char ledPin = 13;
unsigned char stepperStates[8][4] =
{
  {HIGH,LOW,LOW,LOW},
  {HIGH,HIGH,LOW,LOW},
  {LOW,HIGH,LOW,LOW},
  {LOW,HIGH,HIGH,LOW},
  {LOW,LOW,HIGH,LOW},
  {LOW,LOW,HIGH,HIGH},
  {LOW,LOW,LOW,HIGH},
  {HIGH,LOW,LOW,HIGH}
};

void setup() {
  // initialize the serial port:
  Serial.begin(115200);

  for(unsigned char i = 0; i < 4; i++)
  {
    pinMode(stepperPin[i], OUTPUT);
    digitalWrite(stepperPin[i], LOW);
  }

  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, !digitalRead(ledPin));

  for(unsigned short stepCount = 0; stepCount < 2000; stepCount ++)
  {  
    for(unsigned char currentStep = 0; currentStep < 8; currentStep++)
    {
      for(unsigned char phase = 0; phase < 4; phase++)
      {
        digitalWrite(stepperPin[phase],stepperStates[currentStep][phase]);
      }
      delayMicroseconds(INTER_STEP_DELAY);
    }
  }
  for(unsigned char i = 0; i < 4; i++)
  {
    digitalWrite(stepperPin[i], LOW);
  }

  delay(50);

  for(unsigned short stepCount = 0; stepCount < 2000; stepCount ++)
  {  
    for(char currentStep = 8; currentStep > 0; currentStep--)
    {
      for(unsigned char phase = 0; phase < 4; phase++)
      {
        digitalWrite(stepperPin[phase],stepperStates[currentStep-1][phase]);
      }
      delayMicroseconds(INTER_STEP_DELAY);
    }
  }
  for(unsigned char i = 0; i < 4; i++)
  {
    digitalWrite(stepperPin[i], LOW);
  }

  delay(50);
}

