
int medidaSensor = 0;
int ledFrio = 8;
int ledTibio = 9;
int ledCaliente = 10;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(ledFrio, OUTPUT);
pinMode(ledTibio, OUTPUT);
pinMode(ledCaliente, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

int medida = analogRead(medidaSensor);
float voltage = medida * 5.0;
voltage /= 1024.0;

float temperatura = (voltage - 0.5) * 100;
float wald = temperatura * 1.5;

Serial.print(temperatura); Serial.print(" C    ::    "); 
Serial.print(wald); Serial.println(" W");

if(wald < 28)
  {
    digitalWrite(ledFrio, HIGH);
    digitalWrite(ledTibio, LOW);
    digitalWrite(ledCaliente, LOW);
  }
  else if(wald >= 29 && wald < 40)
    {
    digitalWrite(ledFrio, LOW);
    digitalWrite(ledTibio, HIGH);
    digitalWrite(ledCaliente, LOW);
    }
  else if(wald >= 41)
    {
    digitalWrite(ledFrio, LOW);
    digitalWrite(ledTibio, LOW);
    digitalWrite(ledCaliente, HIGH);
    }
 
delay(1000);

}
