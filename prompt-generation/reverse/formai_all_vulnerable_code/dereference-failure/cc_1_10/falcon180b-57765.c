//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: genious
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

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    WordCount words[MAX_WORDS];
    int num_words = 0;
    char ch;
    bool in_word = false;
    char *word_start = NULL;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (!in_word) {
                in_word = true;
                word_start = &ch;
            }
        } else if (in_word) {
            in_word = false;
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words in file\n");
                fclose(file);
                return 1;
            }
            strncpy(words[num_words].word, word_start, MAX_WORD_LENGTH);
            words[num_words].word[MAX_WORD_LENGTH - 1] = '\0';
            words[num_words].count = 1;
            num_words++;
        }
    }

    if (in_word) {
        strncpy(words[num_words].word, word_start, MAX_WORD_LENGTH);
        words[num_words].word[MAX_WORD_LENGTH - 1] = '\0';
        words[num_words].count = 1;
        num_words++;
    }

    fclose(file);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}