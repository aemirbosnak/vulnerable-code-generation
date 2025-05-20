//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>

#define MAX_METADATA_LENGTH 1024

int main(int argc, char **argv) {
  // Check if the user has provided a file name.
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the file name from the command line.
  char *file_name = argv[1];

  // Open the file.
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", file_name);
    return EXIT_FAILURE;
  }

  // Read the file contents into a string.
  char *file_contents = NULL;
  long file_size = 0;
  fseek(file, 0, SEEK_END);
  file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  file_contents = malloc(file_size + 1);
  fread(file_contents, 1, file_size, file);
  file_contents[file_size] = '\0';
  fclose(file);

  // Compile the regular expression.
  regex_t regex;
  int regex_compile_status = regcomp(&regex, "<!-- (?<metadata>.+?) -->", REG_EXTENDED);
  if (regex_compile_status != 0) {
    fprintf(stderr, "Error compiling regular expression\n");
    return EXIT_FAILURE;
  }

  // Execute the regular expression on the file contents.
  regmatch_t matches[1];
  int regex_execute_status = regexec(&regex, file_contents, 1, matches, 0);
  if (regex_execute_status != 0) {
    fprintf(stderr, "Error executing regular expression\n");
    return EXIT_FAILURE;
  }

  // Extract the metadata from the file contents.
  char *metadata = NULL;
  if (matches[0].rm_so != -1) {
    metadata = malloc(matches[0].rm_eo - matches[0].rm_so + 1);
    strncpy(metadata, file_contents + matches[0].rm_so, matches[0].rm_eo - matches[0].rm_so);
    metadata[matches[0].rm_eo - matches[0].rm_so] = '\0';
  }

  // Print the metadata.
  printf("%s\n", metadata);

  // Free the allocated memory.
  free(file_contents);
  free(metadata);
  regfree(&regex);

  return EXIT_SUCCESS;
}