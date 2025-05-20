//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: grateful
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

int main() {
    Word *words = NULL;
    char *spamWords[] = {"free", "lottery", "miracle", "prize", "sweepstakes"};

    for (int i = 0; i < 5; i++) {
        insertWord(words, spamWords[i]);
    }

    char *email = "You have won a lottery! Free prize!";

    if (searchWord(words, email)) {
        printf("Email is spam.\n");
    } else {
        printf("Email is not spam.\n");
    }

    return 0;
}

int searchWord(Word *head, char *email) {
    while (head) {
        if (strcmp(head->word, email) == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}