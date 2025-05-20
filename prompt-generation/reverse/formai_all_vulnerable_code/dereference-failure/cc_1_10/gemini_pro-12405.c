//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a spam message
#define MAX_SPAM_LENGTH 1024

// Define the number of spam filter rules
#define NUM_SPAM_RULES 5

// Define the spam filter rules
char *spam_rules[] = {
    "Free money!",
    "Click here to win!",
    "You've won a prize!",
    "Your account has been compromised!",
    "Your computer is infected!"
};

// Function to check if a message is spam
int is_spam(char *message) {
    // Convert the message to lowercase
    char *lowercase_message = strdup(message);
    for (int i = 0; lowercase_message[i] != '\0'; i++) {
        lowercase_message[i] = tolower(lowercase_message[i]);
    }

    // Check if the message contains any of the spam filter rules
    for (int i = 0; i < NUM_SPAM_RULES; i++) {
        if (strstr(lowercase_message, spam_rules[i]) != NULL) {
            free(lowercase_message);
            return 1;
        }
    }

    // If the message does not contain any of the spam filter rules, return 0
    free(lowercase_message);
    return 0;
}

// Main function
int main() {
    // Get the message from the user
    char message[MAX_SPAM_LENGTH];
    printf("Enter the message: ");
    fgets(message, MAX_SPAM_LENGTH, stdin);

    // Check if the message is spam
    int is_spam_flag = is_spam(message);

    // Print the result
    if (is_spam_flag) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}