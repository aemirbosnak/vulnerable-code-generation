//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 256

typedef struct Word {
    char *word;
    int length;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word, int length) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = malloc(length * sizeof(char));
    newWord->length = length;
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        Word *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newWord;
    }

    return head;
}

int spellCheck(Word *head, char *word) {
    Word *current = head;
    while (current) {
        if (strcmp(word, current->word) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    Word *head = NULL;
    insertWord(head, "apple", 5);
    insertWord(head, "banana", 6);
    insertWord(head, "orange", 6);
    insertWord(head, "grape", 5);

    if (spellCheck(head, "apple") == 1) {
        printf("Apple is in the dictionary.\n");
    }

    if (spellCheck(head, "banana") == 1) {
        printf("Banana is in the dictionary.\n");
    }

    if (spellCheck(head, "orange") == 1) {
        printf("Orange is in the dictionary.\n");
    }

    if (spellCheck(head, "grape") == 1) {
        printf("Grape is in the dictionary.\n");
    }

    return 0;
}