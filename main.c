#include <ncurses.h>

void initConf() 
{
  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE);
}

int main(int argc, char *argv[]) 
{
  char ball[] = "/¯ ¯\\\n\\_ _/";

  initConf();

  int w, h;
  getmaxyx(stdscr, h, w);
  // printw("h : %d, w : %d", h, w);
  refresh();

  for(;;) 
  {
    mvprintw(h / 2, w / 2, ball);
    refresh();

    if (getch() == 10 /* ENTER */) 
    {
      break;
    }
  }

  endwin();
}