//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

// Function to tokenize a string into words
void tokenize(char *str, char **tokens) {
    int i = 0;
    char *token;

    while ((token = strtok(str, " \t\n\r\f\v.?!@#$%^&*()_+-=[]{}|;:,.<>"))!= NULL) {
        if (i >= MAX_WORDS) {
            break;
        }
        tokens[i] = token;
        i++;
    }
}

// Function to calculate the spam score of a message
int calculate_spam_score(char **tokens) {
    int i, score = 0;
    char *word;

    // Check for common spam words
    for (i = 0; i < MAX_WORDS; i++) {
        word = tokens[i];
        if (strcmp(word, "free") == 0 || strcmp(word, "win") == 0 || strcmp(word, "earn") == 0 || strcmp(word, "money") == 0) {
            score += 5;
        }
    }

    // Check for excessive capitalization
    for (i = 0; i < MAX_WORDS; i++) {
        word = tokens[i];
        if (isupper(word[0])) {
            score += 2;
        }
    }

    // Check for excessive punctuation
    for (i = 0; i < MAX_WORDS; i++) {
        word = tokens[i];
        int j;
        for (j = 0; j < strlen(word); j++) {
            if (isalpha(word[j]) == 0) {
                score += 2;
            }
        }
    }

    // Check for excessive use of numbers
    for (i = 0; i < MAX_WORDS; i++) {
        word = tokens[i];
        int j;
        for (j = 0; j < strlen(word); j++) {
            if (isdigit(word[j]) == 1) {
                score += 2;
            }
        }
    }

    // Check for excessive use of symbols
    for (i = 0; i < MAX_WORDS; i++) {
        word = tokens[i];
        int j;
        for (j = 0; j < strlen(word); j++) {
            if (isalpha(word[j]) == 0 && isdigit(word[j]) == 0) {
                score += 2;
            }
        }
    }

    return score;
}

int main() {
    char message[1000];
    char *tokens[MAX_WORDS];
    int spam_score;

    printf("Enter a message: ");
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character

    tokenize(message, tokens);
    spam_score = calculate_spam_score(tokens);

    if (spam_score >= 10) {
        printf("The message is likely spam.\n");
    } else {
        printf("The message is likely not spam.\n");
    }

    return 0;
}