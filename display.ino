#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "SPI.h"
#include "display.h"
#include "ball.h"
#include "paddle.h"

//int potPin = A0; // Connect wiper to A0
int potValue;
int nextPotValue;

//MILLIS
unsigned long prevTime1 = 0, prevTime2 = 0;
const long interval1 = 1, interval2 = 1;

Display displayTest;
Ball ball(100, 100, 5, ILI9341_WHITE);
Paddle paddle1(15, 30, 0xF800);

void move_ball() {
      display.setRotation(0);
      ball.bounce(paddle1);
      displayTest.drawprevBall(ball);
      displayTest.drawBall(ball);
      if (ball.getColl(paddle1)) {
        display.setRotation(1);
        int new_score = paddle1.updatescore();
        displayTest.displayScore(paddle1);
        Serial.print(paddle1.getscore());
        //display.write("scored");
        display.setRotation(0);
      }
}

void move_paddle() {
        potValue = paddle1.getpotValue();
      //Serial.println(potValue);
      delay(1);
      nextPotValue = paddle1.getpotValue();
      
      if(nextPotValue>potValue) {
      displayTest.drawPaddle(paddle1, potValue);
      display.fillRect(0, potValue-30, 15, 30, 0x0000);
      } else if(nextPotValue<potValue) {
      displayTest.drawPaddle(paddle1, potValue);
      display.fillRect(0, potValue+30, 15, 30, 0x0000);
      }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  displayTest.init();
  displayTest.openingScreen();
  displayTest.displayScore(paddle1);
  int pos = ball.getx();
  //Serial.println(pos);
  //displayTest.drawBall(ball);
  Serial.print(displayTest.getw());
  Serial.print(displayTest.geth());


}

void loop() {
    unsigned long currentTime = millis();

  if (currentTime - prevTime1 >= interval1) {  // Task 1 runs every 1s
      prevTime1 = currentTime;
      move_ball();
  }

  if (currentTime - prevTime2 >= interval2) {  // Task 2 runs every 1s
      prevTime2 = currentTime;
move_paddle();
  }
  if (ball.timess()==5) {
    displayTest.closingScreen();
    ball.restart();
  }


}
