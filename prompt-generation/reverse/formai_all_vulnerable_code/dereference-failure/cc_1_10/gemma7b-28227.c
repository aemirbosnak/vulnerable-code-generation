//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <string.h>
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
        Word *currentWord = head;
        while (currentWord->next != NULL) {
            currentWord = currentWord->next;
        }
        currentWord->next = newWord;
    }

    return head;
}

int spellCheck(Word *head, char *word) {
    char lowerWord[MAX_WORD_LENGTH];
    char *pWord = word;

    // Convert word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        lowerWord[i] = tolower(pWord[i]);
    }

    // Iterate over the dictionary
    Word *currentWord = head;
    while (currentWord) {
        // Compare the word with the current word in the dictionary
        if (strcmp(lowerWord, currentWord->word) == 0) {
            return 1;
        }
        currentWord = currentWord->next;
    }

    return 0;
}

int main() {
    Word *head = NULL;

    insertWord(head, "apple");
    insertWord(head, "banana");
    insertWord(head, "cherry");
    insertWord(head, "orange");

    if (spellCheck(head, "apple") == 1) {
        printf("Apple is in the dictionary.\n");
    }

    if (spellCheck(head, "grape") == 0) {
        printf("Grape is not in the dictionary.\n");
    }

    return 0;
}