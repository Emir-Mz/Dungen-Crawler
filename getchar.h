#ifndef GETCHAR_H
#define GETCHAR_H

#include <termios.h>  // For termios

void disableCanonicalMode(struct termios *oldt);
void restoreCanonicalMode(struct termios *oldt);
char getCharWithoutEnter();

#endif // GETCHAR_H