//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains any spam words
int isSpam(char *str) {
  char *spamWords[] = {"free", "money", "prize", "win", "urgent"};
  int numSpamWords = sizeof(spamWords) / sizeof(char *);

  for (int i = 0; i < numSpamWords; i++) {
    if (strstr(str, spamWords[i]) != NULL) {
      return 1;
    }
  }

  return 0;
}

// Function to print a message if a string is spam
void printSpamMessage(char *str) {
  printf("**Warning: This message may be spam!**\n");
  printf("Message: %s\n", str);
}

// Function to get a string from the user
char *getInput() {
  char *str = malloc(100);
  printf("Enter a message: ");
  scanf("%s", str);
  return str;
}

// Main function
int main() {
  // Get a message from the user
  char *str = getInput();

  // Check if the message is spam
  int isSpamResult = isSpam(str);

  // Print a message if the message is spam
  if (isSpamResult) {
    printSpamMessage(str);
  } else {
    printf("**No spam detected!**\n");
  }

  // Free the memory allocated for the string
  free(str);

  return 0;
}