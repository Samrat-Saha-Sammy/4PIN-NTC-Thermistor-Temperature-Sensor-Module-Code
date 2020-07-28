
int Analog_PIN = A0; // Analog PIN A0
int Digital_PIN = 3; // Digital PIN 3

int Min_Temperature = -25;
int Max_Temperature = 80;

const float CURRENT = 5.0; // Volt DC
const float MAX_AD_VALUE = 1023.0; // Max Value for A/D Convertor

const float AD_VALUE_BY_VOLT = (MAX_AD_VALUE / 5.0) * CURRENT; // DO NOT CHANGE

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


  int Temp_Range = (abs(Min_Temperature) + abs(Max_Temperature));

  Analog = analogRead(Analog_PIN);   
  Tf = Analog * (Temp_Range / AD_VALUE_BY_VOLT); // 0 - 1023 is Default Arduino 10 bit resolution for A/D Converter, https://www.arduino.cc/en/Tutorial/AnalogInputPins
  Tc = (Tf - 32) * 5/9; // Fahrenheit to Celsius Formula (32°F − 32) × 5/9 = 0°C
  Digital = digitalRead (Digital_PIN);
    
  //... and outputted here
  Serial.print ("Analog value:"); Serial.print (Analog);
  Serial.print ("Temp (F): "); Serial.print (Tf);
  Serial.print ("Temp (C): "); Serial.print (Tc);
  Serial.print ("Digital Value:"); Serial.print(Digital);
  Serial.println ("----------------------------------------------------------------");
  delay (200);
}
