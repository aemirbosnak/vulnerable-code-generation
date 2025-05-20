//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

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
    Word *head = NULL;

    insertWord(head, "apple");
    insertWord(head, "banana");
    insertWord(head, "orange");
    insertWord(head, "grapefruit");

    char *wordToSearch = "pineapple";

    Word *word = head;

    while (word) {
        if (strcmp(word->word, wordToSearch) == 0) {
            printf("Word found: %s\n", word->word);
            break;
        }

        word = word->next;
    }

    if (word == NULL) {
        printf("Word not found\n");
    }

    return 0;
}