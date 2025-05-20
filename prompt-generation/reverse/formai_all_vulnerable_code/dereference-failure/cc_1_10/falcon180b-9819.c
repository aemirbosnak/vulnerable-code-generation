//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} Word;

bool isSpam(char *email) {
    char *words[MAX_WORDS];
    int numWords = 0;
    int spamWordsCount = 0;

    // Split email into words
    char *token = strtok(email, " ");
    while (token!= NULL) {
        if (numWords >= MAX_WORDS) {
            break;
        }
        words[numWords] = strdup(token);
        numWords++;
        token = strtok(NULL, " ");
    }

    // Check if any spam words are present
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i], "free") == 0 || strcmp(words[i], "money") == 0 || strcmp(words[i], "earn") == 0 || strcmp(words[i], "win") == 0) {
            spamWordsCount++;
        }
    }

    // If more than half of the words are spam words, classify as spam
    if (spamWordsCount >= numWords / 2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char email[MAX_WORD_LENGTH];
    printf("Enter email: ");
    fgets(email, MAX_WORD_LENGTH, stdin);

    // Remove newline character
    email[strcspn(email, "\n")] = '\0';

    if (isSpam(email)) {
        printf("Spam\n");
    } else {
        printf("Not spam\n");
    }

    return 0;
}