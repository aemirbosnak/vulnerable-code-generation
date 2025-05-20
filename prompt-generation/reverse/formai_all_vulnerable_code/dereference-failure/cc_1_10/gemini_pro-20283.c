//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in a spam message
#define MAX_WORDS 100

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the minimum number of occurrences of a word to be considered spam
#define MIN_OCCURRENCES 3

// Create a dictionary of words that are commonly found in spam messages
char *spam_words[] = {
    "free",
    "money",
    "offer",
    "win",
    "prize",
    "click",
    "here",
    "now",
    "today",
    "urgent"
};

// Create a function to check if a message is spam
int is_spam(char *message) {
    // Tokenize the message into words
    char *words[MAX_WORDS];
    int num_words = 0;
    char *token = strtok(message, " ");
    while (token != NULL && num_words < MAX_WORDS) {
        words[num_words] = token;
        num_words++;
        token = strtok(NULL, " ");
    }

    // Count the number of occurrences of each word in the dictionary
    int word_counts[MAX_WORDS];
    memset(word_counts, 0, sizeof(word_counts));
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < sizeof(spam_words) / sizeof(char *); j++) {
            if (strcmp(words[i], spam_words[j]) == 0) {
                word_counts[j]++;
            }
        }
    }

    // Check if the number of occurrences of any word in the dictionary is greater than or equal to the minimum number of occurrences
    for (int i = 0; i < sizeof(spam_words) / sizeof(char *); i++) {
        if (word_counts[i] >= MIN_OCCURRENCES) {
            return 1;
        }
    }

    // If no words in the dictionary occur at least the minimum number of times, the message is not spam
    return 0;
}

// Get a message from the user
char *get_message() {
    char *message = malloc(1024);
    printf("Enter a message: ");
    fgets(message, 1024, stdin);
    return message;
}

// Print a message to the console
void print_message(char *message) {
    printf("%s\n", message);
}

// Main function
int main() {
    // Get a message from the user
    char *message = get_message();

    // Check if the message is spam
    int is_spam_result = is_spam(message);

    // Print the result to the console
    if (is_spam_result) {
        print_message("The message is spam.");
    } else {
        print_message("The message is not spam.");
    }

    // Free the memory allocated for the message
    free(message);

    return 0;
}