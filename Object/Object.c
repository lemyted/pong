#include "Object.h"

Visual *createVisual(int nLines, int len, ...) 
{
  char **map = (char**)malloc(sizeof (char*) * nLines);

  va_list args;
  va_start(args, nLines);

  for (int i = 0; i < nLines; i++) 
  {
    char *arg = va_arg(args, char *);
    int len = strlen(arg);
    map[i] = (char*)malloc(sizeof (char) * (len + 1));
    strcpy(map[i], arg);
  }
  
  va_end(args);

  Visual *vsl = (Visual*)malloc(sizeof (Visual));
  vsl->map = map;
  vsl->h = nLines;
  vsl->w = len;

  return vsl;
}

Object *createObject(Visual *vsl, int y, int x) 
{
  // int len = strlen(visl);
  Object *obj = (Object*)malloc(sizeof (Object));
  // obj->visual = (char*)malloc(sizeof (char) * (len + 1));

  // if (visl[len] != '\0') { visl[len] = '\0'; }

  // strcpy(obj->visual, visl);
  // obj->y = y;
  // obj->x = x;
  // obj->length = getLength(obj->visual);
  // obj->heigth = getHeigth(obj->visual);

  return obj;
}

void deleteObject(Object *obj) 
{
  // free(obj->visual);
  free(obj);
}

