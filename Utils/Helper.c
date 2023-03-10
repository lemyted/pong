#include "Utils.h"

void initConf() 
{
  initscr();
  raw();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
}

void printObject(Object *obj) 
{
  for (int i = 0; i < obj->vsl->h; i++) 
  {
    mvaddstr(obj->y + i, obj->x, obj->vsl->map[i]);
  }
}

int random_sign() {
    static int initialized = 0;
    if (!initialized) {
        srand(time(NULL)); // seed the random number generator with the current time
        initialized = 1;
    }

    return (rand() % 2 == 0) ? 1 : -1; // return either 1 or -1 randomly
}


void updatePositionObject(Object *obj) 
{
  obj->y += obj->velocityY;
  obj->x += obj->velocityX;
}

void reverseVelocity(Object *obj) 
{
  obj->velocityX *= -1;
  obj->velocityY *= -1;
}

void handlePaddles(int *running, Object *ball, Object *leftPaddle, Object *rightPaddle) 
{
  int key = getch();
  if (key == ENTER) { *running = 0; }
  if (key == UP_ARROW) { leftPaddle->y -= 2; }
  if (key == DOWN_ARROW) { leftPaddle->y += 2; }
}

pthread_t *createThread() 
{
  return (pthread_t*)malloc(sizeof (pthread_t));
}

