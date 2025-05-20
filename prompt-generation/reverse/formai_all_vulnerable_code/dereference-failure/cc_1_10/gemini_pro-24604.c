//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct to represent a spam message.
struct spam_msg {
    char *text;
    int length;
};

// Declare a function to tokenize a string.
char **tokenize(char *str, char *delim);

// Declare a function to check if a string contains a spam keyword.
int contains_spam_keyword(char *str);

// Declare a function to classify a message as spam or not.
int classify_msg(struct spam_msg *msg);

// Main function.
int main() {
    // Get the message text from the user.
    char *text = NULL;
    size_t len = 0;
    getline(&text, &len, stdin);

    // Create a spam message struct.
    struct spam_msg msg;
    msg.text = text;
    msg.length = strlen(text);

    // Tokenize the message text.
    char **tokens = tokenize(text, " ");

    // Check if the message contains any spam keywords.
    int is_spam = 0;
    for (int i = 0; tokens[i] != NULL; i++) {
        if (contains_spam_keyword(tokens[i])) {
            is_spam = 1;
            break;
        }
    }

    // Classify the message as spam or not.
    int classification = classify_msg(&msg);

    // Print the classification result.
    if (classification == 1) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    // Free the allocated memory.
    free(text);
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}

// Function to tokenize a string.
char **tokenize(char *str, char *delim) {
    char **tokens = NULL;
    int num_tokens = 0;

    // Count the number of tokens in the string.
    char *token = strtok(str, delim);
    while (token != NULL) {
        num_tokens++;
        token = strtok(NULL, delim);
    }

    // Allocate memory for the tokens.
    tokens = malloc(sizeof(char *) * (num_tokens + 1));

    // Tokenize the string.
    token = strtok(str, delim);
    int i = 0;
    while (token != NULL) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, delim);
    }

    // Set the last token to NULL.
    tokens[num_tokens] = NULL;

    return tokens;
}

// Function to check if a string contains a spam keyword.
int contains_spam_keyword(char *str) {
    char *spam_keywords[] = {"Viagra", "Cialis", "Levitra", "penis", "sex"};

    for (int i = 0; i < sizeof(spam_keywords) / sizeof(char *); i++) {
        if (strstr(str, spam_keywords[i]) != NULL) {
            return 1;
        }
    }

    return 0;
}

// Function to classify a message as spam or not.
int classify_msg(struct spam_msg *msg) {
    // Check if the message contains any spam keywords.
    for (int i = 0; i < msg->length; i++) {
        if (contains_spam_keyword(&msg->text[i])) {
            return 1;
        }
    }

    // Check if the message is written in ALL CAPS.
    int is_all_caps = 1;
    for (int i = 0; i < msg->length; i++) {
        if (islower(msg->text[i])) {
            is_all_caps = 0;
            break;
        }
    }

    // Check if the message contains multiple exclamation marks.
    int num_exclamation_marks = 0;
    for (int i = 0; i < msg->length; i++) {
        if (msg->text[i] == '!') {
            num_exclamation_marks++;
        }
    }

    // Classify the message as spam if it meets any of the following criteria:
    // - Contains a spam keyword
    // - Written in ALL CAPS
    // - Contains multiple exclamation marks
    if (contains_spam_keyword(msg->text) || is_all_caps || num_exclamation_marks > 1) {
        return 1;
    }

    return 0;
}