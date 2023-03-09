#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>
#include <wchar.h>

#define HALF_BALL "\u2588\u2588\u2588\u2588\0"
#define HALF_BALL_LEN 4

#define EIGHTH_PADDLE "\u2588\u2588\0"
#define EIGHTH_PADDLE_LEN 2

#define getCenterPos(pos, size) ((pos + (size)) - (size / 2))
#define setCenterPos(centerPos, size) ((centerPos) - (size / 2))

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
 