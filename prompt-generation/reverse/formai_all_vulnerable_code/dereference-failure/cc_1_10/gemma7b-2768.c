//Gemma-7B DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERROR_MESSAGE_LENGTH 256

typedef struct Error {
  char *message;
  int code;
} Error;

Error *createError(int code, char *message) {
  Error *error = malloc(sizeof(Error));
  error->message = strdup(message);
  error->code = code;
  return error;
}

void handleError(Error *error) {
  fprintf(stderr, "Error: %s (Code: %d)\n", error->message, error->code);
  exit(1);
}

int main() {
  char *filename = "test.txt";
  FILE *file = NULL;

  // Attempt to open the file
  file = fopen(filename, "r");
  if (file == NULL) {
    Error *error = createError(1, "File not found");
    handleError(error);
  }

  // Read data from the file
  char buffer[1024];
  int readBytes = fread(buffer, 1, 1024, file);

  // Check if the read was successful
  if (readBytes == 0) {
    Error *error = createError(2, "Read error");
    handleError(error);
  }

  // Close the file
  fclose(file);

  // Print the data
  printf("%s", buffer);

  return 0;
}