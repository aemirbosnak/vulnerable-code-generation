//Gemma-7B DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERROR_BUFFER_SIZE 256

typedef struct Error {
  char *error_message;
  int error_code;
} Error;

Error *createError(int error_code, char *error_message) {
  Error *error = malloc(sizeof(Error));
  error->error_code = error_code;
  error->error_message = strdup(error_message);
  return error;
}

void handleError(Error *error) {
  fprintf(stderr, "Error: %s (Code: %d)\n", error->error_message, error->error_code);
  exit(1);
}

int main() {
  Error *error = NULL;
  char *filename = "my_file.txt";

  // Open file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    error = createError(1, "Error opening file");
    handleError(error);
  }

  // Read file contents
  char buffer[MAX_ERROR_BUFFER_SIZE];
  int read_size = fread(buffer, 1, MAX_ERROR_BUFFER_SIZE, file);
  if (read_size == 0) {
    error = createError(2, "Error reading file");
    handleError(error);
  }

  // Close file
  fclose(file);

  // Print file contents
  printf("%s", buffer);

  return 0;
}