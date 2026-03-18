#include <Servo.h>
#include <math.h>




//Setup

struct point {
  int x;
  int y;
};

struct new_servo {
  int length;
  int offset;
  Servo servo;
};

// Servo configurations



new_servo L1A = { .length=7, .offset=0};
new_servo L1B = { .length=7, .offset=0};

new_servo L2A = { .length=7, .offset=0};
new_servo L2B = { .length=7, .offset=0};

new_servo R1A = { .length=7, .offset=0};
new_servo R1B = { .length=7, .offset=0};

new_servo R2A = { .length=7, .offset=0};
new_servo R2B = { .length=7, .offset=0};



void moveLeg(new_servo &s1, new_servo &s2, point point){

  double x = (double)point.x;
  double y = (double)point.y;
  double l1 = (double)s1.length;
  double l2 = (double)s2.length;
  double r2 = x * x + y * y;
  double r = sqrt(r2);

  if (r > (l1 + l2) || r < fabs(l1 - l2)){
    return;
  }

  double cosKnee = (r2 - l1 * l1 - l2 * l2) / (2.0 * l1 * l2);
  cosKnee = constrain(cosKnee, -1.0, 1.0);
  double kneeRad = acos(cosKnee);

  // Elbow-up branch keeps this leg's shoulder angle in a practical range.
  double shoulderRad = atan2(y, x) - atan2(-l2 * sin(kneeRad), l1 + l2 * cos(kneeRad));

  double shoulderDeg = shoulderRad * 180.0 / PI;
  double kneeDeg = kneeRad * 180.0 / PI;

  double s1ServoDeg = 90.0 + shoulderDeg + s1.offset;
  double s2ServoDeg = (180.0 - kneeDeg) + s2.offset;

  s1ServoDeg = constrain(s1ServoDeg, 0.0, 180.0);
  s2ServoDeg = constrain(s2ServoDeg, 0.0, 180.0);

  Serial.println("r");
  Serial.println(r);
  Serial.println("shoulderDeg");
  Serial.println(shoulderDeg);
  Serial.println("kneeDeg");
  Serial.println(kneeDeg);
  Serial.println("s1ServoDeg");
  Serial.println(s1ServoDeg);
  Serial.println("s2ServoDeg");
  Serial.println(s2ServoDeg);

  s1.servo.write((int)s1ServoDeg);
  s2.servo.write((int)s2ServoDeg);
}

void setup() {
 Serial.begin(9600);


  // put your setup code here, to run once:
  L1A.servo.attach(10);
  L1B.servo.attach(8);

  L1A.servo.write(0);
  L1B.servo.write(0);
  delay(2000);
  L1A.servo.write(90);
  L1B.servo.write(90);
  delay(2000);
  L1A.servo.write(180);
  L1B.servo.write(180);
  delay(3000);


}

point a = { .x=7, .y=6};
point b = { .x=-4, .y=-10};
point c = { .x=0, .y=-7};

void loop() {
  // put your main code here, to run repeatedly:


  moveLeg(L1A, L1B, a);
  delay(2000);
  moveLeg(L1A, L1B, b);
  delay(2000);
  moveLeg(L1A, L1B, c);
  delay(2000);



}
