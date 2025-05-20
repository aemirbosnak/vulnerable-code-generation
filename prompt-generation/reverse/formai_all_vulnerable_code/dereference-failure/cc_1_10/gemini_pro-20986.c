//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <libgen.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  // Check if the user has provided a file name.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the file.
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Read the file contents into a buffer.
  char buffer[MAX_BUFFER_SIZE];
  size_t buffer_size = fread(buffer, 1, MAX_BUFFER_SIZE, file);
  if (buffer_size == 0) {
    fprintf(stderr, "Error reading file: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Close the file.
  fclose(file);

  // Extract the metadata from the buffer.
  char *metadata = NULL;
  regex_t regex;
  int regex_result = regcomp(&regex, "<meta name=\"(\\w+)\" content=\"(\\S+)\" />", REG_EXTENDED);
  if (regex_result != 0) {
    fprintf(stderr, "Error compiling regular expression: %s\n", strerror(regex_result));
    return EXIT_FAILURE;
  }

  regmatch_t matches[3];
  while (regexec(&regex, buffer, 3, matches, 0) == 0) {
    char *name = buffer + matches[1].rm_so;
    name[matches[1].rm_eo - matches[1].rm_so] = '\0';
    char *content = buffer + matches[2].rm_so;
    content[matches[2].rm_eo - matches[2].rm_so] = '\0';
    metadata = realloc(metadata, strlen(metadata) + strlen(name) + strlen(content) + 3);
    strcat(metadata, name);
    strcat(metadata, ": ");
    strcat(metadata, content);
    strcat(metadata, "\n");
  }

  regfree(&regex);

  // Print the metadata.
  printf("%s\n", metadata);

  // Free the allocated memory.
  free(metadata);

  return EXIT_SUCCESS;
}