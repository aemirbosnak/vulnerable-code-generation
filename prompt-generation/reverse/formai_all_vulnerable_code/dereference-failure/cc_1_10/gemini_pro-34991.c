//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SPAM_WORDS 100
#define MAX_EMAIL_LENGTH 1000

// Array of spam words
char *spamWords[MAX_SPAM_WORDS] = {
    "free",
    "money",
    "win",
    "click",
    "offer",
    "sale",
    "discount",
    "limited time",
    "act now",
    "don't miss out"
};

// Function to check if a word is a spam word
bool isSpamWord(char *word) {
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strcmp(word, spamWords[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to calculate the spam score of an email
int calculateSpamScore(char *email) {
    int score = 0;

    // Convert the email to lowercase
    char *emailLowercase = malloc(MAX_EMAIL_LENGTH);
    strcpy(emailLowercase, email);
    for (int i = 0; i < strlen(emailLowercase); i++) {
        emailLowercase[i] = tolower(emailLowercase[i]);
    }

    // Split the email into words
    char *words[MAX_SPAM_WORDS];
    int numWords = 0;
    char *token = strtok(emailLowercase, " ");
    while (token != NULL) {
        words[numWords] = token;
        numWords++;
        token = strtok(NULL, " ");
    }

    // Check each word for spam
    for (int i = 0; i < numWords; i++) {
        if (isSpamWord(words[i])) {
            score++;
        }
    }

    free(emailLowercase);
    return score;
}

// Function to classify an email as spam or not
bool isSpam(char *email, int spamScoreThreshold) {
    int score = calculateSpamScore(email);
    return score >= spamScoreThreshold;
}

// Main function
int main() {
    // Get the email from the user
    char email[MAX_EMAIL_LENGTH];
    printf("Enter the email: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);

    // Calculate the spam score of the email
    int spamScore = calculateSpamScore(email);

    // Print the spam score
    printf("Spam score: %d\n", spamScore);

    // Classify the email as spam or not
    bool isSpamBool = isSpam(email, 5);

    // Print whether the email is spam or not
    if (isSpamBool) {
        printf("The email is spam.\n");
    } else {
        printf("The email is not spam.\n");
    }

    return 0;
}