//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 1024
#define MAX_ARRAY_SIZE 100

int main() {
    char *string[MAX_ARRAY_SIZE];
    int i, j, k;
    char c;
    struct timespec start, end;

    // Initialize the string array with random words
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        string[i] = malloc(MAX_STRING_LENGTH);
        for (j = 0; j < MAX_STRING_LENGTH; j++) {
            c = 'a' + (rand() % 26);
            string[i][j] = c;
        }
    }

    // Print the strings in a dynamic way
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("String %d: ", i);
        for (j = 0; j < MAX_STRING_LENGTH; j++) {
            if (string[i][j] == '\0') {
                break;
            }
            printf("%c", string[i][j]);
        }
        printf("\n");
    }

    // Measure the execution time
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("String %d: ", i);
        for (j = 0; j < MAX_STRING_LENGTH; j++) {
            if (string[i][j] == '\0') {
                break;
            }
            printf("%c", string[i][j]);
        }
        printf("\n");
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double execution_time = (end.tv_sec - start.tv_sec) * 1000000000;
    printf("Execution time: %f seconds\n", execution_time);

    // Free the memory
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        free(string[i]);
    }

    return 0;
}