//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct Word {
    char* word;
    struct Word* next;
} Word;

Word* insertWord(Word* head, char* word) {
    Word* newNode = malloc(sizeof(Word));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = insertWord(head->next, word);
    }

    return head;
}

int translate(Word* head, char* language) {
    Word* currentWord = head;
    char* translatedWord = malloc(MAX_WORD_LENGTH);

    while (currentWord) {
        if (strcmp(currentWord->word, language) == 0) {
            strcpy(translatedWord, currentWord->word);
            printf("%s\n", translatedWord);
        }

        currentWord = currentWord->next;
    }

    free(translatedWord);
    return 0;
}

int main() {
    Word* head = insertWord(NULL, "Hello");
    insertWord(head, "World");
    insertWord(head, "Cat");
    insertWord(head, "Translate");

    translate(head, "Cat");

    return 0;
}