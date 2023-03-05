#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>
#include <wchar.h>

typedef struct visual
{
  char **map;
  int h;
  int w;
} Visual;

Visual *createVisual(int nLines, int len, ...);

void deleteVisual(Visual *vsl);


typedef struct object 
{
  Visual *vsl;
  int y;
  int x;
} Object;

Object *createObject(Visual *vsl, int y, int x);

void deleteObject(Object *obj);