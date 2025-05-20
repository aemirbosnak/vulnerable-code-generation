//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1024

int main() {

  // Allocate memory for tokens and metadata
  char **tokens = NULL;
  char **metadata = NULL;
  int token_count = 0;

  // Open the file containing text and metadata
  FILE *fp = fopen("mytext.txt", "r");

  // Read the file and process each line
  char line[1024];
  while (fgets(line, 1024, fp) != NULL) {
    // Tokenize the line
    char **tokens_temp = NULL;
    int token_count_temp = 0;
    char *token = strtok(line, ";");
    while (token) {
      tokens_temp = realloc(tokens_temp, (token_count_temp + 1) * sizeof(char *));
      tokens_temp[token_count_temp++] = token;
      token = strtok(NULL, ";");
    }

    // Extract metadata from the tokens
    for (int i = 0; i < token_count_temp; i++) {
      if (tokens_temp[i][0] == '#') {
        metadata = realloc(metadata, (token_count + 1) * sizeof(char *));
        metadata[token_count++] = strdup(tokens_temp[i] + 1);
      }
    }

    // Free memory and close the file
    free(tokens_temp);
    fclose(fp);
  }

  // Print the extracted metadata
  for (int i = 0; i < token_count; i++) {
    printf("%s\n", metadata[i]);
  }

  // Free memory
  free(tokens);
  free(metadata);

  return 0;
}