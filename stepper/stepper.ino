#include <Stepper.h>

#define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)
Stepper stepper(STEPS, 8, 10, 9, 11);

int input;
int sign;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    input = (int)Serial.read();
    input -= 48;
    Serial.println(input);
    if(input == 0){
      stepper.setSpeed(0); // Stop
    } else if(input >= 1 && input <= 4){ // CCW
      stepper.setSpeed(input*4);
      sign = 1;
    } else if(input >= 5 && input <= 8){ //CW
      stepper.setSpeed((input-4)*4);
      sign -= 1;
    }
    stepper.step(sign*30);
  }
  delay(1);
  /*
  stepper.setSpeed(6); // 1 rpm
  stepper.step(2038); // do 2038 steps -- corresponds to one revolution in one minute
  delay(1000); // wait for one second
  stepper.setSpeed(6); // 6 rpm
  stepper.step(-2038); // do 2038 steps in the other direction with faster speed -- corresponds to one revolution in 10 seconds
  */
}
