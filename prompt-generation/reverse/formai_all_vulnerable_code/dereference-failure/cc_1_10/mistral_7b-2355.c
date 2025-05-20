//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_STRING_LENGTH 1024
#define NUM_STRINGS 1000000
#define LENGTH_OF_EACH_RANDOM_STRING (rand() % 10 + 1)

void generateRandomString(char *str, int length) {
    for (int i = 0; i < length; i++) {
        str[i] = (char) ('a' + rand() % 26);
    }
    str[length] = '\0';
}

int main() {
    clock_t start, end;
    double time_spent;

    char *strings[NUM_STRINGS];
    for (int i = 0; i < NUM_STRINGS; i++) {
        strings[i] = (char *) calloc(LENGTH_OF_EACH_RANDOM_STRING, sizeof(char));
        if (strings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            return 1;
        }
        generateRandomString(strings[i], LENGTH_OF_EACH_RANDOM_STRING);
    }

    start = clock();
    for (int i = 0; i < NUM_STRINGS; i++) {
        int len = strlen(strings[i]);
        for (int j = 0; j < len; j++) {
            if (strings[i][j] > 'z' || strings[i][j] < 'a') {
                fprintf(stderr, "Invalid character found in string %d\n", i);
                return 1;
            }
        }
    }
    end = clock();

    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %.9f seconds\n", time_spent);

    for (int i = 0; i < NUM_STRINGS; i++) {
        free(strings[i]);
    }

    return 0;
}