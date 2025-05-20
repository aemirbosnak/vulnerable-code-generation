//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define WORD_LENGTH 50
#define DICTIONARY_SIZE 10000

typedef struct Word {
    char word[WORD_LENGTH];
    struct Word *next;
} Word;

Word *dictionary[DICTIONARY_SIZE];
int words_count = 0;

void load_dictionary() {
    FILE *fp;
    char line[1024];
    Word *new_word;
    int index;

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file!\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        new_word = (Word *) malloc(sizeof(Word));
        strcpy(new_word->word, line);
        index = strlen(line) / WORD_LENGTH;
        new_word->next = dictionary[index];
        dictionary[index] = new_word;
        words_count++;
    }

    fclose(fp);
}

int hash(char *word) {
    int hash = 0;
    int i;

    for (i = 0; i < strlen(word); i++)
        hash += tolower(word[i]) * (i + 1);

    return hash % DICTIONARY_SIZE;
}

int check_word(char *word) {
    Word *current;
    int index;

    index = hash(word);

    current = dictionary[index];

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            printf("** Congratulations! You spelled the word '%s' correctly! **\n", word);
            return 1;
        }
        current = current->next;
    }

    printf("* Sorry, the word '%s' is not in the dictionary. *\n", word);
    return 0;
}

int main(int argc, char *argv[]) {
    char word[WORD_LENGTH];
    int i;

    if (argc < 2) {
        printf("Usage: %s <word>\n", argv[0]);
        return 1;
    }

    load_dictionary();

    strcpy(word, argv[1]);

    for (i = 0; i < strlen(word); i++)
        word[i] = tolower(word[i]);

    check_word(word);

    return 0;
}