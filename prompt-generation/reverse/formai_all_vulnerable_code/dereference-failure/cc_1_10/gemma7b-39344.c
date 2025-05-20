//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

int isWord(Word *head, char *word) {
    Word *currWord = head;

    while (currWord) {
        if (strcmp(currWord->word, word) == 0) {
            return 1;
        }
        currWord = currWord->next;
    }

    return 0;
}

int main() {
    char dictionaryPath[] = "words.txt";
    Word *head = NULL;

    // Insert words into the dictionary
    insertWord(head, "apple");
    insertWord(head, "banana");
    insertWord(head, "orange");
    insertWord(head, "grape");
    insertWord(head, "peach");

    // Spell check the word "apple"
    if (isWord(head, "apple")) {
        printf("Apple is in the dictionary.\n");
    } else {
        printf("Apple is not in the dictionary.\n");
    }

    // Spell check the word "banana"
    if (isWord(head, "banana")) {
        printf("Banana is in the dictionary.\n");
    } else {
        printf("Banana is not in the dictionary.\n");
    }

    // Spell check the word "orange"
    if (isWord(head, "orange")) {
        printf("Orange is in the dictionary.\n");
    } else {
        printf("Orange is not in the dictionary.\n");
    }

    return 0;
}