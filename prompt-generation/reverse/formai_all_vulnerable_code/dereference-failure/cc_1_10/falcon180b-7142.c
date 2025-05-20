//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compare_word_frequency(const void *a, const void *b) {
    const WordFrequency *w1 = a;
    const WordFrequency *w2 = b;
    return w2->frequency - w1->frequency;
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordFrequency *word_frequency_table = NULL;
    int num_words = 0;
    int i;

    // Open the file
    file = fopen("romeo_and_juliet.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read the file and count the frequency of each word
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        num_words = 0;
        word_frequency_table = realloc(word_frequency_table, num_words * sizeof(WordFrequency));
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                strncpy(word, &line[i], MAX_WORD_LENGTH);
                word[strcspn(word, ",.?!;:\"'")] = '\0';
                if (strlen(word) > 0) {
                    num_words++;
                    word_frequency_table[num_words - 1].word = strdup(word);
                    word_frequency_table[num_words - 1].frequency = 1;
                }
            }
        }
        qsort(word_frequency_table, num_words, sizeof(WordFrequency), compare_word_frequency);
    }

    // Print the word frequency table
    printf("Word\tFrequency\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
    }

    // Close the file
    fclose(file);
    return 0;
}