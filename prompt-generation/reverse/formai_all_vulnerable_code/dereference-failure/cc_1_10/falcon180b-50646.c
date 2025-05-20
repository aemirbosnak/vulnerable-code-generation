//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compare_words(const void *a, const void *b) {
    struct word_frequency *word_a = (struct word_frequency *)a;
    struct word_frequency *word_b = (struct word_frequency *)b;

    return strcmp(word_a->word, word_b->word);
}

int main() {
    FILE *input_file;
    char line[1000];
    char *word;
    int word_length;
    struct word_frequency *word_frequency_table = NULL;
    int num_words = 0;

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        word = line;
        while ((word_length = strlen(word)) > 0) {
            if (num_words >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }

            if (word_length > MAX_WORD_LENGTH) {
                printf("Word length exceeds maximum limit.\n");
                exit(1);
            }

            word_frequency_table = realloc(word_frequency_table, sizeof(struct word_frequency) * ++num_words);
            strcpy(word_frequency_table[num_words - 1].word, word);
            word_frequency_table[num_words - 1].frequency = 1;

            word += word_length;
        }
    }

    fclose(input_file);

    qsort(word_frequency_table, num_words, sizeof(struct word_frequency), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
    }

    free(word_frequency_table);

    return 0;
}