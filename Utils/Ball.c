#include "Utils.h"

Object *createBall(int y, int x) 
{
  char half_ball[5];
  half_ball[0] = (char)BLOCK;
  half_ball[1] = (char)BLOCK;
  half_ball[2] = (char)BLOCK;
  half_ball[3] = (char)BLOCK;
  half_ball[4] = '\0';
 
  Visual *ballVisual = createVisual(2, 4, half_ball, half_ball);
  Object *ball = createObject(ballVisual, y, x);
  ball->velocityY = random_sign();
  ball->velocityX = random_sign();

  return ball;
}

void topBottomCollision(Object *ball, int maxY) 
{
  int centerBallPosY = getCenterPos(ball->y, ball->vsl->h);

  if (centerBallPosY <= 1 || centerBallPosY >=  (maxY - 1)) 
  {
    ball->velocityY *= -1;
  }
}

void leftRightCollision(Object *ball, Object *leftPaddle, Object *rightPaddle, int maxY) 
{
  int centerBallPosX = getCenterPos(ball->x, ball->vsl->w);
  int centerBallPosY = getCenterPos(ball->y, ball->vsl->h);

  int leftPaddleCollisionCenterPosX = getCenterPos(leftPaddle->x, leftPaddle->vsl->w) + 1;
  int leftPaddleTopPos = leftPaddle->y;
  int leftPaddleBottomPos = leftPaddle->y;

  int rightPaddleCollisionCenterPosX = getCenterPos(rightPaddle->x, rightPaddle->vsl->w) + 1;
  int rightPaddleTopPos = rightPaddle->y;
  int rightPaddleBottomPos = rightPaddle->y;

  if (centerBallPosX <= (leftPaddleCollisionCenterPosX + 3)) 
  {
    if (centerBallPosY >= leftPaddle->y && centerBallPosY <= leftPaddle->y + leftPaddle->vsl->h)
    {
      ball->velocityX *= -1;
    }
    else 
    {
      usleep(500000);
      ball->y = getCenterPos(rightPaddle->y, rightPaddle->vsl->h);
      ball->x = rightPaddle->x - 6;
      ball->velocityX = -1;
      ball->velocityY = random_sign();
    }
  }
  else if (centerBallPosX >= (rightPaddleCollisionCenterPosX - 5)) 
  {
    if (centerBallPosY >= rightPaddle->y && centerBallPosY <= rightPaddle->y + rightPaddle->vsl->h)
    {
      ball->velocityX *= -1;
    }
    else 
    {
      usleep(500000);
      ball->y = getCenterPos(leftPaddle->y, leftPaddle->vsl->h);
      ball->x = leftPaddle->x + 5;
      ball->velocityX = 1;
      ball->velocityY = random_sign();    
    }
  }
}

void updateBall(Object *ball, int maxY, Object *leftPaddle, Object *rightPaddle) 
{
  updatePositionObject(ball);
  printObject(ball);
}

void handleBall(Object *ball, int maxY, Object *leftPaddle, Object *rightPaddle) 
{
  topBottomCollision(ball, maxY);
  leftRightCollision(ball, leftPaddle, rightPaddle, maxY);
}