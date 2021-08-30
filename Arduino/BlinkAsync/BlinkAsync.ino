/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

const int RED_PIN = 8;
const int GREEN_PIN = 9;
const int STATE_OFF = 0;
const int STATE_ON = 1;
const unsigned long RED_ON_TIME = 400;
const unsigned long RED_OFF_TIME = 400;
const unsigned long GREEN_ON_TIME = 400;
const unsigned long GREEN_OFF_TIME = 2000;

unsigned long red_time;
unsigned long green_time;
int red_state;
int green_state;

// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  unsigned long start_time = millis();
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  red_time = start_time;
  green_time = start_time;
  red_state = STATE_OFF;
  green_state = STATE_OFF;
}

void update_red(unsigned long cur_time)
{
  switch(red_state)
  {
    case STATE_OFF:
      if(cur_time - red_time >= RED_OFF_TIME)
      {
        red_state = STATE_ON;
        red_time += RED_OFF_TIME;
        digitalWrite(RED_PIN, HIGH);
      }
      break;
     case STATE_ON:
      if(cur_time - red_time >= RED_ON_TIME)
      {
        red_state = STATE_OFF;
        red_time += RED_ON_TIME;
        digitalWrite(RED_PIN, LOW);
      }
      break;
  }
}

void update_green(unsigned long cur_time)
{
  switch(green_state)
  {
    case STATE_OFF:
      if(cur_time - green_time >= GREEN_OFF_TIME)
      {
        green_state = STATE_ON;
        green_time += GREEN_OFF_TIME;
        digitalWrite(GREEN_PIN, HIGH);
      }
      break;
     case STATE_ON:
      if(cur_time - green_time >= GREEN_ON_TIME)
      {
        green_state = STATE_OFF;
        green_time += GREEN_ON_TIME;
        digitalWrite(GREEN_PIN, LOW);
      }
      break;
  }
}


// the loop function runs over and over again forever
void loop()
{
  unsigned long cur_time = millis();
  update_red(cur_time);
  update_green(cur_time);
}
