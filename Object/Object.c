#include "Object.h"

Visual *createVisual(int nLines, int len, ...) 
{
  char **map = (char**)malloc(sizeof (char*) * nLines);

  va_list args;
  va_start(args, len);

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

void deleteVisual(Visual *vsl) 
{
  for (int i = 0; i < vsl->h; i++) 
  {
    free(vsl->map[i]);
  }
  free(vsl->map);
  free(vsl);
}

Object *createObject(Visual *vsl, int y, int x) 
{
  Object *obj = (Object*)malloc(sizeof (Object));

  obj->vsl = vsl;
  obj->y = y;
  obj->x = x;

  return obj;
}

void deleteObject(Object *obj) 
{
  deleteVisual(obj->vsl);
  free(obj);
}

