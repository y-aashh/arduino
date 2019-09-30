#include <SPI.h>
#include <SD.h>
const int green = 2,red = 3,button = 5;
File myFile;
String q;
void setup() {
  // put your setup code here, to run once:
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  Serial.begin(4800);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  digitalWrite(green,HIGH);
  digitalWrite(red,HIGH);
  delay(1000);
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  delay(1000);
  if (!SD.begin(4)) {
    while (1){digitalWrite(red,HIGH);};
  }
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  myFile = SD.open("test.txt");
  digitalWrite(green,HIGH);
  delay(1000);
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  while(digitalRead(button) == LOW){
    digitalWrite(green,HIGH);
    }
    if (myFile) {
  digitalWrite(red,HIGH);      

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      digitalWrite(green,LOW);
      digitalWrite(red,HIGH);
      delay(250);
      //if(Serial.read() == 1)
      q = myFile.readStringUntil('\n');
      Serial.println(q);
      delay(250);
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    digitalWrite(green,HIGH);
    digitalWrite(red,HIGH);
  }
    
}
