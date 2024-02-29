// This is the first test for a weekly solenoid controller. 
// Solenoid will turn on for x amount of time, every x days. 
// 

const unsigned long SECOND = 1000;
const unsigned long HOUR = 3600*SECOND;
const unsigned int numOfDays = 3;
const unsigned int runningHours = 1;



class Solenoid
{
  private:
    unsigned long timeAtStart;
    int timeToRun;
    
  public:
    int identifier;
    string section;
    bool isRunning;
    
    void setTimer(int timeInMinutes)
    { // use millis() to set start time, then in main code if the time dif in millis  goes over set time limit, do stuff. 
      timeAtStart = millis();
      timeToRun = timeInMinutes;
    }
    
    int getTimeRun()
    {
      return millis() - timeAtStart()
    }
    
}







void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  delay(5000);
  digitalWrite(32, LOW);
  digitalWrite(33, LOW);

}



void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < runningHours; i++) {
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    delay(1*HOUR);
  }

  for(int i = 0; i <numOfDays; i++) {
    delay(24*HOUR);
  }
}

void turnOnSolenoid(int solenoid)
{
  
}

void turnOffSolenoid(int solenoid)
{

}
