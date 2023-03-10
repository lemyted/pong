#include "Utils.h"

Object *createPaddle(int y, int x) 
{
  char paddle_fraction[3];
  paddle_fraction[0] = (char)BLOCK;
  paddle_fraction[1] = (char)BLOCK;
  paddle_fraction[2] = '\0';
 
  Visual *paddleVisual = createVisual(8, 2, paddle_fraction, 
    paddle_fraction,
    paddle_fraction,
    paddle_fraction,
    paddle_fraction,
    paddle_fraction,
    paddle_fraction,
    paddle_fraction, 
    paddle_fraction);
  Object *paddle = createObject(paddleVisual, y, x);
  paddle->velocityY = 0;
  paddle->velocityX = 0;

  return paddle;
}

void updatePaddles(Object *leftPaddle, Object *rightPaddle, int maxY) 
{
  updatePositionObject(leftPaddle);
  updatePositionObject(rightPaddle);
  printObject(leftPaddle);
  printObject(rightPaddle);
}