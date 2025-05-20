//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: romantic
#include <stdio.h>
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

int translateCCat(Word *head) {
    int i = 0;
    Word *currentWord = head;

    while (currentWord) {
        char *translatedWord = malloc(MAX_WORDS);

        for (i = 0; currentWord->word[i] != '\0'; i++) {
            switch (currentWord->word[i]) {
                case 'a':
                    translatedWord[i] = 'a';
                    break;
                case 'e':
                    translatedWord[i] = 'e';
                    break;
                case 'i':
                    translatedWord[i] = 'i';
                    break;
                case 'o':
                    translatedWord[i] = 'o';
                    break;
                case 'u':
                    translatedWord[i] = 'u';
                    break;
                default:
                    translatedWord[i] = currentWord->word[i];
            }
        }

        translatedWord[i] = '\0';

        printf("%s\n", translatedWord);
        free(translatedWord);

        currentWord = currentWord->next;
    }

    return 0;
}

int main() {
    Word *head = insertWord(NULL, "Meow");
    insertWord(head, "Purr");
    insertWord(head, "Meowingly");

    translateCCat(head);

    return 0;
}