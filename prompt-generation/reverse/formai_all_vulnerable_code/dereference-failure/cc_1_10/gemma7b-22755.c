//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: decentralized
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

int detectSpam(Word *head, char *text) {
    int score = 0;
    char *words[MAX_WORDS];

    // Extract words from text
    char *p = text;
    int i = 0;
    while (p) {
        char *word = strtok(p, " ");
        if (word) {
            words[i++] = strdup(word);
        }
        p = strtok(NULL, " ");
    }

    // Check if words are in the spam word list
    for (int j = 0; j < i; j++) {
        if (searchWord(head, words[j])) {
            score++;
        }
    }

    return score;
}

int searchWord(Word *head, char *word) {
    while (head) {
        if (strcmp(head->word, word) == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
    Word *head = NULL;
    insertWord(head, "spam");
    insertWord(head, "junk");
    insertWord(head, "garbage");

    char *text = "This text contains spam and junk words.";

    int score = detectSpam(head, text);

    printf("Spam score: %d\n", score);

    return 0;
}