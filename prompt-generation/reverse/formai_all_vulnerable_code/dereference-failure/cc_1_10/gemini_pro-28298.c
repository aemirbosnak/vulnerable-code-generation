//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a message
#define MAX_MESSAGE_LENGTH 1024

// Define the number of spam words to check for
#define NUM_SPAM_WORDS 10

// Define the spam words
const char *spamWords[] = {
  "free",
  "money",
  "win",
  "prize",
  "offer",
  "discount",
  "sale",
  "click",
  "subscribe",
  "unsubscribe"
};

// Check if a message is spam
int isSpam(char *message) {
  // Convert the message to lowercase
  for (int i = 0; i < strlen(message); i++) {
    message[i] = tolower(message[i]);
  }

  // Check for spam words
  for (int i = 0; i < NUM_SPAM_WORDS; i++) {
    if (strstr(message, spamWords[i]) != NULL) {
      return 1;
    }
  }

  // The message is not spam
  return 0;
}

// Print a message indicating if the message is spam or not
void printSpamStatus(char *message) {
  if (isSpam(message)) {
    printf("The message is spam.\n");
  } else {
    printf("The message is not spam.\n");
  }
}

// Get a message from the user
char *getMessage() {
  // Allocate memory for the message
  char *message = malloc(MAX_MESSAGE_LENGTH);

  // Get the message from the user
  printf("Enter a message: ");
  fgets(message, MAX_MESSAGE_LENGTH, stdin);

  // Return the message
  return message;
}

// Main function
int main() {
  // Get a message from the user
  char *message = getMessage();

  // Check if the message is spam
  printSpamStatus(message);

  // Free the memory allocated for the message
  free(message);

  return 0;
}