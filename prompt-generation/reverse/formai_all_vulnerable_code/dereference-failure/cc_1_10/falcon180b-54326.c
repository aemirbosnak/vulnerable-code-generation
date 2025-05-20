//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

WordFrequency *word_frequency_table;
int word_frequency_table_size;

void initialize_word_frequency_table(int size) {
    word_frequency_table = (WordFrequency *) malloc(size * sizeof(WordFrequency));
    word_frequency_table_size = size;
    for (int i = 0; i < size; i++) {
        word_frequency_table[i].word = NULL;
        word_frequency_table[i].frequency = 0;
    }
}

void add_word_to_frequency_table(char *word) {
    int hash = hash_string(word) % word_frequency_table_size;
    WordFrequency *entry = &word_frequency_table[hash];
    if (entry->word == NULL) {
        entry->word = strdup(word);
        entry->frequency = 1;
    } else if (strcmp(entry->word, word) == 0) {
        entry->frequency++;
    }
}

int hash_string(char *str) {
    int hash = 0;
    while (*str) {
        hash = 31 * hash + tolower(*str++);
    }
    return hash;
}

void print_word_frequency_table(FILE *output) {
    for (int i = 0; i < word_frequency_table_size; i++) {
        WordFrequency *entry = &word_frequency_table[i];
        if (entry->word!= NULL) {
            fprintf(output, "%s %d\n", entry->word, entry->frequency);
        }
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    FILE *input_file;
    FILE *output_file;

    initialize_word_frequency_table(100);

    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *word = strtok(line, " \t\r\n\f\v");
        while (word!= NULL) {
            add_word_to_frequency_table(word);
            word = strtok(NULL, " \t\r\n\f\v");
        }
    }

    print_word_frequency_table(output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}