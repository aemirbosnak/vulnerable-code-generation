//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        head->next = insertWord(head->next, word);
    }

    return head;
}

void spellCheck(Word *head, char *word) {
    Word *currentWord = head;

    while (currentWord) {
        if (strcmp(currentWord->word, word) == 0) {
            printf("%s is in the dictionary.\n", word);
            return;
        }

        currentWord = currentWord->next;
    }

    printf("%s is not in the dictionary.\n", word);
}

int main() {
    Word *head = NULL;

    insertWord(head, "apple");
    insertWord(head, "banana");
    insertWord(head, "orange");
    insertWord(head, "grape");

    spellCheck(head, "apple");
    spellCheck(head, "banana");
    spellCheck(head, "grape");
    spellCheck(head, "mango");

    return 0;
}