#include <DistanceGP2Y0A21YK.h>

DistanceGP2Y0A21YK Dist;
int distance;
int led1 = A0;
int led2 = A3;
int led3 = A5;

void setup()
{
  Serial.begin(9600);
  Dist.begin(A4);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
    //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
}

void loop()
{
  
  
    //Motor A forward @ full speed
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed

  //Motor B backward @ half speed
  digitalWrite(13, HIGH);  //Establishes backward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);    //Spins the motor on Channel B at half speed

  distance = Dist.getDistanceCentimeter();
  Serial.print("\nDistance in centimers: ");
  Serial.print(distance);
  if(distance > 10){
    digitalWrite(led1, HIGH); 
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    
  } else{
    
    
    if(distance > 5 && distance < 10)
    {
             digitalWrite(led2, LOW); 
    digitalWrite(led1, LOW); 
    digitalWrite(led3, HIGH);
      
    }else{
             digitalWrite(led2, HIGH); 
    digitalWrite(led1, LOW); 
    digitalWrite(led3, LOW);
    }
    

  }
  delay(500); //make it readable
}
