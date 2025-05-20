//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Ken Thompson
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

int isSpam(Word *head, char *phrase) {
    char **words = malloc(MAX_WORDS * sizeof(char *));
    int i = 0;

    for (Word *word = head; word; word = word->next) {
        words[i++] = word->word;
    }

    for (i = 0; words[i] && !strcmp(words[i], phrase); i++) {}

    free(words);

    return i == -1;
}

int main() {
    Word *head = insertWord(NULL, "Spam");
    insertWord(head, "Ham");
    insertWord(head, "Eggs");
    insertWord(head, "Spam");

    if (isSpam(head, "Spam")) {
        printf("Spam detected!\n");
    }

    return 0;
}