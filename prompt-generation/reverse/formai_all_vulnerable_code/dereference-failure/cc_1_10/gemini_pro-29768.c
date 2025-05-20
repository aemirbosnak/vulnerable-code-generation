//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a blacklist of known spam words
char *spam_words[] = {"free", "money", "offer", "click", "win"};

// Check if a message contains any spam words
int is_spam(char *message) {
  // Convert the message to lowercase for easier comparison
  char *lower_message = strdup(message);
  for (int i = 0; i < strlen(lower_message); i++) {
    lower_message[i] = tolower(lower_message[i]);
  }

  // Check if any spam words are present in the message
  for (int i = 0; i < sizeof(spam_words) / sizeof(char *); i++) {
    if (strstr(lower_message, spam_words[i]) != NULL) {
      free(lower_message);
      return 1;
    }
  }

  // No spam words found, so the message is not spam
  free(lower_message);
  return 0;
}

// Get a message from the user
char *get_message() {
  char *message = NULL;
  size_t len = 0;
  getline(&message, &len, stdin);
  return message;
}

// Print a message to the user
void print_message(char *message) {
  printf("%s\n", message);
}

// Main function
int main() {
  // Get a message from the user
  char *message = get_message();

  // Check if the message is spam
  int is_spam_flag = is_spam(message);

  // Print a message to the user
  if (is_spam_flag) {
    print_message("This message is spam.");
  } else {
    print_message("This message is not spam.");
  }

  // Free the allocated memory
  free(message);

  return 0;
}