//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is the main function.
int main(int argc, char *argv[]) {
  // Check if the user has provided enough arguments.
  if (argc < 2) {
    printf("Usage: %s <email address>\n", argv[0]);
    return 1;
  }

  // Get the email address from the user.
  char *email = argv[1];

  // Check if the email address is valid.
  if (!validate_email(email)) {
    printf("Error: Invalid email address.\n");
    return 1;
  }

  // Check if the email address is in the spam database.
  if (is_spam(email)) {
    printf("Warning: This email address is in the spam database.\n");
  } else {
    printf("This email address is not in the spam database.\n");
  }

  return 0;
}

// This function checks if the email address is valid.
int validate_email(char *email) {
  // Check if the email address is not empty.
  if (strlen(email) == 0) {
    return 0;
  }

  // Check if the email address contains an "@" symbol.
  if (strchr(email, '@') == NULL) {
    return 0;
  }

  // Check if the email address contains a "." symbol.
  if (strchr(email, '.') == NULL) {
    return 0;
  }

  return 1;
}

// This function checks if the email address is in the spam database.
int is_spam(char *email) {
  // Open the spam database file.
  FILE *fp = fopen("spam.txt", "r");
  if (fp == NULL) {
    return 0;
  }

  // Read the spam database file line by line.
  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Check if the email address is in the current line.
    if (strstr(line, email) != NULL) {
      // The email address is in the spam database.
      fclose(fp);
      return 1;
    }
  }

  // The email address is not in the spam database.
  fclose(fp);
  return 0;
}