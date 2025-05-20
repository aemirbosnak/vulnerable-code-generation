//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: inquisitive
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct CAT_WORD {
    char word[20];
    struct CAT_WORD* next;
} CAT_WORD;

CAT_WORD* createWord(char* word) {
    CAT_WORD* newWord = (CAT_WORD*)malloc(sizeof(CAT_WORD));
    strcpy(newWord->word, word);
    newWord->next = NULL;
    return newWord;
}

void addWord(CAT_WORD* head, char* word) {
    CAT_WORD* newWord = createWord(word);
    if (head == NULL) {
        head = newWord;
    } else {
        head->next = newWord;
    }
}

int translateWord(char* word) {
    CAT_WORD* head = NULL;
    addWord(head, "Meow");
    addWord(head, "Purr");
    addWord(head, "Meow-Meow");
    addWord(head, "Meow-Purr");

    CAT_WORD* currentWord = head;
    while (currentWord) {
        if (strcmp(word, currentWord->word) == 0) {
            return currentWord->word;
        }
        currentWord = currentWord->next;
    }

    return -1;
}

int main() {
    char* word = "Meow-Purr";
    int translation = translateWord(word);

    if (translation != -1) {
        printf("Translation: %s", translation);
    } else {
        printf("Word not found.");
    }

    return 0;
}