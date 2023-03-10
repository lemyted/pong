#include "../Object/Object.h"
#include <ncursesw/ncurses.h>
#include <locale.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h>   // for time()
#include <unistd.h>
#include <pthread.h>

#define ENTER 10
#define UP_ARROW 259
#define DOWN_ARROW 258

// Helper
void initConf();

void printObject(Object *obj);

int random_sign();

void updatePositionObject(Object *obj);

void handlePaddles(int *running, Object *ball, Object *leftPaddle, Object *rightPaddle);

pthread_t *createThread();

// Ball
Object *createBall(int y, int x);

void topBottomCollision(Object *ball, int maxY);

void leftRightCollision(Object *ball, Object *leftPaddle, Object *rightPaddle, int maxY);

void updateBall(Object *ball, int maxY, Object *leftPaddle, Object *rightPaddle);

void reverseVelocity(Object *obj);

void handleBall(Object *ball, int maxY, Object *leftPaddle, Object *rightPaddle);

// Paddle
Object *createPaddle(int y, int x);

void updatePaddles(Object *leftPaddle, Object *rightPaddle, int maxY);

// Inputs
typedef struct inputs
{
  int maxY;
  int maxX;
  int running;
  Object *ball;
  Object *leftPaddle;
  Object *rightPaddle;
}Inputs;

Inputs *createInputs(int maxY, int maxX, Object *ball, Object *leftPaddle, Object *rightPaddle);

void deleteInputs(Inputs *in);