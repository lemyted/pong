OBJECT=Object/Object.c
OBJECT_TEST=Object/*.c

main:
	gcc main.c -o pong -lncurses

test_Object:
	gcc $(OBJECT_TEST) -o ObjectTest -lcunit -lncurses
	./ObjectTest

debug_test_Object:
	gcc $(OBJECT_TEST) -g -o ObjectTest -lcunit -lncurses
	gdb --args ./ObjectTest