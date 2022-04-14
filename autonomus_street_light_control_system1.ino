// C++ code

// initiallise Photo sensor value to 0
int sensorValue = 0;

//intialise value for PIR sensor and photoresistor

int PIRPin=7;         
int PIRPin2 = 8;

int isObstacle=LOW;
int PIR_val=0;

int PIR_val2=0;

// All setup for INPUT and OUTPUT value

void setup()
{  
  //setup for Photo sensor
  
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  
  //Setup for PIR sensor
  
  pinMode(PIRPin, INPUT);
  pinMode(PIRPin2, INPUT);
  Serial.begin(9600);
}

// Now we give command according to our giving condition

void loop()
{
  // read the value from the photo sensor
  
  sensorValue = analogRead(A0);
  
  //read value from PIR sensor
  PIR_val=digitalRead(PIRPin);
  
  PIR_val2=digitalRead(PIRPin2);
  
  // print the photo sensor reading so you know its range
  
  Serial.print(sensorValue);
  Serial.print(",");
  
  //print the PIR sensor reading
  Serial.println(PIR_val);
  
  Serial.print(",");
  Serial.println(PIR_val2);
 
  
  
  // Giving Condition to LED according to
  
  //Intensitiy detect by Photodiode and value obtain from PIR sensor
  if(sensorValue<800&&PIR_val==1)
  {
    if(PIR_val==1)
    {
    digitalWrite(9,HIGH);         // command to turn on LED
    Serial.println("!!!Obstacle!!!!");
    delay(1000);
    }
  }
  if(sensorValue<800&&PIR_val==1&&PIR_val2==0)
  {
    digitalWrite(9,HIGH);          // command to turn on LED
    Serial.println("!!!Obstacle!!!!");
    delay(1000);
  }

  if(sensorValue<800&&PIR_val2==1)
  {
    digitalWrite(9,LOW);           // command to turn off LED
   }
  if(sensorValue>800&&PIR_val2==0)
  {
    digitalWrite(9,LOW); 
  }
  
  delay(500);
  
}


// End of Prograamme 
// Thank You