#include <ezButton.h>

ezButton tSwitch_1(4);
ezButton tSwitch_2(7);
int red_1 = 2;
int green_1 = 3;
int red_2 = 6;
int green_2 = 5;
bool ani = false;
int anicount = 0;

void setup() {
  Serial.begin(9600);
  tSwitch_1.setDebounceTime(50);
  tSwitch_2.setDebounceTime(50);
  pinMode(red_1, OUTPUT);
  pinMode(green_1, OUTPUT);
  pinMode(red_2, OUTPUT);
  pinMode(green_2, OUTPUT);
}

void loop() {
  tSwitch_1.loop();
  tSwitch_2.loop();
  int state1 = tSwitch_1.getState();
  int state2 = tSwitch_2.getState();
  
  if(state1 == HIGH && ani == false){
    digitalWrite(green_1, LOW);
    digitalWrite(red_1, HIGH);
    Serial.println("RED1 ON");
  }else if(state1 == LOW && ani == false){
    digitalWrite(green_1, HIGH);
    digitalWrite(red_1, LOW);
    Serial.println("GREEN1 ON");
  }
  if(state2 == HIGH && ani == false){
    digitalWrite(green_2, LOW);
    digitalWrite(red_2, HIGH);
    Serial.println("RED2 ON");
  }else if(state2 == LOW && ani == false){
    digitalWrite(green_2, HIGH);
    digitalWrite(red_2, LOW);
    Serial.println("GREEN2 ON");
  }

  if(((state1 == LOW && state2 == LOW) || ani == true) && anicount < 5) {
    animation();
    ani = true;
    anicount++;
  }
  if(state1 == HIGH && state2 == HIGH) {
    ani = false;
    anicount = 0;
  }
}

void animation() {
  Serial.println("Animation");
  delay(1000);
  digitalWrite(green_1, LOW);
  digitalWrite(red_1, LOW);
  digitalWrite(green_2, LOW);
  digitalWrite(red_2, LOW);
  delay(500);
  digitalWrite(green_1, HIGH);
  digitalWrite(red_1, HIGH);
  digitalWrite(green_2, HIGH);
  digitalWrite(red_2, HIGH);
  delay(500);
  digitalWrite(green_1, LOW);
  digitalWrite(red_1, LOW);
  digitalWrite(green_2, LOW);
  digitalWrite(red_2, LOW);
  delay(500);
  digitalWrite(green_1, HIGH);
  digitalWrite(red_1, HIGH);
  digitalWrite(green_2, HIGH);
  digitalWrite(red_2, HIGH);
  delay(500);
  digitalWrite(green_1, LOW);
  digitalWrite(red_1, LOW);
  digitalWrite(green_2, LOW);
  digitalWrite(red_2, LOW);
  delay(500);
}
//
//int switch_pin = 4;
//int led_pin = 2;
//
//void setup() {
//  pinMode(switch_pin, INPUT);
//  pinMode(led_pin, OUTPUT);
//}
//
//void loop() {
//  if(digitalRead(switch_pin) == HIGH){
//    digitalWrite(led_pin, LOW);
//  }
//  if(digitalRead(switch_pin) == LOW){
//    digitalWrite(led_pin, HIGH);
//  }
//
//}
