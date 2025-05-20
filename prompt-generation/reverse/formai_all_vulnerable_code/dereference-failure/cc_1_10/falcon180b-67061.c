//Falcon-180B DATASET v1.0 Category: System administration ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_NUM_LINES 10000

typedef struct {
    char *word;
    unsigned int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    unsigned int num_words;
} WordFrequencyTable;

void initialize_word_frequency_table(WordFrequencyTable *table) {
    table->words = (WordFrequency *)malloc(MAX_NUM_LINES * sizeof(WordFrequency));
    table->num_words = 0;
}

void free_word_frequency_table(WordFrequencyTable *table) {
    for (unsigned int i = 0; i < table->num_words; i++) {
        free(table->words[i].word);
    }
    free(table->words);
}

void add_word_to_frequency_table(WordFrequencyTable *table, const char *word) {
    for (unsigned int i = 0; i < table->num_words; i++) {
        if (strcmp(table->words[i].word, word) == 0) {
            table->words[i].frequency++;
            return;
        }
    }
    if (table->num_words >= MAX_NUM_LINES) {
        fprintf(stderr, "Error: table is full\n");
        exit(1);
    }
    table->words[table->num_words].word = strdup(word);
    table->words[table->num_words].frequency = 1;
    table->num_words++;
}

void print_word_frequency_table(const WordFrequencyTable *table) {
    for (unsigned int i = 0; i < table->num_words; i++) {
        printf("%s %u\n", table->words[i].word, table->words[i].frequency);
    }
}

int main() {
    WordFrequencyTable table;
    initialize_word_frequency_table(&table);

    FILE *file = fopen("sherlock_holmes.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            add_word_to_frequency_table(&table, word);
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
    print_word_frequency_table(&table);

    free_word_frequency_table(&table);
    return 0;
}