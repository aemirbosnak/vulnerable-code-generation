//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"
#define LINE_LENGTH 100

typedef struct Word {
    char word[MAX_WORD_LENGTH + 1];
    struct Word *next;
} Word;

Word *dictionary = NULL;
Word *current = NULL;

void load_dictionary() {
    FILE *fp = fopen(DICTIONARY_FILE, "r");
    char line[LINE_LENGTH];

    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, LINE_LENGTH, fp)) {
        Word *new_word = (Word *)malloc(sizeof(Word));
        strcpy(new_word->word, line);
        new_word->next = dictionary;
        dictionary = new_word;
    }

    fclose(fp);
}

bool is_in_dictionary(char *word) {
    current = dictionary;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return true;
        }
        current = current->next;
    }

    return false;
}

void check_word(char *word) {
    if (is_in_dictionary(word)) {
        printf("%s is a valid word.\n", word);
    } else {
        printf("%s is not a valid word.\n", word);
    }
}

int main(int argc, char *argv[]) {
    load_dictionary();

    if (argc < 2) {
        printf("Usage: %s <word>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    check_word(argv[1]);

    return EXIT_SUCCESS;
}