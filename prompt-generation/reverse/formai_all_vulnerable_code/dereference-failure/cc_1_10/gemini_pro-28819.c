//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a spam message
#define MAX_MESSAGE_LENGTH 1024

// Define the list of spam words
char *spam_words[] = {
  "free", "cash", "win", "prize", "offer", "click", "subscribe", "unsubscribe", "cancel", "delete"
};

// Define the number of spam words
int num_spam_words = sizeof(spam_words) / sizeof(char *);

// Check if a message is spam
int is_spam(char *message) {
  // Tokenize the message
  char *tokens = strtok(message, " ");

  // Loop through the tokens
  while (tokens != NULL) {
    // Check if the token is a spam word
    for (int i = 0; i < num_spam_words; i++) {
      if (strcmp(tokens, spam_words[i]) == 0) {
        return 1;
      }
    }

    // Get the next token
    tokens = strtok(NULL, " ");
  }

  // The message is not spam
  return 0;
}

// Get a message from the user
char *get_message() {
  // Allocate memory for the message
  char *message = malloc(MAX_MESSAGE_LENGTH);

  // Get the message from the user
  printf("Enter your message: ");
  fgets(message, MAX_MESSAGE_LENGTH, stdin);

  // Return the message
  return message;
}

// Main function
int main() {
  // Get a message from the user
  char *message = get_message();

  // Check if the message is spam
  int is_spam_result = is_spam(message);

  // Print the result
  if (is_spam_result) {
    printf("Your message is spam.\n");
  } else {
    printf("Your message is not spam.\n");
  }

  // Free the memory allocated for the message
  free(message);

  return 0;
}