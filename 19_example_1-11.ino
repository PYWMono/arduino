#include <Servo.h>
#define PIN_SERVO 10
#define PIN_IR A0

int timec, duty;
float purpose, curr;
Servo myservo;

void setup() {
  Serial.begin(57600);
  myservo.attach(PIN_SERVO); 
  curr = 1605;
  duty = 14;
}

float ir_distance(void){ // return value unit: mm
  float val;
  float volt = float(analogRead(PIN_IR));
  val = ((6762.0/(volt-9.0))-4.0) * 10.0;
  return val;
}

void loop() {
  float raw_dist = ir_distance();
  
  Serial.print("min:0,max:500,dist:");
  Serial.println(raw_dist);
  
  if (raw_dist >= 190){
    purpose = 1805;
  }
  else if (raw_dist <= 170){
    purpose = 1405;
  }

  if (purpose >= curr){
    curr = (curr+duty)>purpose ? purpose : curr+duty;
  }
  else if (purpose <= curr){
    curr = (curr-duty)<purpose ? purpose : curr-duty;
  }
  myservo.writeMicroseconds(curr);
  delay(10);
}
