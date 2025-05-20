//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_PATTERN_LENGTH 128

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <email address> <pattern>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Compile the regular expression pattern
  regex_t regex;
  int err = regcomp(&regex, argv[2], REG_ICASE);
  if (err != 0) {
    char error_message[MAX_PATTERN_LENGTH];
    regerror(err, &regex, error_message, sizeof(error_message));
    fprintf(stderr, "Error compiling regular expression pattern: %s\n", error_message);
    return EXIT_FAILURE;
  }

  // Check if the email address matches the pattern
  char *email_address = argv[1];
  size_t email_address_length = strlen(email_address);
  if (email_address_length > MAX_EMAIL_LENGTH) {
    fprintf(stderr, "Error: Email address too long (max length: %d)\n", MAX_EMAIL_LENGTH);
    return EXIT_FAILURE;
  }

  regmatch_t match;
  err = regexec(&regex, email_address, 1, &match, 0);
  if (err != 0) {
    char error_message[MAX_PATTERN_LENGTH];
    regerror(err, &regex, error_message, sizeof(error_message));
    fprintf(stderr, "Error matching email address to pattern: %s\n", error_message);
    return EXIT_FAILURE;
  }

  // Print the result
  if (match.rm_so == -1) {
    printf("Email address does not match pattern\n");
  } else {
    printf("Email address matches pattern\n");
  }

  // Free the compiled regular expression
  regfree(&regex);

  return EXIT_SUCCESS;
}