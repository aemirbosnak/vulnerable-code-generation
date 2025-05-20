//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char word[20];
    struct Word* next;
} Word;

Word* insertWord(Word* head, char* word) {
    Word* newNode = malloc(sizeof(Word));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    head->next = insertWord(head->next, word);
    return head;
}

int spellCheck(Word* head, char* word) {
    for (Word* current = head; current; current = current->next) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    Word* head = NULL;
    insertWord(head, "apple");
    insertWord(head, "banana");
    insertWord(head, "orange");
    insertWord(head, "grape");

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