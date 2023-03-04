#include "Object.h"

int getLength(char *str) 
{
  int l = 0;
  int lastRecordedL = 0;

  for (int i = 0; str[i] != '\0'; i++) 
  {
    if (str[i] != '\n') 
    { 
      l++;  
    }
    else 
    {
      if (l > lastRecordedL) 
      {
        lastRecordedL = l;
      }
      l = 1;
    }  
  }

  return lastRecordedL; 
}

int getHeigth(char *str) 
{
  int h = 0;

  if (strlen(str) > 0) 
  {
    h = 1;
  }

  for (int i = 0; str[i] != '\0'; i++) 
  {
    if (str[i] == '\n') { h++; }
  }

  return h;
}

Object *createObject(char *visl, int y, int x) 
{
  int len = strlen(visl);
  Object *obj = (Object*)malloc(sizeof (Object));
  obj->visual = (char*)malloc(sizeof (char) * (len + 1));

  if (visl[len] != '\0') { visl[len] = '\0'; }

  strcpy(obj->visual, visl);
  obj->y = y;
  obj->x = x;
  obj->length = getLength(obj->visual);
  obj->heigth = getHeigth(obj->visual);

  return obj;
}

void deleteObject(Object *obj) 
{
  free(obj->visual);
  free(obj);
}

