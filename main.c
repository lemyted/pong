#include <ncurses.h>

/* 
ball
/¯ ¯\
\_ _/
*/



char ball[] = "/¯ ¯\\\n\\_ _/";

int main(int argc, char *argv[]) 
{
  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE);

  printw("Hello word!");
  refresh();
  getch();
  endwin();
}