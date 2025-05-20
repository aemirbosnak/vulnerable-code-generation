//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

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

int main() {
    Word *words = NULL;

    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Tokenize the sentence into words
    char *word = strtok(sentence, " ");

    while (word) {
        insertWord(words, word);
        word = strtok(NULL, " ");
    }

    // Analyze the words
    for (Word *w = words; w; w = w->next) {
        // Check if the word is a spam word
        if (isSpamWord(w->word)) {
            printf("%s is a spam word.\n", w->word);
        }
    }

    return 0;
}

int isSpamWord(char *word) {
    // List of spam words
    char *spamWords[] = {"free", "lottery", "miracle", "prize", "miracle"};

    for (int i = 0; i < 5; i++) {
        if (strcmp(word, spamWords[i]) == 0) {
            return 1;
        }
    }

    return 0;
}