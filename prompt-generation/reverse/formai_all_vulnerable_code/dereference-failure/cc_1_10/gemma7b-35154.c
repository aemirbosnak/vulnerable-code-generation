//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct Word {
    char word[20];
    struct Word* next;
} Word;

Word* InsertWord(Word* head, char* word) {
    Word* newWord = malloc(sizeof(Word));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        head->next = InsertWord(head->next, word);
    }

    return head;
}

int SpellCheck(Word* head, char* word) {
    for (Word* currentWord = head; currentWord; currentWord = currentWord->next) {
        if (strcmp(currentWord->word, word) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    Word* head = NULL;
    InsertWord(head, "apple");
    InsertWord(head, "banana");
    InsertWord(head, "orange");
    InsertWord(head, "grapefruit");

    if (SpellCheck(head, "apple") == 1) {
        printf("Apple is in the dictionary.\n");
    }

    if (SpellCheck(head, "banana") == 1) {
        printf("Banana is in the dictionary.\n");
    }

    if (SpellCheck(head, "orange") == 1) {
        printf("Orange is in the dictionary.\n");
    }

    if (SpellCheck(head, "grapefruit") == 1) {
        printf("Grapefruit is in the dictionary.\n");
    }

    return 0;
}