const int L1_RED_PIN = 2;
const int L1_YELLOW_PIN = 3;
const int L1_GREEN_PIN = 4;
const int L2_RED_PIN = 5;
const int L2_YELLOW_PIN = 6;
const int L2_GREEN_PIN = 7;

const unsigned long STATE_0_TIME = 2000;
const unsigned long STATE_1_TIME = 1000;
const unsigned long STATE_2_TIME = 10000;
const unsigned long STATE_3_TIME = 2000;
const unsigned long STATE_4_TIME = 2000;
const unsigned long STATE_5_TIME = 1000;
const unsigned long STATE_6_TIME = 15000;
const unsigned long STATE_7_TIME = 2000;


int state;
unsigned long last_change;



void setup() {
  pinMode(L1_RED_PIN, OUTPUT);
  pinMode(L1_YELLOW_PIN, OUTPUT);
  pinMode(L1_GREEN_PIN, OUTPUT);
  pinMode(L2_RED_PIN, OUTPUT);
  pinMode(L2_YELLOW_PIN, OUTPUT);
  pinMode(L2_GREEN_PIN, OUTPUT);
  state = 0;
  digitalWrite(L1_RED_PIN, HIGH);
  digitalWrite(L1_YELLOW_PIN, LOW);
  digitalWrite(L1_GREEN_PIN, LOW);
  digitalWrite(L2_RED_PIN, HIGH);
  digitalWrite(L2_YELLOW_PIN, LOW);
  digitalWrite(L2_GREEN_PIN, LOW);
  last_change = millis();
}

void loop() {
  unsigned long cur_time=millis();
  updateTrafficLight(cur_time);
}

void updateTrafficLight(unsigned long cur_time)
{
  switch(state)
  {
    case 0:
      if(cur_time - last_change >= STATE_0_TIME)
      {
        state = 1;
        digitalWrite(L1_YELLOW_PIN, HIGH);
        last_change += STATE_0_TIME;
      }
      break;
    case 1:
      if(cur_time - last_change >= STATE_1_TIME)
      {
        state = 2;
        digitalWrite(L1_RED_PIN, LOW);
        digitalWrite(L1_YELLOW_PIN, LOW);
        digitalWrite(L1_GREEN_PIN, HIGH);
        last_change += STATE_1_TIME;
      }
      break;
    case 2:
      if(cur_time - last_change >= STATE_2_TIME)
      {
        state = 3;
        digitalWrite(L1_GREEN_PIN, LOW);
        digitalWrite(L1_YELLOW_PIN, HIGH);
        last_change += STATE_2_TIME;
      }
      break;
    case 3:
      if(cur_time - last_change >= STATE_3_TIME)
      {
        state = 4;
        digitalWrite(L1_YELLOW_PIN, LOW);
        digitalWrite(L1_RED_PIN, HIGH);
        last_change += STATE_3_TIME;
      }
      break;
    case 4:
      if(cur_time - last_change >= STATE_4_TIME)
      {
        state = 5;
        digitalWrite(L2_YELLOW_PIN, HIGH);
        last_change += STATE_4_TIME;
      }
      break;
    case 5:
      if(cur_time - last_change >= STATE_5_TIME)
      {
        state = 6;
        digitalWrite(L2_RED_PIN, LOW);
        digitalWrite(L2_YELLOW_PIN, LOW);
        digitalWrite(L2_GREEN_PIN, HIGH);
        last_change += STATE_5_TIME;
      }
      break;
    case 6:
      if(cur_time - last_change >= STATE_6_TIME)
      {
        state = 7;
        digitalWrite(L2_GREEN_PIN, LOW);
        digitalWrite(L2_YELLOW_PIN, HIGH);
        last_change += STATE_6_TIME;
      }
      break;
    case 7:
      if(cur_time - last_change >= STATE_7_TIME)
      {
        state = 0;
        digitalWrite(L2_YELLOW_PIN, LOW);
        digitalWrite(L2_RED_PIN, HIGH);
        last_change += STATE_7_TIME;
      }
      break;
  }
}
