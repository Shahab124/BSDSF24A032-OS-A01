#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    char buf[100];

    printf("mystrlen(Hello) = %d\n", mystrlen("Hello"));

    mystrcpy(buf, "Hello");
    printf("mystrcpy: %s\n", buf);

    mystrncpy(buf, "Operating Systems", 9);
    printf("mystrncpy: %s\n", buf);

    mystrcpy(buf, "Hello");
    mystrcat(buf, " World");
    printf("mystrcat: %s\n", buf);

    printf("\n--- Testing File Functions ---\n");
    FILE* fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Could not open test.txt\n");
        return 1;
    }

    int lines, words, chars;
    wordCount(fp, &lines, &words, &chars);
    printf("wordCount: %d lines, %d words, %d chars\n", lines, words, chars);

    rewind(fp);

    char** matches;
    int n = mygrep(fp, "os", &matches);
    printf("mygrep found %d lines with 'os':\n", n);
    for (int i = 0; i < n; i++) {
        printf("  %s", matches[i]);
        free(matches[i]);
    }
    free(matches);

    fclose(fp);
    return 0;
}
