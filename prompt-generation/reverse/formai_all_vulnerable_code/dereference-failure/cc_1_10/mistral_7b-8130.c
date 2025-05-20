//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char str[WORD_LENGTH];
    struct Word *next;
} Word;

Word *dictionary = NULL;

void load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char str[WORD_LENGTH];
    Word *current, *new_word;

    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open dictionary file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(str, sizeof(str), fp)) {
        str[strlen(str) - 1] = '\0'; // Remove newline character
        new_word = (Word *)malloc(sizeof(Word));
        strcpy(new_word->str, str);
        new_word->next = dictionary;
        dictionary = new_word;
    }

    fclose(fp);
}

int is_valid_word(const char *word) {
    Word *current = dictionary;

    while (current != NULL) {
        if (strcasecmp(current->str, word) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void check_spell(const char *text) {
    char word[WORD_LENGTH];
    int word_length, i;
    int misspelled = 0;

    for (i = 0; text[i] != '\0'; i++) {
        if (isspace(text[i])) {
            if (i > 0 && word[0] != '\0') {
                word_length = i - 1;
                if (!is_valid_word(&word[0])) {
                    printf("Misspelled word: %s\n", &word[0]);
                    misspelled++;
                }
                memset(word, 0, WORD_LENGTH);
            }
        } else {
            word[word_length++] = tolower(text[i]);
        }
    }

    if (word[0] != '\0') {
        word_length = i - (i - strlen(&word[0]));
        if (!is_valid_word(&word[0])) {
            printf("Misspelled word: %s\n", &word[0]);
            misspelled++;
        }
    }

    if (misspelled == 0) {
        printf("No misspelled words found!\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_dictionary("dictionary.txt");

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open input file %s.\n", argv[1]);
        return EXIT_FAILURE;
    }

    char text[1024];
    int ch;

    while ((ch = fgetc(fp)) != EOF) {
        text[fgetc(fp)] = ch;
    }

    text[strlen(text)] = '\0';
    fclose(fp);

    check_spell(text);

    return EXIT_SUCCESS;
}