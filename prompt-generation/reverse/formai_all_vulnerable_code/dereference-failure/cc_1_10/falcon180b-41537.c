//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compare_words(const void *a, const void *b) {
    struct word_frequency *word1 = (struct word_frequency *)a;
    struct word_frequency *word2 = (struct word_frequency *)b;

    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *input_file;
    char line[MAX_WORD_LENGTH];
    char *word;
    int word_count = 0;
    struct word_frequency *word_frequency_table = NULL;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    word_frequency_table = (struct word_frequency *)malloc(MAX_WORDS * sizeof(struct word_frequency));
    if (word_frequency_table == NULL) {
        printf("Error allocating memory for word frequency table.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            word_count++;
            if (word_count == MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }

            strcpy(word_frequency_table[word_count].word, word);
            word_frequency_table[word_count].frequency = 1;

            qsort(word_frequency_table, word_count, sizeof(struct word_frequency), compare_words);

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(input_file);

    qsort(word_frequency_table, word_count, sizeof(struct word_frequency), compare_words);

    printf("Word\t\tFrequency\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\t\t%d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
    }

    free(word_frequency_table);

    return 0;
}