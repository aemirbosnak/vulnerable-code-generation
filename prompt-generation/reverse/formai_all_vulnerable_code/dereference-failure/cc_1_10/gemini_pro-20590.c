//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct node {
    char word[MAX_WORD_LEN];
    struct node *next;
} node;

node *hashTable[MAX_WORDS];

unsigned int hash(const char *str) {
    unsigned int h = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        h = (h << 5) - h + str[i];
    }
    return h % MAX_WORDS;
}

void insert(const char *word) {
    unsigned int h = hash(word);
    node *new = malloc(sizeof(node));
    strcpy(new->word, word);
    new->next = hashTable[h];
    hashTable[h] = new;
}

int search(const char *word) {
    unsigned int h = hash(word);
    node *n = hashTable[h];
    while (n != NULL) {
        if (strcmp(n->word, word) == 0) {
            return 1;
        }
        n = n->next;
    }
    return 0;
}

void loadDictionary(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Error opening dictionary file.\n");
        exit(1);
    }
    char word[MAX_WORD_LEN];
    while (fscanf(f, "%s", word) != EOF) {
        insert(word);
    }
    fclose(f);
}

int checkSpelling(const char *word) {
    return search(word);
}

int main() {
    // Load the dictionary
    loadDictionary("dictionary.txt");

    // Check the spelling of some words
    char words[][MAX_WORD_LEN] = {"apple", "banana", "cherry", "dog", "elephant", "fish", "grape", "house", "ice cream", "juice"};
    for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        if (checkSpelling(words[i])) {
            printf("%s is spelled correctly.\n", words[i]);
        } else {
            printf("%s is spelled incorrectly.\n", words[i]);
        }
    }

    return 0;
}