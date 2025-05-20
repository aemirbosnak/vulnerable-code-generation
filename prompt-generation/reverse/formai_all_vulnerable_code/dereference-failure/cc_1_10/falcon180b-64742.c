//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_input_file(FILE *input_file, WordFrequency *word_frequency_table, int num_words) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(input_file, "%s", word)!= EOF) {
        if (i >= num_words) {
            printf("Error: Input file contains more than %d words.\n", num_words);
            exit(1);
        }
        strcpy(word_frequency_table[i].word, word);
        word_frequency_table[i].frequency = 1;
        i++;
    }
}

void display_word_frequency(WordFrequency *word_frequency_table, int num_words) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        if (word_frequency_table[i].frequency > 0) {
            printf("%s\t%d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
        }
    }
}

int main() {
    FILE *input_file;
    char input_filename[100];
    printf("Enter input file name: ");
    scanf("%s", input_filename);
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }
    int num_words;
    printf("Enter number of words to display: ");
    scanf("%d", &num_words);
    WordFrequency word_frequency_table[MAX_NUM_WORDS];
    read_input_file(input_file, word_frequency_table, num_words);
    display_word_frequency(word_frequency_table, num_words);
    fclose(input_file);
    return 0;
}