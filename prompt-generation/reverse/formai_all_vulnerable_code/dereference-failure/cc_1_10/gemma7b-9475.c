//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

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

int main() {
    Word *words = NULL;
    words = insertWord(words, "apple");
    words = insertWord(words, "banana");
    words = insertWord(words, "orange");
    words = insertWord(words, "grapefruit");
    words = insertWord(words, "pineapple");

    char *spamWord = "pineapple";

    int isSpam = 0;
    for (Word *word = words; word != NULL; word++) {
        if (strcmp(word->word, spamWord) == 0) {
            isSpam = 1;
        }
    }

    if (isSpam) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}