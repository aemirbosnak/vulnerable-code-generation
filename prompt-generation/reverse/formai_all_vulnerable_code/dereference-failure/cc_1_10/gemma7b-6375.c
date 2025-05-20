//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1024

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
    char *spamWords[] = {"free", "lottery", "miracle", "prize", "sweepstakes"};

    for (int i = 0; i < 5; i++) {
        if (strstr(head->word, spamWords[i]) != NULL) {
            return 1;
        }
    }

    return 0;
}

int main() {
    Word *head = insertWord(NULL, "You won a lottery!");
    insertWord(head, "Free gift!");
    insertWord(head, "Miracle offer!");
    insertWord(head, "Prize draw!");
    insertWord(head, "Sweepstakes!");

    if (detectSpam(head) == 1) {
        printf("Spam detected!");
    } else {
        printf("No spam detected");
    }

    return 0;
}