//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  ERR_NONE,
  ERR_FILE_OPEN,
  ERR_FILE_READ,
  ERR_FILE_WRITE,
  ERR_MEMORY_ALLOC,
  ERR_INVALID_ARG,
  ERR_UNKNOWN
} ErrorCodes;

const char *error_messages[] = {
  "No error",
  "Could not open file",
  "Could not read from file",
  "Could not write to file",
  "Could not allocate memory",
  "Invalid argument",
  "Unknown error"
};

void print_error(ErrorCodes error) {
  fprintf(stderr, "Error: %s\n", error_messages[error]);
}

int main(void) {
  FILE *file;
  char *buffer;

  // Open the file
  file = fopen("test.txt", "r");
  if (file == NULL) {
    print_error(ERR_FILE_OPEN);
    return EXIT_FAILURE;
  }

  // Allocate memory for the buffer
  buffer = malloc(1024);
  if (buffer == NULL) {
    print_error(ERR_MEMORY_ALLOC);
    return EXIT_FAILURE;
  }

  // Read from the file
  if (fread(buffer, 1, 1024, file) != 1024) {
    print_error(ERR_FILE_READ);
    return EXIT_FAILURE;
  }

  // Write to the file
  if (fwrite(buffer, 1, 1024, file) != 1024) {
    print_error(ERR_FILE_WRITE);
    return EXIT_FAILURE;
  }

  // Close the file
  if (fclose(file) != 0) {
    print_error(ERR_FILE_OPEN);
    return EXIT_FAILURE;
  }

  // Free the memory
  free(buffer);

  // Return success
  return EXIT_SUCCESS;
}