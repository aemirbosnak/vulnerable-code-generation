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

int isSpam(Word *head, char *phrase) {
    char **words = malloc(MAX_WORDS * sizeof(char *));
    int i = 0;

    for (Word *word = head; word; word = word->next) {
        words[i++] = word->word;
    }

    for (int j = 0; j < i && words[j] != NULL; j++) {
        if (strstr(phrase, words[j])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    Word *head = insertWord(NULL, "free");
    insertWord(head, "money");
    insertWord(head, "prize");
    insertWord(head, "lottery");

    char *phrase = "You have won $1 million!";

    if (isSpam(head, phrase)) {
        printf("Spam detected!");
    } else {
        printf("No spam detected.");
    }

    return 0;
}