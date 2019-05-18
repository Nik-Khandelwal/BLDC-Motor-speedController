#include <SoftwareSerial.h>
#include <Servo.h>

Servo esc;
Servo test;
SoftwareSerial bt(0,1);

void setup() {
  // put your setup code here, to run once:
  esc.attach(9,1000,2000);
  test.attach(10,1000,2000);
  esc.writeMicroseconds(1000);
  delay(1000);

  bt.begin(9600);
  Serial.begin(9600);

  Serial.print("Sab laga do");
  delay(15000);
  Serial.print("................................\n");
}

void loop() {
  // put your main code here, to run repeatedly
  int val;
  if(bt.available())
  {
    val = bt.read();
    Serial.print("\n");
    Serial.print(val);
    Serial.print("    ---     ");
    val = map(val,0,255,1000,2000);
//    if(val>=1200)
//      val = 1200;
    Serial.print(val);
    Serial.print("\n");
    esc.writeMicroseconds(val);
    test.writeMicroseconds(val);
  }
}
