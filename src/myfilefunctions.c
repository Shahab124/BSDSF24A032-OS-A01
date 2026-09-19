#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myfilefunctions.h"
#include "../include/mystrfunctions.h"

#define MAX_MATCHES 100

int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (file == NULL)
        return -1;

    int l = 0, w = 0, c = 0;
    int inWord = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF) {
        c++;

        if (ch == '\n')
            l++;

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            w++;
        }
    }

    *lines = l;
    *words = w;
    *chars = c;
    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (fp == NULL)
        return -1;

    char** list = malloc(MAX_MATCHES * sizeof(char*));
    if (list == NULL)
        return -1;

    char line[1024];
    int count = 0;

    while (fgets(line, 1024, fp) != NULL && count < MAX_MATCHES) {
        if (strstr(line, search_str) != NULL) {
            list[count] = malloc(mystrlen(line) + 1);
            mystrcpy(list[count], line);
            count++;
        }
    }

    *matches = list;
    return count;
}
