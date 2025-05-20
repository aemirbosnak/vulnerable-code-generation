//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024
#define CHAR_COUNT 256

int main() {
    char* wordlist[CHAR_COUNT];
    int i, j, k;
    int len = 0;
    clock_t start, end;

    // Generate a list of random words
    for (i = 0; i < CHAR_COUNT; i++) {
        wordlist[i] = (char*) malloc(MAX_LENGTH * sizeof(char));
        for (j = 0; j < MAX_LENGTH; j++) {
            wordlist[i][j] = 'a' + (rand() % 26);
        }
    }

    // Shuffle the list of words
    for (k = 0; k < CHAR_COUNT; k++) {
        int index = rand() % CHAR_COUNT;
        char temp[MAX_LENGTH];
        strcpy(temp, wordlist[index]);
        strcpy(wordlist[index], wordlist[k]);
        strcpy(wordlist[k], temp);
    }

    // Measure the execution time
    start = clock();
    for (i = 0; i < 10000; i++) {
        for (j = 0; j < CHAR_COUNT; j++) {
            len += strlen(wordlist[j]);
        }
    }
    end = clock();

    // Print the results
    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Total length: %d\n", len);

    // Free memory
    for (i = 0; i < CHAR_COUNT; i++) {
        free(wordlist[i]);
    }

    return 0;
}