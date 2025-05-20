//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to store spam keywords and their weights
typedef struct SpamKeyword {
    char keyword[256];
    int weight;
} SpamKeyword;

// Array of spam keywords and their weights
const SpamKeyword spamKeywords[] = {
    {"viagra", 100},
    {"cialis", 100},
    {"levitra", 100},
    {"free", 50},
    {"money", 50},
    {"win", 50},
    {"click", 25},
    {"here", 25},
    {"get", 25},
    {"now", 25},
    {"urgent", 25},
};

// Function to calculate the spam score of a given message
int calculateSpamScore(char *message) {
    int score = 0;

    // Convert the message to lowercase for easier comparison
    char *lowercaseMessage = strdup(message);
    for (int i = 0; lowercaseMessage[i] != '\0'; i++) {
        lowercaseMessage[i] = tolower(lowercaseMessage[i]);
    }

    // Check for the presence of each spam keyword in the message
    for (int i = 0; i < sizeof(spamKeywords) / sizeof(SpamKeyword); i++) {
        if (strstr(lowercaseMessage, spamKeywords[i].keyword) != NULL) {
            score += spamKeywords[i].weight;
        }
    }

    free(lowercaseMessage);

    return score;
}

// Main function
int main() {
    // Get the user input message
    char message[1024];
    printf("Enter the message to check for spam: ");
    fgets(message, sizeof(message), stdin);

    // Calculate the spam score of the message
    int score = calculateSpamScore(message);

    // Print the spam score
    printf("Spam score: %d\n", score);

    // Determine if the message is spam or not based on the score
    if (score > 100) {
        printf("The message is likely spam.\n");
    } else {
        printf("The message is not likely spam.\n");
    }

    return 0;
}