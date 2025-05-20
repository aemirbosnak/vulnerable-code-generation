//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char* word;
    int count;
} WordCount;

int main() {
    char email[MAX_EMAIL_LENGTH];
    char word[MAX_WORD_LENGTH];
    char* words[MAX_WORDS];
    int numWords = 0;
    int spamCount = 0;
    int i;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Read in the email
    printf("Enter an email: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);

    // Remove the newline character at the end of the email
    email[strcspn(email, "\n")] = '\0';

    // Convert the email to lowercase
    for (i = 0; email[i]!= '\0'; i++) {
        email[i] = tolower(email[i]);
    }

    // Count the number of words in the email
    char* token = strtok(email, " ");
    while (token!= NULL) {
        if (numWords >= MAX_WORDS) {
            break;
        }
        words[numWords] = strdup(token);
        numWords++;
        token = strtok(NULL, " ");
    }

    // Check each word for spammyness
    for (i = 0; i < numWords; i++) {
        spamCount += isSpamWord(words[i])? 1 : 0;
    }

    // Print the result
    if (spamCount >= numWords / 2) {
        printf("SPAM!\n");
    } else {
        printf("Not spam.\n");
    }

    return 0;
}

// Returns 1 if the word is a spam word, 0 otherwise
int isSpamWord(char* word) {
    // TODO: Implement spam word detection algorithm
    return rand() % 2;
}