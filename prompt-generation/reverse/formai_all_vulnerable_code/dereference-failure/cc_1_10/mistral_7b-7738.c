//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINE_LENGTH 80
#define NUM_LINES 10

void printLine(char *str) {
    printf("%s\n", str);
}

char *generateRandomString(int length) {
    char *str = (char *)malloc(length * sizeof(char));
    int i;
    for (i = 0; i < length; i++) {
        str[i] = 65 + rand() % 26;
    }
    str[length] = '\0';
    return str;
}

int main() {
    clock_t start, end;
    double time_spent;
    int i, j;
    char *lines[NUM_LINES];

    srand(time(NULL));

    for (i = 0; i < NUM_LINES; i++) {
        lines[i] = generateRandomString(LINE_LENGTH);
    }

    start = clock();

    for (i = 0; i < NUM_LINES; i++) {
        for (j = 0; j < LINE_LENGTH; j++) {
            putchar(lines[i][j]);
            fflush(stdout);
        }
        printf("\n");
    }

    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nYou typed %d characters in %.2fs!\n", LINE_LENGTH * NUM_LINES, time_spent);

    for (i = 0; i < NUM_LINES; i++) {
        free(lines[i]);
    }

    return 0;
}