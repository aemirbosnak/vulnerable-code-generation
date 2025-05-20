//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void translateCat(Word *head) {
    char *translatedWord = malloc(MAX_WORDS);
    translatedWord[0] = '\0';

    for (Word *word = head; word != NULL; word = word->next) {
        char *wordLower = malloc(MAX_WORDS);
        wordLower[0] = '\0';

        for (int i = 0; word->word[i] != '\0'; i++) {
            wordLower[i] = tolower(word->word[i]);
        }

        int wordLength = strlen(wordLower);

        if (translatedWord[0] == '\0') {
            sprintf(translatedWord, "%s", wordLower);
        } else {
            sprintf(translatedWord, "%s, %s", translatedWord, wordLower);
        }

        free(wordLower);
    }

    printf("%s\n", translatedWord);

    free(translatedWord);
}

int main() {
    Word *head = insertWord(NULL, "Meow");
    insertWord(head, "Woof");
    insertWord(head, "Chirp");

    translateCat(head);

    return 0;
}