//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 255

typedef struct CatWord {
    char word[MAX_WORD_LENGTH];
    struct CatWord* next;
} CatWord;

CatWord* insertWord(CatWord* head, char* word) {
    CatWord* newWord = malloc(sizeof(CatWord));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL) {
        return newWord;
    }

    CatWord* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    tail->next = newWord;
    return head;
}

int translateCat(CatWord* head, char* query) {
    char* result = malloc(MAX_WORD_LENGTH);
    strcpy(result, "");

    for (CatWord* word = head; word; word = word->next) {
        if (strcmp(word->word, query) == 0) {
            strcat(result, word->word);
            break;
        }
    }

    return strlen(result);
}

int main() {
    CatWord* head = insertWord(NULL, "Meow");
    insertWord(head, "Woof");
    insertWord(head, "Chirp");

    char* query = "Meow";
    int length = translateCat(head, query);

    printf("Length of translated word: %d\n", length);

    return 0;
}