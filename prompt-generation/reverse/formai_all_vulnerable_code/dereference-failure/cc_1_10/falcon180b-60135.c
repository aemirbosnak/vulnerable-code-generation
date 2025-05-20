//Falcon-180B DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, WordFrequency *word_frequencies) {
    char line[MAX_WORD_LENGTH];
    char *word = strtok(line, ",.!?;:");

    while (word!= NULL) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        WordFrequency *frequency = NULL;
        int found = 0;

        for (i = 0; i < MAX_WORDS &&!found; i++) {
            if (strcmp(word, word_frequencies[i].word) == 0) {
                frequency = &word_frequencies[i];
                found = 1;
            }
        }

        if (!found) {
            if (word_frequencies[MAX_WORDS - 1].word[0]!= '\0') {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }
            strcpy(word_frequencies[MAX_WORDS - 1].word, word);
            frequency = &word_frequencies[MAX_WORDS - 1];
        }

        frequency->count++;
        word = strtok(NULL, ",.!?;:");
    }
}

void write_file(FILE *file, WordFrequency *word_frequencies) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (word_frequencies[i].word[0]!= '\0') {
            fprintf(file, "%s: %d\n", word_frequencies[i].word, word_frequencies[i].count);
        }
    }
}

int main() {
    FILE *input_file, *output_file;
    WordFrequency word_frequencies[MAX_WORDS];

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    read_file(input_file, word_frequencies);

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    write_file(output_file, word_frequencies);

    fclose(input_file);
    fclose(output_file);

    return 0;
}