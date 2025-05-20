//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE* file, WordCount* word_counts) {
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            if (word_counts->count > 0) {
                word_counts++;
            }
        } else {
            strncpy(word_counts->word, &ch, MAX_WORD_LENGTH);
            word_counts->count = 1;
        }
    }
}

void print_word_counts(WordCount* word_counts) {
    printf("Word\tCount\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].count > 0) {
            printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    FILE* file;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    read_file(file, word_counts);

    fclose(file);

    print_word_counts(word_counts);

    return 0;
}