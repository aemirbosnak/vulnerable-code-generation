//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    struct Word* next;
} Word;

Word* insertWord(Word* head, char* word) {
    Word* newNode = malloc(sizeof(Word));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int main() {
    Word* head = NULL;
    head = insertWord(head, "apple");
    head = insertWord(head, "banana");
    head = insertWord(head, "cherry");
    head = insertWord(head, "orange");

    char* wordToSearch = "apricot";

    Word* currentWord = head;
    while (currentWord) {
        if (strcmp(currentWord->word, wordToSearch) == 0) {
            printf("Word found: %s\n", currentWord->word);
            break;
        }

        currentWord = currentWord->next;
    }

    if (currentWord == NULL) {
        printf("Word not found: %s\n", wordToSearch);
    }

    return 0;
}