OBJECT=Object/Object.c
OBJECT_TEST=Object/*.c
HELPER=Utils/Helper.c
BALL=Utils/Ball.c
PADDLE=Utils/Paddle.c
INPUTS=Utils/Inputs.c

main:
	gcc main.c $(OBJECT) $(HELPER) $(BALL) $(PADDLE) $(INPUTS) -o pong -lncursesw -lpthread

debug:
	gcc main.c $(OBJECT) $(HELPER) $(BALL) $(PADDLE) $(INPUTS) -o pong -lncursesw -lpthread -g
	gdb --args ./pong

test_Object:
	gcc $(OBJECT_TEST) -o ObjectTest -lcunit -lncurses
	./ObjectTest