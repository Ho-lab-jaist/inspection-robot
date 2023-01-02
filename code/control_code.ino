#include <MP.h>
#include <time.h>

#ifdef SUBCORE /* SUBCORE */

#if (SUBCORE == 1)
#define SUBID "Sub1"
#elif (SUBCORE == 2)
#define SUBID "Sub2"
#elif (SUBCORE == 3)
#define SUBID "Sub3"
#elif (SUBCORE == 4)
#define SUBID "Sub4"
#elif (SUBCORE == 5)
#define SUBID "Sub5"
#endif

float f = 1.0;
float t = 1000/(2*f);
float s = 0.5*t;
int count = 0;

static const uint8_t pin_x = PIN_A0;
static const uint8_t pin_y = PIN_A1;

int xPosition = 0;
int yPosition = 0;
//int SW_state = 0;
int mapX = 0;
int mapY = 0;


void setup() {
//  pinMode(1, OUTPUT);
//  pinMode(2, OUTPUT);
//  pinMode(3, OUTPUT);
//  pinMode(14, OUTPUT);
//  digitalWrite(14, LOW);
//  pinMode(VRx, INPUT);
//  pinMode(VRy, INPUT);

//  pinMode(PIN_A2, INPUT);
//  pinMode(A1, INPUT);
//  Serial.begin(115200);
  MP.begin();
}

void loop() {
  if (SUBID == "Sub1"){
    if (count == 0){
      delay(141);
      digitalWrite(2, HIGH);
      digitalWrite(LED0, HIGH);
      delay(t);
      digitalWrite(2, LOW);
      digitalWrite(LED0, LOW);
      delay(t);
      count = 1;
    }
    else{
      digitalWrite(2, HIGH);
      digitalWrite(LED0, HIGH);
      delay(t);
      digitalWrite(2, LOW);
      digitalWrite(LED0, LOW);
      delay(t);
    }
  }
  else if (SUBID == "Sub2"){
    if (count == 0){
      delay(94);
      delay(s);
      digitalWrite(4, HIGH);
      digitalWrite(LED1, HIGH);
      delay(t);
      digitalWrite(4, LOW);
      digitalWrite(LED1, LOW);
      delay(t);
      count = 1;
    }
    else{
      digitalWrite(4, HIGH);
      digitalWrite(LED1, HIGH);
      delay(t);
      digitalWrite(4, LOW);
      digitalWrite(LED1, LOW);
      delay(t);
    }
    
  }
  else if (SUBID == "Sub3"){
    if (count == 0){
      delay(47);
      delay(2*s);
      digitalWrite(12, HIGH);
      digitalWrite(LED2, HIGH);
      delay(t);
      digitalWrite(12, LOW);
      digitalWrite(LED2, LOW);
      delay(t);
      count = 1;
    }
    else{
      digitalWrite(12, HIGH);
      digitalWrite(LED2, HIGH);
      delay(t);
      digitalWrite(12, LOW);
      digitalWrite(LED2, LOW);
      delay(t);
    }
    
  }
  else if (SUBID == "Sub4"){
    if (count == 0){
      delay(3*s);
      digitalWrite(7, HIGH);
      digitalWrite(LED3, HIGH);
      delay(t);
      digitalWrite(7, LOW);
      digitalWrite(LED3, LOW);
      delay(t);
      count = 1;
    }
    else{
      digitalWrite(7, HIGH);
      digitalWrite(LED3, HIGH);
      delay(t);
      digitalWrite(7, LOW);
      digitalWrite(LED3, LOW);
      delay(t);
    }
  }

  else if (SUBID == "Sub5"){
    xPosition = analogRead(A0);
    yPosition = analogRead(A1);

    printf("x = %d\n", xPosition);
    printf("      y = %d\n", yPosition);

//    delay(100);

//    if (yPosition<700){
//      digitalWrite(8, HIGH);
//    }
//    
    

  //x direction
  if (xPosition < 200){
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  else if (xPosition > 700){
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  else{
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }

//  y direction
  if (yPosition < 200){
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
  else if (yPosition > 700){
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  else{
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  }
}

#else /* MAINCORE */
void setup()
{
  int subid;
  Serial.begin(115200);
  while (!Serial);
  for (subid = 1; subid <= 5; subid++){
    MP.begin(subid);
  }
}

void loop(){
}

#endif
