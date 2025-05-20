//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    struct Word* next;
} Word;

Word* insertWord(Word* head, char* word) {
    Word* newWord = malloc(sizeof(Word));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        Word* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newWord;
    }

    return head;
}

int spellCheck(Word* head, char* word) {
    char* w = word;
    Word* currentWord = head;

    while (currentWord) {
        if (strcmp(w, currentWord->word) == 0) {
            return 1;
        }

        currentWord = currentWord->next;
    }

    return 0;
}

int main() {
    Word* head = NULL;
    insertWord(head, "apple");
    insertWord(head, "banana");
    insertWord(head, "cherry");
    insertWord(head, "orange");

    char* word = "banana";
    if (spellCheck(head, word) == 1) {
        printf("Word found: %s\n", word);
    } else {
        printf("Word not found: %s\n", word);
    }

    return 0;
}