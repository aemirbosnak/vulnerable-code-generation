//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a message
#define MAX_MESSAGE_LENGTH 1024

// Define the list of spam words
const char *spam_words[] = {"viagra", "free", "money", "offer", "click", "earn", "cash"};

// Define the number of spam words
const int num_spam_words = sizeof(spam_words) / sizeof(spam_words[0]);

// Check if a message contains any spam words
int is_spam(const char *message) {
  // Convert the message to lowercase
  char *message_lower = malloc(strlen(message) + 1);
  strcpy(message_lower, message);
  for (int i = 0; i < strlen(message_lower); i++) {
    message_lower[i] = tolower(message_lower[i]);
  }

  // Check if the message contains any spam words
  for (int i = 0; i < num_spam_words; i++) {
    if (strstr(message_lower, spam_words[i]) != NULL) {
      free(message_lower);
      return 1;
    }
  }

  // The message does not contain any spam words
  free(message_lower);
  return 0;
}

// Prompt the user for a message and check if it is spam
int main() {
  // Prompt the user for a message
  printf("Enter a message: ");
  char message[MAX_MESSAGE_LENGTH];
  fgets(message, MAX_MESSAGE_LENGTH, stdin);

  // Check if the message is spam
  int is_spam_result = is_spam(message);

  // Print the result
  if (is_spam_result) {
    printf("The message is spam.\n");
  } else {
    printf("The message is not spam.\n");
  }

  return 0;
}