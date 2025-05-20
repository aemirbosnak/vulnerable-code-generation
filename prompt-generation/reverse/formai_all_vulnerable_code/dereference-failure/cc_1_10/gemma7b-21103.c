//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define WORDS_PER_PAGE 10

typedef struct WordEntry {
    char word[MAX_WORD_LENGTH];
    struct WordEntry* next;
} WordEntry;

WordEntry* insertWord(WordEntry* head, char* word) {
    WordEntry* newEntry = malloc(sizeof(WordEntry));
    strcpy(newEntry->word, word);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

int main() {
    WordEntry* head = NULL;

    insertWord(head, "apple");
    insertWord(head, "banana");
    insertWord(head, "orange");
    insertWord(head, "grapefruit");

    char wordToSearchFor[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", wordToSearchFor);

    WordEntry* currentWord = head;
    while (currentWord) {
        if (strcmp(wordToSearchFor, currentWord->word) == 0) {
            printf("Word found: %s\n", currentWord->word);
            break;
        }
        currentWord = currentWord->next;
    }

    if (currentWord == NULL) {
        printf("Word not found\n");
    }

    return 0;
}