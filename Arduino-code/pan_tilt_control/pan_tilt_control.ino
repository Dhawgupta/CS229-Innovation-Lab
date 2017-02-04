#include <Servo.h>

Servo pan;
Servo tilt;

int pos = 90;

void setup()
{
  pan.attach(2);
  tilt.attach(3);
  pan.write(pos);
  tilt.write(pos);
  
}

void move_to_pos(int npos,int which) // 0 for pan and 1 for tilt
{
 int opos;
  switch(which)
  {
  case 0: opos = pan.read();
  if (opos > npos)
  {
    for(int i = opos;i>=npos;i--)
    {
      pan.write(i);
      delay(15);
    }
  }
  else{
    for(int i = opos;i<=npos;i++)
    {
      pan.write(i);
      delay(15);
    }
  }
  break;
  case 1: opos = tilt.read();
  if (opos > npos)
  {
    for(int i = opos;i>=npos;i--)
    {
      tilt.write(i);
      delay(15);
    }
  }
  else{
    for(int i = opos;i<=npos;i++)
    {
      tilt.write(i);
      delay(15);
    }
  }
  break;
  
    
  }
  
}
void loop()
{
  int pangle,tangle;
  pangle = map(analogRead(A0),0,1023,0,180);
  tangle = map(analogRead(A1),0,1023,0,180);
  // 0 for pan and 1 for tilt
  move_to_pos(pangle,0);
  delay(10);
  
  move_to_pos(tangle,1);
  delay(10);
  
}

