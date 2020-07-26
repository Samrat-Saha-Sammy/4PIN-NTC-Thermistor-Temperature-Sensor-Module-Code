#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int Analog_PIN = A0; // Analog PIN
int Digital_PIN = 3; // Digital PIN

LiquidCrystal_I2C lcd(0x27, 16, 2);
  
void setup ()
{
  pinMode (Analog_PIN, INPUT);
  pinMode (Digital_PIN, INPUT);
       
  //Serial.begin (9600); // serial output with 9600 bps

  // initialize the LCD, 
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();   
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
  //Serial.print ("Analog value:"); Serial.print (Analog);
  //Serial.print ("Temp (F): "); Serial.print (Tf);
  //Serial.print ("Temp (C): "); Serial.print (Tc);
  //Serial.print ("Digital Value:"); Serial.print(Digital);
  //Serial.println ("----------------------------------------------------------------");
  lcd.clear();// clear previous values from screen
  lcd.setCursor(0, 0);
  lcd.print(Tc);
  lcd.setCursor(6,0);
  lcd.print((char)223);
  lcd.setCursor(7,0);
  lcd.print("C");
  
  delay (1000);
}
