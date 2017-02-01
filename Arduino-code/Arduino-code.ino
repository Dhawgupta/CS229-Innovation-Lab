#include <Servo.h>

Servo servo_motor;
int iter = 0; // iteration count
int starting_pos = 90; // starting position for servo in [0,180]
void setup()
{
  servo_motor.attach(9); // attaching servo to pin number 9
  Serial.begin(9600);
  
}

void loop()
{
  if(run ==0){
    Serial.println("Setting up system and attached servo..");
    delay(15);
    Serial.print("Moving to the initial position : ");
    Serial.println(starting_pos);
    servo_motor_write(starting_pos);
    delay(30);
    Serial.println("Init Done.");
    }

    Serial.println("Waiting for Data");
    while(!Serial.available());
      
}

