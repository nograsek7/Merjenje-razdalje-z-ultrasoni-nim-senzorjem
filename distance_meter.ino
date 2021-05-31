#include <LiquidCrystal.h>
 
#define trigger 9
#define echo 8
 
LiquidCrystal lcd(12,11,5,4,3,2);
 
float time=0,distance=0;
 
void setup()
{
 lcd.begin(16,2);
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 lcd.print(" Zivijo!");
 delay(2000);
 lcd.clear();
 lcd.print(" Zacnite meriti!");
 delay(3000);
}
 
void loop()
{
 lcd.clear();
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 distance=time*340/20000;
 lcd.clear();
 lcd.print("Razdalja:");
 lcd.print(distance);
 lcd.print("cm");
 lcd.setCursor(0,1);
 lcd.print("Razdalja:");
 lcd.print(distance/100);
 lcd.print("m");
 delay(1000);
}
