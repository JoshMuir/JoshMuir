#define drive D5 // pwm control on pin D5
#define in3 D6 // forward control on pin D6
#define in4 D7
#define min_acceptable 450
#define max_acceptable 950



void setup() {
  Serial.begin(115200);
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT);
  pinMode(drive, OUTPUT);
  pinMode (A0, INPUT); // pot read
  pinMode(D1, INPUT_PULLUP); 
  //digitalWrite(, );
  digitalWrite(in3, LOW); // set fwd to high 
  digitalWrite(in4, HIGH);
  analogWriteRange(1023);
  analogWriteFreq(1250);
}

unsigned int motorSpeed;

void loop() {




  // when the trigger button is not being pressed, we will take a reading of the pot every 3 seconds.
  while (digitalRead(D1) == HIGH) //  button is not pressed
  {     
    analogWrite(drive,0);
    readValue(&motorSpeed);
    delay(3000);
  }
  
  
}

// We want readValue() to return an accurate reading. Therefore we will disregard any readings that are outside of a determined boundary, and then take an average of 32 valid readings. 
void readValue(unsigned int *pmotorSpeed) 
{
    unsigned int sumOfReadings =0, acceptedReadings = 0, speed = 0;
    bool validReading, fault = FALSE;
    while (acceptedReadings < 32) 
  {
      if(digitalRead(D1==LOW))
      {
        pFault = &fault;
        *pFault = TRUE; // set fault flag
        break; // bail out of the reading while loop
      }
      speed = analogRead(A0);
      validReading = speed > min_acceptable && speed < max_acceptable;
      
      if (!validReading) {continue;} // do not pass go, do not collect $200.
      
      if (validReading) 
      {
        sumOfReadings += speed;
        acceptedReadings++;
      }
  }
    if(!fault){*pmotorSpeed = sumOfReadings >> 5;} // if the program did not bail out, assign the new valid motor speed
}




