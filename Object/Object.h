#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

typedef struct object 
{
  char *visual;
  int y;
  int x;
  int length;
  int heigth;
} Object;

Object *createObject(char *visl, int y, int x);

void deleteObject(Object *obj);