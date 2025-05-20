//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

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

int detectSpam(Word *head) {
    char *keywords[] = {"free", "lottery", "miracle", "prize", "vacation"};
    int i = 0;

    for (Word *currWord = head; currWord; currWord = currWord->next) {
        for (i = 0; i < MAX_WORDS && keywords[i] != NULL; i++) {
            if (strcmp(currWord->word, keywords[i]) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    Word *head = insertWord(NULL, "Free lottery!");
    insertWord(head, "Miracle prize!");
    insertWord(head, "Vacation prize!");

    if (detectSpam(head)) {
        printf("Spam detected!");
    } else {
        printf("No spam detected!");
    }

    return 0;
}