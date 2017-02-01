#include <Servo.h>

Servo servo_motor;
int iter = 0; // iteration count
int starting_pos = 90; // starting position for servo in [0,180]
void setup()
{
  servo_motor.attach(9); // attaching servo to pin number 9
  Serial.begin(9600);
  
}


void goto_pos(int pos, int dely = 15) //pos is the new position and dely is the dely between each angel
{
  int curr_angle = servo_motor.read();
  Serial.print("Current angle  : ");
  Serial.println(curr_angle);
  
  if(pos < curr_angle)
  {
    for(int i = curr_angle; i >= pos ; i--)
    {
      servo_motor.write(i);
      delay(dely); // giving the delay between each intermediate turn of one degreee
      //Possibily add a break if new angle request comes
    }
  }
  else if(pos  > curr_angle)
  {
    for(int i= curr_angle ; i <= pos; i++)
    {
      servo_motor.write(i);
      delay(dely);
      //Possibily add a break if new angle request comes

    }
  }
  Serial.print("New Angle is : ");
  Serial.println(servo_motor.read());
  
}
void loop()
{
  if(iter ==0){
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
    String str;
    if(Serial.available())
    {
      int i = Serial.read();
      if(idDigit(i)){
        str += (char)i; 
      }
    }
    Serial.print("Read :");
    int pos = str.toInt();
    Serial.print(pos);
    Serial.println(".00")

    if(pos < 10 || pos > 170)
    {
      Serial.println("Error : Angle out of bounds : " + pos);
    }
    else
    goto_pos(pos); // can also give delays
    iter++;
    
      
      
    }
      


