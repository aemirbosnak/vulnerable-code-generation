//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

struct word {
    char word[MAX_WORD_LEN];
    int count;
};

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void read_words(struct word *words, FILE *file) {
    char line[MAX_WORD_LEN];
    char *word;
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            if (i >= MAX_WORDS) {
                fprintf(stderr, "Error: Too many words.\n");
                exit(1);
            }

            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(words, i, sizeof(struct word), compare);
}

void check_spelling(struct word *words, FILE *file) {
    char line[MAX_WORD_LEN];
    char *word;
    int i;

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            i = 0;
            while (i < MAX_WORDS && strcmp(word, words[i].word)!= 0) {
                i++;
            }

            if (i == MAX_WORDS) {
                fprintf(stdout, "Misspelled word: %s\n", word);
            }

            word = strtok(NULL, ",.?!;:");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s dictionary_file text_file\n", argv[0]);
        return 1;
    }

    FILE *dict_file = fopen(argv[1], "r");
    FILE *text_file = fopen(argv[2], "r");

    if (dict_file == NULL || text_file == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }

    struct word words[MAX_WORDS];
    read_words(words, dict_file);
    check_spelling(words, text_file);

    fclose(dict_file);
    fclose(text_file);

    return 0;
}