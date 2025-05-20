//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define NUM_STRINGS 10

void generateString(char* str) {
    int i;
    for (i = 0; i < MAX_STRING_LENGTH; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[MAX_STRING_LENGTH] = '\0';
}

int main() {
    int i, j, k;
    char strings[NUM_STRINGS][MAX_STRING_LENGTH];
    clock_t start, end;

    srand(time(NULL));

    printf("\n***** SHOCKED C TYPING SPEED TEST *****\n");
    printf("                                       \n");
    printf("                                       \n");
    printf("                                       \n");
    printf("                                       \n");
    printf("***************************************\n");
    printf("|                                     |\n");
    printf("|  Prepare yourself for an extreme test|*\n");
    printf("|                                     |\n");
    printf("***************************************\n");
    printf("                                       \n");

    for (i = 0; i < NUM_STRINGS; i++) {
        generateString(strings[i]);
    }

    start = clock();

    for (i = 0; i < NUM_STRINGS; i++) {
        for (j = 0; j < MAX_STRING_LENGTH; j++) {
            printf("%c", strings[i][j]);
            for (k = 0; k < 10000; k++);
        }
        printf("\n");
    }

    end = clock();

    printf("\n*********************************\n");
    printf("| Your typing speed is: %f words/min |\n", (double)(MAX_STRING_LENGTH * NUM_STRINGS * 60) / ((end - start) / CLOCKS_PER_SEC));
    printf("*********************************\n");

    return 0;
}