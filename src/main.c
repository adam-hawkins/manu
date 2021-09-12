#include <ncurses.h>
#include <c/c.h>
#include <python/python.h>
#include <kotlin/kotlin.h>
#include <go/go.h>
#include <stdio.h>

#define ENTER 10

int menu_down(int i) {
  i++;
  return (i > 4) ? 0 : i;
}

int menu_up(int i) {
  i--;
  return (i < 0) ? 4 : i;
}

int main() {
  WINDOW *w;
  char* list[5] = { "C/C++", "Go", "Python", "Kotlin" };
  char item[7];
  int ch, i = 0;
  initscr(); // initialize Ncurses
  w = newwin( 10, 12, 1, 1 ); // create a new window
  box( w, 0, 0 ); // sets default borders for the window
  // now print all the menu items and highlight the first one
  for( i=0; i<5; i++ ) {
      if( i == 0 )
          wattron( w, A_STANDOUT ); // highlights the first item.
      else
          wattroff( w, A_STANDOUT );
  
      sprintf(item, "%-1s",  list[i]);
      mvwprintw( w, i+1, 2, "%s", item );
  }
  
  wrefresh( w ); // update the terminal screen
  i = 0;
  noecho(); // disable echoing of characters on the screen
  keypad( w, TRUE ); // enable keyboard input for the window.
  curs_set( 0 ); // hide the default screen cursor.
  // get the input
  int kill = 0;
  ch = wgetch(w);
  
  while(!kill) {
      // right pad with spaces to make the items appear with even width.
      sprintf(item, "%-1s",  list[i]);
      mvwprintw( w, i+1, 2, "%s", item );
  
      // use a variable to increment or decrement the value based on the input.
      switch( ch ) {
        // up keys
          case KEY_UP:
              i = menu_up(i);
              break;
          case 'w':
              i = menu_up(i);
              break;
          case 'k':
              i = menu_up(i);
              break;
        // down keys
          case KEY_DOWN:
              i = menu_down(i);
              break;
          case 's':
              i = menu_down(i);
              break;
          case 'j':
              i = menu_down(i);
              break;
          case ENTER:
              kill = 1;
              break;
  
          default:
              break;
      }
  
      if (kill) {
          break;
      }
  
      // now highlight the next item in the list.
      wattron( w, A_STANDOUT );
      sprintf(item, "%-1s",  list[i]);
      mvwprintw( w, i+1, 2, "%s", item);
      wattroff( w, A_STANDOUT );
      ch = wgetch(w);
  }
  
  delwin( w );
  endwin();
  
  switch ( i ) {
    case 0:
      create_c_project();
      break;
    case 1:
      create_go_project();
      break;
    case 2:
      create_python_project();
      break;
    case 3:
      create_kotlin_project();
      break;

    default:
      printf("nada\n");
      break;

  }

  return 0;

}
