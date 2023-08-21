/** pex1.c
 * =============================================================
 * Name: Your Name
 * Section:  Your Section
 * Project:  FILL IN
 * Purpose:  FILL IN
 * Documentation Statement:  FILL IN
 * ============================================================= */

// Includes and defines
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define REQUIRED_HEIGHT 32
#define REQUIRED_WIDTH 80

// Functions

/** DO NOT ALTER THIS FUNCTION ************************************
 * @brief checks to ensure that the shell window is the correct size
 * of 32x80 rows and columns.  Exits after printing error message or
 * retuns without issue if the size is correct.
 * @return nothing
*/
void checkSize() {
    system("echo -ne '\e[8;32;80t'");   // Be sure to run PEX outside of VSC in
                                        // a dedicated terminal window.
    sleep(1);   // Wait for resize  
    initscr();  // Start curses mode and check to ensure window is 32x80   
    if (COLS != REQUIRED_WIDTH || LINES != REQUIRED_HEIGHT) {
        move(3, 10);
        printw("Do not run PEX1 in VSC's builtin terminal!\n");
        move(1, 1);
        printw("This window is %d columns wide ", COLS);
        printw("BUT it should be %d", REQUIRED_WIDTH);
        move(2, 2);
        printw("This window is %d lines high, ", LINES);
        printw("BUT should be %d", LINES, REQUIRED_HEIGHT);
    refresh();
        refresh();
        sleep(8);
        endwin();
        exit(1);
    }
}

// Main
int main() {
    // Do not remove this function call
    checkSize();

    // the following lines are for demonstration
    // puposes only. Remove prior to submission
    move(2, 2);
    printw("This window is %d columns wide", COLS);
    move(4, 4);
    printw("This window is %d lines high", LINES);
    move(6, 6);
    printw("This window will close automatically");
    refresh();
    // Delay a few seconds
    sleep(6);
    // >>>>>>>>>>>> end demonstration code

    endwin();  // End curses mode
    return 0;
}
