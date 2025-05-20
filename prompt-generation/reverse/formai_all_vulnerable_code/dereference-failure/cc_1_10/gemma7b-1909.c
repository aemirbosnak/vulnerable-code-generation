//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: irregular
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
    Word *wordHead = NULL;
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Split the sentence into words
    char *wordPtr = strtok(sentence, " ");
    while (wordPtr) {
        insertWord(wordHead, wordPtr);
        wordPtr = strtok(NULL, " ");
    }

    // Check for spam words
    char *spamWords[] = {"free", "lottery", "miracle", "prize", "miracle"};
    for (int i = 0; i < 5; i++) {
        Word *word = wordHead;
        while (word) {
            if (strcmp(word->word, spamWords[i]) == 0) {
                printf("Spam word detected: %s\n", word->word);
            }
            word = word->next;
        }
    }

    return 0;
}