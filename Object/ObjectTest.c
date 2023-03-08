#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "Object.h"

void test_whenValidArgs_createVisual_returnVisualBall(void) 
{
  printf("\n%s\n", HALF_BALL);
  printf("%s\n", HALF_BALL);

  Visual *vsl = createVisual(2, HALF_BALL_LEN, HALF_BALL, HALF_BALL);
  CU_ASSERT_EQUAL(vsl->h, 2);
  CU_ASSERT_EQUAL(vsl->w, HALF_BALL_LEN);
  CU_ASSERT_STRING_EQUAL(vsl->map[0], HALF_BALL);
  CU_ASSERT_STRING_EQUAL(vsl->map[1], HALF_BALL);
  deleteVisual(vsl);
}

void test_whenValidArgs_createVisual_returnVisualPaddle(void) 
{
  printf("\n%s\n", EIGHTH_PADDLE);
  printf("%s\n", EIGHTH_PADDLE);
  printf("%s\n", EIGHTH_PADDLE);
  printf("%s\n", EIGHTH_PADDLE);
  printf("%s\n", EIGHTH_PADDLE);
  printf("%s\n", EIGHTH_PADDLE);
  printf("%s\n", EIGHTH_PADDLE);
  printf("%s\n", EIGHTH_PADDLE);

  Visual *vsl = createVisual(2, EIGHTH_PADDLE_LEN, 
    EIGHTH_PADDLE, 
    EIGHTH_PADDLE, 
    EIGHTH_PADDLE, 
    EIGHTH_PADDLE, 
    EIGHTH_PADDLE, 
    EIGHTH_PADDLE, 
    EIGHTH_PADDLE, 
    EIGHTH_PADDLE
  );
  CU_ASSERT_EQUAL(vsl->h, 8);
  CU_ASSERT_EQUAL(vsl->w, EIGHTH_PADDLE_LEN);
  CU_ASSERT_STRING_EQUAL(vsl->map[0], EIGHTH_PADDLE);
  CU_ASSERT_STRING_EQUAL(vsl->map[7], EIGHTH_PADDLE);
  deleteVisual(vsl);
}

void test_whenValidVisual_deleteVisual_visualDeleted(void) 
{
  Visual *vsl = createVisual(2, HALF_BALL_LEN, HALF_BALL, HALF_BALL);
  deleteVisual(vsl);
  CU_ASSERT_NOT_EQUAL(vsl->h, 2);
  CU_ASSERT_NOT_EQUAL(vsl->w, HALF_BALL_LEN);
  CU_ASSERT_STRING_NOT_EQUAL(vsl->map[0], HALF_BALL);
  CU_ASSERT_STRING_NOT_EQUAL(vsl->map[1], HALF_BALL);
}

void test_whenValidArgs_createObject_returnObject(void) 
{
  int y = 10;
  int x = 12;
  Visual *vsl = createVisual(2, HALF_BALL_LEN, HALF_BALL, HALF_BALL);
  Object *obj = createObject(vsl, y,x);
  CU_ASSERT_STRING_EQUAL(obj->vsl->map[0], HALF_BALL);
  CU_ASSERT_STRING_EQUAL(obj->vsl->map[1], HALF_BALL);
  CU_ASSERT_EQUAL(obj->y, y);
  CU_ASSERT_EQUAL(obj->x, x);
  CU_ASSERT_EQUAL(obj->vsl->w, HALF_BALL_LEN);
  CU_ASSERT_EQUAL(obj->vsl->h, 2);
  deleteObject(obj);
}

void test_whenValidObject_deleteObject_objectDeleted(void) 
{
  int y = 10;
  int x = 12;
  Visual *vsl = createVisual(2, HALF_BALL_LEN, HALF_BALL, HALF_BALL);
  Object *obj = createObject(vsl, y,x);
  deleteObject(obj);
  CU_ASSERT_STRING_NOT_EQUAL(obj->vsl->map[0], HALF_BALL);
  CU_ASSERT_STRING_NOT_EQUAL(obj->vsl->map[1], HALF_BALL);
  CU_ASSERT_NOT_EQUAL(obj->y, y);
  CU_ASSERT_NOT_EQUAL(obj->x, x);
  CU_ASSERT_NOT_EQUAL(obj->vsl->w, HALF_BALL_LEN);
  CU_ASSERT_NOT_EQUAL(obj->vsl->h, 2);
}

int main(void) 
{
  CU_initialize_registry();

  CU_pSuite createVisual = CU_add_suite("createVisual", NULL, NULL);
  CU_add_test(createVisual, "test_whenValidArgs_createVisual_returnVisualBall", test_whenValidArgs_createVisual_returnVisualBall);
  CU_add_test(createVisual, "test_whenValidArgs_createVisual_returnVisualPaddle", test_whenValidArgs_createVisual_returnVisualPaddle);

  CU_pSuite deleteVisual = CU_add_suite("deleteVvisual", NULL, NULL);
  CU_add_test(createVisual, "test_whenValidVisual_deleteVisual_visualDeleted", test_whenValidVisual_deleteVisual_visualDeleted);

  CU_pSuite createObject = CU_add_suite("createObject", NULL, NULL);
  CU_add_test(createObject, "test_whenValidArgs_createObject_returnObject", test_whenValidArgs_createObject_returnObject);

  CU_pSuite deleteObject = CU_add_suite("deleteObject", NULL, NULL);
  CU_add_test(deleteObject, "test_whenValidObject_deleteObject_objectDeleted", test_whenValidObject_deleteObject_objectDeleted);
  
  CU_basic_run_tests();
  CU_cleanup_registry();
}