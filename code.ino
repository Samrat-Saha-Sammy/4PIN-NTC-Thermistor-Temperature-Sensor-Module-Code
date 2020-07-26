
int Analog_PIN = A0; // Analog PIN
int Digital_PIN = 3; // Digital PIN
  
void setup ()
{
  pinMode (Analog_PIN, INPUT);
  pinMode (Digital_PIN, INPUT);
       
  Serial.begin (9600); // serial output with 9600 bps
}
  
// The program reads the current values at the input pins
// and outputs them at the serial output
void loop ()
{
  float Analog;
  float Tf;
  float Tc;
  int Digital;

  Analog = analogRead(Analog_PIN);   
  Tf = Analog * (95 / 1023.0); // -25 ~ 80
  Tc = (Tf - 32) * 5/9;
  Digital = digitalRead (Digital_PIN);
    
  //... and outputted here
  Serial.print ("Analog value:"); Serial.print (Analog);
  Serial.print ("Temp (F): "); Serial.print (Tf);
  Serial.print ("Temp (C): "); Serial.print (Tc);
  Serial.print ("Digital Value:"); Serial.print(Digital);
  Serial.println ("----------------------------------------------------------------");
  delay (200);
}
