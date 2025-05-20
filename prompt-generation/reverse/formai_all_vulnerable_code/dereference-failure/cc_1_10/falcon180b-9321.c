//Falcon-180B DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, WordCount *word_counts, int num_words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_words) {
            strcpy(word_counts[num_words - 1].word, word);
            word_counts[num_words - 1].count = 1;
            num_words++;
        }
    }
}

void sort_word_counts(WordCount *word_counts, int num_words) {
    int i, j;
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (word_counts[i].count < word_counts[j].count) {
                WordCount temp = word_counts[i];
                word_counts[i] = word_counts[j];
                word_counts[j] = temp;
            }
        }
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    char filename[100];
    int num_words = 0;
    WordCount word_counts[MAX_WORDS];

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_file(file, word_counts, num_words);
    fclose(file);

    sort_word_counts(word_counts, num_words);
    printf("Word counts:\n");
    print_word_counts(word_counts, num_words);

    return 0;
}