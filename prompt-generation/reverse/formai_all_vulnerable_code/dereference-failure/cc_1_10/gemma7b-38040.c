//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
    Word *newNode = malloc(sizeof(Word));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = insertWord(head->next, word);
    }

    return head;
}

int spellCheck(Word *head, char *word) {
    char *wordLower = strdup(word);
    wordLower = tolower(wordLower);

    for (Word *currentWord = head; currentWord; currentWord = currentWord->next) {
        char *currentWordLower = strdup(currentWord->word);
        currentWordLower = tolower(currentWordLower);

        if (strcmp(wordLower, currentWordLower) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    Word *head = insertWord(NULL, "apple");
    insertWord(head, "banana");
    insertWord(head, "orange");
    insertWord(head, "grape");

    char *wordToSearch = "apricot";

    if (spellCheck(head, wordToSearch) == 1) {
        printf("Word found: %s\n", wordToSearch);
    } else {
        printf("Word not found: %s\n", wordToSearch);
    }

    return 0;
}