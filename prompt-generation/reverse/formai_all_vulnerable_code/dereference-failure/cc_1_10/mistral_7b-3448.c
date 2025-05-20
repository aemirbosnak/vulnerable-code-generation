//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_MAX_WORDS 1000
#define WORDS_FILE "dictionary.txt"

typedef struct Word {
    char word[MAX_WORD_LENGTH + 1];
    struct Word *next;
} Word;

Word *dictionary = NULL;

void load_dictionary() {
    FILE *fp;
    char line[MAX_WORD_LENGTH + 1];
    char *word;
    Word *new_word;

    fp = fopen(WORDS_FILE, "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH + 1, fp)) {
        word = strtok(line, "\n");
        word = strtok(word, " ");

        new_word = (Word *)malloc(sizeof(Word));
        strcpy(new_word->word, word);
        new_word->next = dictionary;
        dictionary = new_word;
    }

    fclose(fp);
}

int is_in_dictionary(char *word) {
    Word *current;

    current = dictionary;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0)
            return 1;
        current = current->next;
    }

    return 0;
}

void check_spell(char *line) {
    char *token;
    int i;

    token = strtok(line, " ");
    while (token != NULL) {
        for (i = 0; token[i] != '\0'; i++) {
            token[i] = tolower(token[i]);
        }

        if (!is_in_dictionary(token)) {
            printf("Error: %s is not a valid word.\n", token);
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    char line[1000];

    load_dictionary();

    printf("Hello! I'm a happy C Spell checker. I'll help you find the mistakes in your sentences.\n");

    while (1) {
        printf("Enter a line: ");
        fgets(line, sizeof(line), stdin);

        check_spell(line);

        printf("\nKeep going? (y/n) ");
        char answer;
        scanf("%c", &answer);
        if (answer == 'n')
            break;
    }

    return 0;
}