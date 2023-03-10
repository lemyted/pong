#include "Utils/Utils.h"

#define REFRESH_RATE 1000000 / 24
#define leftBorder 4
#define rightBorder(max_x) ((max_x) - 6)

void *threadHandlePaddles(void *x) 
{
  Inputs *in = (Inputs*)x;

  while(in->running) 
  {
    handlePaddles(&(in->running), in->ball, in->leftPaddle, in->rightPaddle);
    usleep(10000);
  }

  int ret;
  pthread_exit(&ret);
}

int main(int argc, char *argv[]) 
{
  initConf();

  int maxX, maxY;
  getmaxyx(stdscr, maxY, maxX);
  mvprintw(0, 0, "max y: %d", maxY);

  Object *ball = createBall(maxY / 2, maxX / 2);
  Object *leftPaddle = createPaddle(1, leftBorder);
  Object *rightPaddle = createPaddle(maxY - 2, rightBorder(maxX));

  leftPaddle->y = setCenterPos(maxY / 2, leftPaddle->vsl->h);
  rightPaddle->y = setCenterPos(maxY / 2, rightPaddle->vsl->h);
  
  Inputs *inputs = createInputs(maxY, maxX, ball, leftPaddle, rightPaddle); 
  pthread_t *threadPaddles = createThread();
  pthread_t *threadBall = createThread();

  pthread_create(threadPaddles, NULL, threadHandlePaddles, inputs);
  
  while(inputs->running) 
  {
    handleBall(ball, maxY, leftPaddle, rightPaddle);
    updateBall(ball, maxY, leftPaddle, rightPaddle);
    updatePaddles(leftPaddle, rightPaddle, maxY);
    usleep(REFRESH_RATE);
    refresh();
    clear();
  }

  deleteInputs(inputs);
  free(threadPaddles);
  free(threadBall);
  endwin();
}