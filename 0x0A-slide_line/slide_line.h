#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>
#include <ctype.h>
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 0

int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */
