//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    WordFrequency *word_frequency_table = malloc(MAX_WORDS * sizeof(WordFrequency));
    int num_words = 0;
    int i;

    file = fopen("example_text.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            num_words++;
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words in text.\n");
                exit(1);
            }
            strcpy(word_frequency_table[num_words - 1].word, word);
            word_frequency_table[num_words - 1].frequency = 1;
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printf("Word\tFrequency\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
    }

    free(word_frequency_table);

    return 0;
}