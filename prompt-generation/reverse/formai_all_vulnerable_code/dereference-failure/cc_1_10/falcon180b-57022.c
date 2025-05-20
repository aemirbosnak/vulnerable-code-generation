//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char* word;
    int count;
} WordFrequency;

int main() {
    FILE* file;
    char line[MAX_WORD_LENGTH];
    char* word;
    WordFrequency* frequencies = malloc(MAX_WORDS * sizeof(WordFrequency));
    int num_words = 0;

    if (frequencies == NULL) {
        printf("Error: could not allocate memory for frequencies\n");
        exit(EXIT_FAILURE);
    }

    file = fopen("romeo_and_juliet.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", line)!= EOF) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words\n");
                exit(EXIT_FAILURE);
            }

            frequencies[num_words].word = strdup(word);
            frequencies[num_words].count = 1;

            word = strtok(NULL, ",.?!;:");
            num_words++;
        }
    }

    fclose(file);

    printf("Word frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }

    for (int i = 0; i < num_words; i++) {
        free(frequencies[i].word);
    }
    free(frequencies);

    return 0;
}