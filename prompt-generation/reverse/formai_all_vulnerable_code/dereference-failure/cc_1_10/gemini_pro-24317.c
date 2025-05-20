//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main() {
  // Define the regular expression pattern for log entries
  const char *pattern = "^\\[(?<timestamp>[^\\]]+)\\] \\[(?<level>[^\\]]+)\\] \\[(?<source>[^\\]]+)\\] (?<message>.*)$";
  regex_t regex;
  int reti;

  // Compile the regular expression
  reti = regcomp(&regex, pattern, REG_EXTENDED);
  if (reti) {
    fprintf(stderr, "Could not compile regular expression: %s\n", strerror(reti));
    return 1;
  }

  // Open the log file for reading
  FILE *fp = fopen("log.txt", "r");
  if (!fp) {
    perror("fopen");
    return 1;
  }

  // Buffer for line of text from the log file
  char line[1024];

  // Loop through each line of the log file
  while (fgets(line, sizeof(line), fp)) {
    // Initialize the match data
    regmatch_t matches[5];

    // Perform the regular expression match
    reti = regexec(&regex, line, 5, matches, 0);
    if (!reti) {
      // If the line matches the regular expression, extract the captured groups
      char *timestamp = line + matches[1].rm_so;
      timestamp[matches[1].rm_eo - matches[1].rm_so] = '\0';

      char *level = line + matches[2].rm_so;
      level[matches[2].rm_eo - matches[2].rm_so] = '\0';

      char *source = line + matches[3].rm_so;
      source[matches[3].rm_eo - matches[3].rm_so] = '\0';

      char *message = line + matches[4].rm_so;
      message[matches[4].rm_eo - matches[4].rm_so] = '\0';

      // Print the extracted data
      printf("%s %s %s %s\n", timestamp, level, source, message);
    } else if (reti == REG_NOMATCH) {
      // If the line doesn't match the regular expression, ignore it
      continue;
    } else {
      // If there was an error performing the match, print an error message
      fprintf(stderr, "regexec failed: %s\n", strerror(reti));
      return 1;
    }
  }

  // Close the log file
  fclose(fp);

  // Free the compiled regular expression
  regfree(&regex);

  return 0;
}