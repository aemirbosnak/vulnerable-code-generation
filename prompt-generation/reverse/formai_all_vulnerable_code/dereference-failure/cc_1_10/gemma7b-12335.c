//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_LANGUAGE_MAX_WORDS 10

typedef struct AlienLanguageWord {
    char *word;
    struct AlienLanguageWord *next;
} AlienLanguageWord;

AlienLanguageWord *alienLanguageWord_create(char *word) {
    AlienLanguageWord *newWord = malloc(sizeof(AlienLanguageWord));
    newWord->word = strdup(word);
    newWord->next = NULL;
    return newWord;
}

void alienLanguageWord_add(AlienLanguageWord **head, char *word) {
    AlienLanguageWord *newWord = alienLanguageWord_create(word);
    if (*head == NULL) {
        *head = newWord;
    } else {
        (*head)->next = newWord;
    }
}

char *alienLanguageWord_translate(AlienLanguageWord *head, char *alienWord) {
    for (AlienLanguageWord *word = head; word; word = word->next) {
        if (strcmp(word->word, alienWord) == 0) {
            return word->word;
        }
    }
    return NULL;
}

int main() {
    AlienLanguageWord *head = NULL;
    alienLanguageWord_add(&head, "Gor'nak");
    alienLanguageWord_add(&head, "Zork'nak");
    alienLanguageWord_add(&head, "Blorg'nak");

    char *alienWord = "Blorg'nak";
    char *translatedWord = alienLanguageWord_translate(head, alienWord);

    if (translatedWord) {
        printf("Translated word: %s\n", translatedWord);
    } else {
        printf("Word not found.\n");
    }

    return 0;
}