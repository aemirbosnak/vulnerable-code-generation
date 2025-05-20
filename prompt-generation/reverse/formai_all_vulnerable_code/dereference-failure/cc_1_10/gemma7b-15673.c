//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
    char *words[MAX_WORDS];
    int i = 0;

    // Tokenize the phrase
    char *word = strtok(phrase, " ");
    while (word) {
        words[i++] = strdup(word);
        word = strtok(NULL, " ");
    }

    // Check if the word is in the spam list
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i], head->word) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    Word *head = NULL;
    insertWord(head, "free");
    insertWord(head, "lottery");
    insertWord(head, "miracle");
    insertWord(head, "spam");

    char *phrase = "This is a spam message with lots of free stuff!";

    if (isSpam(head, phrase) == 1) {
        printf("The phrase is spam.\n");
    } else {
        printf("The phrase is not spam.\n");
    }

    return 0;
}