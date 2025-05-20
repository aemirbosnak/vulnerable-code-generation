//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a message
#define MAX_MESSAGE_LENGTH 1024

// Define the list of spam keywords
char *spam_keywords[] = {"free", "money", "win", "prize", "offer", "click", "subscribe"};

// Define the number of spam keywords
#define NUM_SPAM_KEYWORDS 7

// Function to check if a message contains any spam keywords
int is_spam(char *message) {
  // Convert the message to lowercase
  char *lowercase_message = strdup(message);
  for (int i = 0; i < strlen(lowercase_message); i++) {
    lowercase_message[i] = tolower(lowercase_message[i]);
  }

  // Check if the message contains any spam keywords
  for (int i = 0; i < NUM_SPAM_KEYWORDS; i++) {
    if (strstr(lowercase_message, spam_keywords[i]) != NULL) {
      free(lowercase_message);
      return 1;
    }
  }

  // The message does not contain any spam keywords
  free(lowercase_message);
  return 0;
}

// Main function
int main() {
  // Get the message from the user
  char message[MAX_MESSAGE_LENGTH];
  printf("Enter a message: ");
  fgets(message, MAX_MESSAGE_LENGTH, stdin);

  // Check if the message is spam
  if (is_spam(message)) {
    printf("The message is spam.\n");
  } else {
    printf("The message is not spam.\n");
  }

  return 0;
}