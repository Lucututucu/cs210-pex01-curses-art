/** pex1.c
 * =============================================================
 * Name: Lucas Briggs 23 Aug 2024
 * Section:  T1/2 Kloenne
 * Project:  Pex 01
 * Purpose:  Practice with the curses library and function creation.
 * Documentation Statement:  None
 * ============================================================= */

// Includes and defines
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define REQUIRED_HEIGHT 32
#define REQUIRED_WIDTH 80

#define GREEN_BLACK 1
#define WHITE_BLUE 2
#define BLACK_RED 3
#define WHITE_BLACK 4

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
        printw("BUT should be %d", REQUIRED_HEIGHT);
    refresh();
        refresh();
        sleep(8);
        endwin();
        exit(1);
    }
}

/** 
 * @brief Draws the initials LB at a specified location
 * @param topLine the number of the highest row of the initials
 * @param leftCol the number of the leftmost collumn of the initials
 * @return nothing
 */ 
void applyStamp(int topLine, int leftCol) {
    // Draw the L
    move(topLine, leftCol);
    printw("L");
    move(topLine + 1, leftCol);
    printw("L");
    move(topLine + 2, leftCol);
    printw("U");
    move(topLine + 3, leftCol);
    printw("U");
    move(topLine + 4, leftCol);
    printw("C");
    move(topLine + 5, leftCol);
    printw("C");
    move(topLine + 5, leftCol + 1);
    printw("A");
    move(topLine + 5, leftCol + 2);
    printw("A");
    move(topLine + 5, leftCol + 3);
    printw("S");
    move(topLine + 5, leftCol + 4);
    printw("S");

    // Draw the B
    move(topLine, leftCol + 7);
    printw("B");
    move(topLine, leftCol + 9);
    printw("B");
    move(topLine + 1, leftCol + 7);
    printw("R");
    move(topLine + 1, leftCol + 11);
    printw("R");
    move(topLine + 2, leftCol + 7);
    printw("I");
    move(topLine + 2, leftCol + 9);
    printw("I");
    move(topLine + 3, leftCol + 7);
    printw("G");
    move(topLine + 3, leftCol + 11);
    printw("G");
    move(topLine + 4, leftCol + 7);
    printw("G");
    move(topLine + 4, leftCol + 11);
    printw("G");
    move(topLine + 5, leftCol + 7);
    printw("S");
    move(topLine + 5, leftCol + 9);
    printw("S");
}

/** 
 * @brief Draws a group of ASCII Faces at a specified location
 * @param topLine the number of the highest row of the faces
 * @param leftCol the number of the leftmost collumn of the faces
 * @return nothing
 */ 
void sillyFaces(int topLine, int leftCol) {
    // Draw faces
    move(topLine, leftCol);
    printw(":)");
    move(topLine, leftCol + 4);
    printw(":D");
    move(topLine, leftCol + 8);
    printw(":P");
    move(topLine + 2, leftCol);
    printw("<]:)");
    move(topLine + 2, leftCol + 8);
    printw("o o");
    move(topLine + 3, leftCol + 9);
    printw(">");
    move(topLine + 4, leftCol);
    printw("B)");
    move(topLine + 4, leftCol + 3);
    printw("*O*");
    move(topLine + 4, leftCol + 7);
    printw("\\___/");

}

// Main
int main() {
    // Do not remove this function call
    checkSize();

    // Assign color pairs
    start_color();
    init_pair(GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
    init_pair(WHITE_BLUE, COLOR_WHITE, COLOR_BLUE);
    init_pair(BLACK_RED, COLOR_BLACK, COLOR_RED);
    init_pair(WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
    wbkgd(stdscr, COLOR_PAIR(WHITE_BLACK)); // Sets the standard color

    // Begin drawing with stamp
    attron(COLOR_PAIR(GREEN_BLACK));    // Selects first color pallate
    applyStamp(17, 2);                  // Applies first stamp
    attroff(COLOR_PAIR(GREEN_BLACK));   // De-selects first color pallate
    attron(COLOR_PAIR(WHITE_BLUE));     // Selects second color pallate
    applyStamp(3, 27);                  // Applies second stamp
    attroff(COLOR_PAIR(WHITE_BLUE));    // De-selects first color pallate
    attron(COLOR_PAIR(BLACK_RED));      // Selects third color pallate
    applyStamp(12, 30);                 // Applies third stamp
    attroff(COLOR_PAIR(BLACK_RED));     // De-selects third color pallate

    sillyFaces(15, 60);                 // Calls second function

    // prevent application from ending until keystroke
    move(30,10);                                    // move cursor near bottom of the window
    printw("Created with Curses by Lucas Briggs");  // display a message
    move(31,15);                                    
    printw("Press any key to continue"); 
    getch();                                        // wait for keystroke

    endwin();  // End curses mode
    return 0;
}
