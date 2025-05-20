//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void load_words(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in file %s\n", filename);
            exit(1);
        }

        words[num_words].word[0] = tolower(word[0]);
        strncpy(words[num_words].word + 1, word + 1, MAX_WORD_LENGTH - 1);
        words[num_words].count = 0;
        num_words++;
    }

    fclose(fp);
}

void spell_check(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
    }

    fclose(fp);

    printf("Spell check complete\n");
}

void print_misspellings(FILE* fp) {
    for (int i = 0; i < num_words; i++) {
        if (words[i].count == 0) {
            fprintf(fp, "Misspelled word: %s\n", words[i].word);
        }
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s load <words_file> | spell_check <text_file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "load") == 0) {
        load_words(argv[2]);
        printf("Loaded %d words\n", num_words);
    } else if (strcmp(argv[1], "spell_check") == 0) {
        spell_check(argv[2]);
    } else {
        printf("Error: invalid command\n");
        return 1;
    }

    return 0;
}