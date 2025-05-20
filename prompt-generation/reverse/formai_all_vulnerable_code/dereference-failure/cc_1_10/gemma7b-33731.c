//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_CHAR 256

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

void freeWord(Word *word) {
    free(word->word);
    free(word);
}

int main() {
    Word *words = NULL;
    char word[MAX_WORDS];

    printf("Enter a word: ");
    scanf("%s", word);

    words = insertWord(words, word);

    printf("List of words: ");
    for (Word *currentWord = words; currentWord; currentWord = currentWord->next) {
        printf("%s ", currentWord->word);
    }

    printf("\n");

    freeWord(words);

    return 0;
}