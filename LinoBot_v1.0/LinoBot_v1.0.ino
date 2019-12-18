/*-------definning Inputs------*/
#define LS  A5    // left sensor
#define RS  A4  // right sensor


/*-------definning Outputs------*/
#define LM1 4    // left motor
#define LM2 5    // left motor
#define RM1 10    // right motor
#define RM2 11     // right motor

int ENA=9; //right motor
int ENB=6; //left motor
int nodeInput = 2;

int SPEED=250;
void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(nodeInput, INPUT);
  
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  
  Serial.begin(9600);
}

void loop(){
  
  int nodeInputValue = digitalRead(nodeInput);
  
  if(nodeInputValue == 1) {
    if((analogRead(LS)>250) && (analogRead(RS)>250))  
    {    
      MoveForward();
    }
    
    if((analogRead(LS)<250) && (analogRead(RS)<250))  
    {
        Stop();
    }
    if((analogRead(LS)<250) && (analogRead(RS)>250))  
    {
      TurnLeft();
    }
    
    if((analogRead(LS)>250) && (analogRead(RS)<250))
    {
      TurnRight();
    }
  } else {
    Stop();
  }

}

void MoveForward()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    analogWrite(ENA,SPEED);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(ENB,SPEED);
    delay(20);
}

void TurnRight()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    analogWrite(ENB,SPEED);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(ENA,SPEED);
    delay(30); 
}

void TurnLeft() 
{
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(ENB,SPEED);
    digitalWrite(RM1, HIGH);  
    digitalWrite(RM2, LOW);
    analogWrite(ENA,SPEED);
    delay(30);
}

void Stop()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    analogWrite(ENA,SPEED);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    analogWrite(ENB,SPEED);
    delay(20);
}
