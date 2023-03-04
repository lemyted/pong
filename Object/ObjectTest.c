#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "Object.h"

void test_whenValidArgs_createObject_returnObject(void) 
{
  char str[] = "ooo\nooo";
  char expectedStr[] = "ooo\nooo\0";
  int y = 10;
  int x = 12;
  Object *obj = createObject(str, y,x);
  CU_ASSERT_STRING_EQUAL(obj->visual, expectedStr);
  CU_ASSERT_EQUAL(obj->y, y);
  CU_ASSERT_EQUAL(obj->x, x);
  CU_ASSERT_EQUAL(obj->length, 3);
  CU_ASSERT_EQUAL(obj->heigth, 2);
  free(obj);
}

void test2_whenValidArgs_createObject_returnObject(void) 
{
  char str[] = "ooo\nooo\nooo0";
  char expectedStr[] = "ooo\nooo\nooo0\0";
  int y = 41;
  int x = 43;
  Object *obj = createObject(str, y,x);
  CU_ASSERT_STRING_EQUAL(obj->visual, expectedStr);
  CU_ASSERT_EQUAL(obj->y, y);
  CU_ASSERT_EQUAL(obj->x, x);
  CU_ASSERT_EQUAL(obj->length, 4);
  CU_ASSERT_EQUAL(obj->heigth, 3);
  free(obj);
}

void test3_whenValidArgs_createObject_returnObject(void) 
{
  char str[] = "";
  char expectedStr[] = "\0";
  int y = 151;
  int x = 403;
  Object *obj = createObject(str, y,x);
  CU_ASSERT_STRING_EQUAL(obj->visual, expectedStr);
  CU_ASSERT_EQUAL(obj->y, y);
  CU_ASSERT_EQUAL(obj->x, x);
  CU_ASSERT_EQUAL(obj->length, 0);
  CU_ASSERT_EQUAL(obj->heigth, 0);
  free(obj);
}

int main(void) 
{
  CU_initialize_registry();

  CU_pSuite createObject = CU_add_suite("createObject", NULL, NULL);
  CU_add_test(createObject, "test_whenValidArgs_createObject_returnObject", test_whenValidArgs_createObject_returnObject);
  CU_add_test(createObject, "test2_whenValidArgs_createObject_returnObject", test2_whenValidArgs_createObject_returnObject);
  CU_add_test(createObject, "test3_whenValidArgs_createObject_returnObject", test3_whenValidArgs_createObject_returnObject);

  CU_basic_run_tests();
  CU_cleanup_registry();
}