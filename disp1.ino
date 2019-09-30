
#include <Servo.h>
#define up 8
#define down 7
int i=0;
int s,b,t,r;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int val,k;    // variable to store the servo position
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  Serial.begin(9600);
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("TEAM SOLARIUM");
  lcd.setCursor(0,1);
  lcd.print("INVICTUS 2.O");
  delay(5000);
  lcd.clear();
}

void loop() {
   while(digitalRead(up)==HIGH)
  {
   k=0;
  i++;
  delay(300);
  break;
  }
  while(digitalRead(down)==HIGH)
  {
   k=1;
  i--;
  delay(300);
  break;
  }
  if(i<=0)
  {
  i=0;
  }
   if(i>=4)
  {
  i=4;
  }
  Serial.println(i);
  if(k==0)
  {
  switch(i)
  {
    case 0: val=20;
    break;
     case 1: val=60;
    break;
     case 2: val=90;
    break;
     case 3: val=125;
    break;
     case 4: val=180;
    break;
  }
  }
   if(k==1)
  {
  switch(i)
  {
    case 0: val=30;
    break;
     case 1: val=40;
    break;
     case 2: val=65;
    break;
     case 3: val=100;
    break;
     case 4: val=180;
    break;
  }
  }
  
     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val); // sets the servo position according to the scaled value
  Serial.println(pos);
  delay(15); 
  
 
  double batterypercentage;
  double sensorValue = analogRead(A1);
  double voltage1 = sensorValue*5/1023*0.97490;
  double voltage = sensorValue*5/1023*0.964278;
  Serial.println(voltage);
if(voltage1<=3.52969&&voltage1>=3.27757)//100-95%
{
  batterypercentage=((voltage1+1.51271)/0.050424);
  Serial.println(batterypercentage);
    //lcd.print(batterypercentage);
}
if(voltage1<3.27757&&voltage1>=3.1936)//95-90%
{
  batterypercentage=((voltage1-1.68207)/0.016794);
  Serial.println(batterypercentage);
  //lcd.print(batterypercentage);
}
if(voltage1<3.1936&&voltage1>=3.1096 )//90-80%
{
  batterypercentage=((voltage1-2.4376)/0.0084);
  Serial.println(batterypercentage);
  //lcd.print(batterypercentage);
}
if(voltage<3.1096&&voltage>=3.0844)//80-70%
{
  batterypercentage=((voltage-2.908)/0.00252);
  Serial.println(batterypercentage);
  //lcd.print(batterypercentage);
}
if(voltage<3.0844&&voltage>=3.0255)//70-60%
{
  batterypercentage=((voltage-2.6721)/0.00589);
  Serial.println(batterypercentage);
  lcd.print(batterypercentage);
}
if(voltage<3.0255&&voltage>=2.9835)//60-50%
{
  batterypercentage=((voltage-2.7735)/0.0042);
  Serial.println(batterypercentage);
  //lcd.print(batterypercentage);
}
if(voltage<2.9835&&voltage>=2.9415)//50-40%
{
  batterypercentage=((voltage-2.7735)/0.0042);
  Serial.println(batterypercentage);
  //lcd.print(batterypercentage);
}
if(voltage<2.9415&&voltage>=2.8995)//40-30%
{
  batterypercentage=((voltage-2.7735)/0.0042);
  Serial.println(batterypercentage);
  lcd.print(batterypercentage);
}
if(voltage<2.8995&&voltage>=2.8115)//30-20%
{
  batterypercentage=((voltage-2.6355)/0.0088);
  Serial.println(batterypercentage);
  //lcd.print(batterypercentage);
}
if(voltage<2.8115&&voltage>=2.7650)//20-10%
{
  batterypercentage=((voltage-2.7138)/0.00465);
  Serial.println(batterypercentage);
  lcd.print(batterypercentage);
}
if(voltage<2.7650&&voltage>=2.7062)//10-5%
{
  batterypercentage=((voltage-2.6474)/0.01176);
  Serial.println(batterypercentage);
  //lcd.print(batterypercentage);
}
if(voltage<2.7062&&voltage>=2.35)//battery low
{
  batterypercentage=((voltage-2.354)/0.07124);
  Serial.println(batterypercentage);
  lcd.print(batterypercentage);
    //Serial.println("Battery_Low");
}
//Serial.println("next");


////Serial.println("next");
  //char str[4];
 s=65;
 r=60;
 int t1=batterypercentage;
  lcd.setCursor(0,0);
  lcd.print("B");
  lcd.print(t1);
  lcd.print("%");
  
  lcd.setCursor(6,0);
  lcd.print("T:");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(13,0);
  lcd.print("G");
  lcd.print(":");
  lcd.print(i);
  lcd.setCursor(0,1);
  lcd.print("S:");
  lcd.print(s);
  lcd.print("kph");
  lcd.setCursor(8,1);
  lcd.print("DTE:");
  lcd.print(r);
  lcd.print("km");
   
  }
