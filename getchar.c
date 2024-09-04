#include "getchar.h"
#include <unistd.h>  // For read()
#include <stdio.h>   // For getchar()

// Function to disable canonical mode (which waits for Enter)
void disableCanonicalMode(struct termios *oldt) {
    struct termios newt;
    tcgetattr(STDIN_FILENO, oldt);            // Get current terminal attributes
    newt = *oldt;                             // Make a copy of attributes
    newt.c_lflag &= ~(ICANON | ECHO);         // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Set new terminal attributes
}

// Function to restore terminal settings
void restoreCanonicalMode(struct termios *oldt) {
    tcsetattr(STDIN_FILENO, TCSANOW, oldt);  // Restore old terminal settings
}

// Function to get a character without pressing Enter
char getCharWithoutEnter() {
    struct termios oldt;
    disableCanonicalMode(&oldt);  // Disable canonical mode
    
    char ch = getchar();          // Read a single character
    
    restoreCanonicalMode(&oldt);  // Restore the terminal settings
    return ch;
}