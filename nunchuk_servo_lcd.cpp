#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include "Wire.h"
#include <WiiNunChuk.h>
#include <math.h>


#define MAXANGLE 90
#define MINANGLE -90

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);    //LCD-Pins: Gelb A4  Weiss A5  Rot +5   Grau -
WiiChuck chuck = WiiChuck();
Servo servo;

int angleStart, currentAngle;
int tillerStart = 0;
double angle;

void setup() {
  lcd.begin(16,2); // initialize the lcd 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NunChuk:");
  lcd.setCursor(0,1);
  lcd.print("Servo  :");
  servo.attach(9); // servo an pin 9
  servo.write(1);  // servo auf Null Grad
  //Serial.begin(115200);
  chuck.begin();
  chuck.update();
  //chuck.calibrateJoy();
}


void loop() {
  delay(20);
  chuck.update();
  //Button Z
    if (chuck.buttonZ) {
       lcd.setCursor(15,0);
       lcd.print("Z");
      } else  {
       lcd.setCursor(15,0);
       lcd.print(" ");
     }
   //Button C
    if (chuck.buttonC) {
       lcd.setCursor(15,1);
       lcd.print("C");
      } else  {
       lcd.setCursor(15,1);
       lcd.print(" ");
     }
  int val = chuck.readRoll();
  val = map(val,-90,90,0,180);
  val = round(val/5)*5;  //auf 5 grad runden, wenig Jitter

  //Serial.print(chuck.readRoll());
  //Serial.print(", ");  
  //Serial.print(chuck.readPitch());
  //Serial.print(", ");  

  //  Serial.print((int)chuck.readAccelX());
  //  Serial.print(", ");  
  //  Serial.print((int)chuck.readAccelY());
  //  Serial.print(", ");  

  //  Serial.print((int)chuck.readAccelZ());

  //  Serial.println();
    //lcd.clear();
    
    lcd.setCursor(10,0);
    lcd.print((int)chuck.readRoll());
    lcd.setCursor(10,1);
    lcd.print(val);
    servo.write(val);
}
