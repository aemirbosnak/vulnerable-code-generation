//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
    Word *newNode = malloc(sizeof(Word));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int main() {
    Word *words = NULL;
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Tokenize the sentence
    char *word = strtok(sentence, " ");

    // Insert each word into the list
    while (word) {
        words = insertWord(words, word);
        word = strtok(NULL, " ");
    }

    // Check for spam words
    char *spamWords[] = {"free", "lottery", "miracle", "prize", "miracle"};
    int numSpamWords = 5;

    for (int i = 0; i < numSpamWords; i++) {
        Word *currentWord = words;

        while (currentWord) {
            if (strcmp(currentWord->word, spamWords[i]) == 0) {
                printf("Warning: The word '%s' is considered spam.\n", currentWord->word);
            }
            currentWord = currentWord->next;
        }
    }

    return 0;
}