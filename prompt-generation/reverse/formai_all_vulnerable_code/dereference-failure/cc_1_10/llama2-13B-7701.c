//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_PATTERN_LEN 20
#define MAX_PRINT_LEN 100

void printPattern(char pattern[MAX_PATTERN_LEN]) {
    int i, j, k;
    char currentChar, nextChar;

    for (i = 0; i < MAX_PATTERN_LEN; i++) {
        currentChar = pattern[i];
        nextChar = pattern[i + 1];

        if (currentChar == 'A') {
            if (nextChar == 'B') {
                for (j = 0; j < 3; j++) {
                    putchar('C');
                }
            } else if (nextChar == 'C') {
                for (j = 0; j < 2; j++) {
                    putchar('D');
                }
            }
        } else if (currentChar == 'B') {
            if (nextChar == 'A') {
                for (j = 0; j < 3; j++) {
                    putchar('E');
                }
            } else if (nextChar == 'C') {
                for (j = 0; j < 2; j++) {
                    putchar('F');
                }
            }
        } else if (currentChar == 'C') {
            if (nextChar == 'B') {
                for (j = 0; j < 3; j++) {
                    putchar('G');
                }
            } else if (nextChar == 'A') {
                for (j = 0; j < 2; j++) {
                    putchar('H');
                }
            }
        }
    }
}

int main() {
    char pattern[MAX_PATTERN_LEN];
    int len;

    srand(time(NULL));

    printf("Enter a pattern (up to %d characters): ", MAX_PATTERN_LEN);
    fgets(pattern, MAX_PATTERN_LEN, stdin);

    len = strlen(pattern);

    printPattern(pattern);

    return 0;
}