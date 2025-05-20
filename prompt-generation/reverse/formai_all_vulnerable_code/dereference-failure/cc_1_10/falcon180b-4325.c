//Falcon-180B DATASET v1.0 Category: Text processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void read_input_file(FILE *input_file, struct WordFrequency *word_frequencies, int *word_count) {
    char word[MAX_WORD_LENGTH];
    int word_length;

    while (fscanf(input_file, "%s", word)!= EOF) {
        word_length = strlen(word);

        if (word_length > 0 && word_length <= MAX_WORD_LENGTH) {
            struct WordFrequency *word_frequency = NULL;

            for (int i = 0; i < *word_count; i++) {
                if (strcmp(word_frequencies[i].word, word) == 0) {
                    word_frequency = &word_frequencies[i];
                    break;
                }
            }

            if (word_frequency == NULL) {
                if (*word_count >= MAX_WORDS) {
                    printf("Error: Maximum number of words reached.\n");
                    exit(1);
                }

                word_frequency = &word_frequencies[*word_count];
                (*word_count)++;
            }

            word_frequency->frequency++;
        }
    }
}

void write_output_file(FILE *output_file, struct WordFrequency *word_frequencies, int word_count) {
    for (int i = 0; i < word_count; i++) {
        fprintf(output_file, "%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int word_count = 0;
    struct WordFrequency word_frequencies[MAX_WORDS];

    read_input_file(input_file, word_frequencies, &word_count);

    write_output_file(output_file, word_frequencies, word_count);

    fclose(input_file);
    fclose(output_file);

    return 0;
}