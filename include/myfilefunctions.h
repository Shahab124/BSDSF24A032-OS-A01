#ifndef MYFILEFUNCTIONS_H
#define MYFILEFUNCTIONS_H

#include <stdio.h>

// Count lines, words and characters in the file. Return 0 on success, -1 on failure.
int wordCount(FILE* file, int* lines, int* words, int* chars);

// Find lines containing search_str, fill the matches array. Return match count, or -1 on failure.
int mygrep(FILE* fp, const char* search_str, char*** matches);

#endif
