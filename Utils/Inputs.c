#include "Utils.h"

Inputs *createInputs(int maxY, int maxX, Object *ball, Object *leftPaddle, Object *rightPaddle) 
{
  Inputs *in = (Inputs*)malloc(sizeof (Inputs));
  in->running = 1;
  in->maxY = maxY;
  in->maxX = maxX;
  in->ball = ball;
  in->leftPaddle = leftPaddle;
  in->rightPaddle = rightPaddle;
}

void deleteInputs(Inputs *in) 
{
  deleteObject(in->ball);
  deleteObject(in->leftPaddle);
  deleteObject(in->rightPaddle);
  free(in);
}