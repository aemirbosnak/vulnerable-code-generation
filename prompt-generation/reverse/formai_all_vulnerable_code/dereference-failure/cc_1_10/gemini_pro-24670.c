//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main() {
  // Open the log file
  FILE *logFile = fopen("log.txt", "r");
  if (logFile == NULL) {
    perror("Error opening log file");
    return EXIT_FAILURE;
  }

  // Define the regular expression
  const char *pattern = "^\\[(.*?)\\]\\s+(.*)$";
  regex_t regex;
  int reti = regcomp(&regex, pattern, REG_EXTENDED);
  if (reti != 0) {
    fprintf(stderr, "Error compiling regex: %s\n", strerror(reti));
    return EXIT_FAILURE;
  }

  // Read the log file line by line
  char line[1024];
  while (fgets(line, sizeof(line), logFile) != NULL) {
    // Match the line against the regular expression
    regmatch_t matches[2];
    reti = regexec(&regex, line, 2, matches, 0);
    if (reti != 0) {
      fprintf(stderr, "Error matching line: %s\n", strerror(reti));
      continue;
    }

    // Extract the timestamp and message from the line
    char timestamp[20];
    strncpy(timestamp, line + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
    char message[1024];
    strncpy(message, line + matches[2].rm_so, matches[2].rm_eo - matches[2].rm_so);

    // Print the timestamp and message
    printf("%s %s\n", timestamp, message);
  }

  // Close the log file
  fclose(logFile);

  // Free the regular expression
  regfree(&regex);

  return EXIT_SUCCESS;
}