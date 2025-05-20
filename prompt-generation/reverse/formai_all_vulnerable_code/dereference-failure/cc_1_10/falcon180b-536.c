//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void read_file(FILE *file, struct WordFrequency *words, int *word_count) {
    char ch;
    int in_word = 0;
    int word_length = 0;
    char word[MAX_WORD_LENGTH];

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            in_word = 1;
            word[word_length++] = tolower(ch);
        } else if (in_word) {
            in_word = 0;
            word[word_length] = '\0';
            struct WordFrequency *found_word = NULL;

            for (int i = 0; i < *word_count; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    found_word = &words[i];
                    break;
                }
            }

            if (found_word == NULL) {
                if (*word_count >= MAX_WORD_LENGTH) {
                    printf("Error: Too many unique words.\n");
                    exit(1);
                }
                strcpy(found_word->word, word);
                (*word_count)++;
            }

            found_word->frequency++;
        }
    }
}

void print_word_frequencies(struct WordFrequency *words, int word_count) {
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int word_count = 0;
    struct WordFrequency words[MAX_WORD_LENGTH];

    read_file(file, words, &word_count);

    print_word_frequencies(words, word_count);

    fclose(file);
    return 0;
}