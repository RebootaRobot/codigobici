int sensorPin = 0; //pin analogico 0
int ledPinNaranjo = 13;
int ledPinRojo = 7;
int ledPinAzul = 8;
double varSensor = 0;
double analogValue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPinAzul,OUTPUT);
  pinMode(ledPinNaranjo,OUTPUT);
  pinMode(ledPinRojo,OUTPUT);
}

void loop()
{
  varSensor = analogRead(sensorPin);
  analogValue = ((1/varSensor)*1000)/0.07525;
  Serial.print("Sensor indica: ");
  Serial.print(analogValue);
  Serial.print("cm");

  if(analogValue <= 132.89)
  {
    Serial.println(" = PELIGRO!!..");
    digitalWrite(ledPinRojo, HIGH);
    delay(500);
  }
  else
  {
    if(analogValue > 132.89 && analogValue <= 221.48)
    {
      Serial.println(" = PRECAUCION!!");
      digitalWrite(ledPinNaranjo, HIGH);
      delay(500);
    }
    else
    {
      if(analogValue > 221.48 && analogValue < 500.00)
      {
        Serial.println(" = DISTANCIA SEGURA");
        digitalWrite(ledPinAzul, HIGH);
        delay(500);
      }
      else
      {  
          digitalWrite(ledPinAzul, LOW);
          Serial.println(" = SIN RANGO");
      }
      digitalWrite(ledPinAzul, LOW);
    }
    digitalWrite(ledPinNaranjo, LOW);
  }
  digitalWrite(ledPinRojo, LOW);
  delay(500);

}
