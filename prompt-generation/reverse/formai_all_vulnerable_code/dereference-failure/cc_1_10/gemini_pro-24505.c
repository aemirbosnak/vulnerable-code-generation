//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Error {
  NO_ERROR,
  INVALID_INPUT,
  MEMORY_ALLOC_FAILED,
  FILE_OPEN_FAILED,
  FILE_READ_FAILED,
  FILE_WRITE_FAILED,
  UNKNOWN_ERROR
};

typedef struct {
  const char *message;
  enum Error error;
} ErrorInfo;

const ErrorInfo errors[] = {
  { "Invalid input", INVALID_INPUT },
  { "Memory allocation failed", MEMORY_ALLOC_FAILED },
  { "File open failed", FILE_OPEN_FAILED },
  { "File read failed", FILE_READ_FAILED },
  { "File write failed", FILE_WRITE_FAILED },
  { "Unknown error", UNKNOWN_ERROR }
};

int main() {
  // Declare our variables.
  char *input = NULL;
  FILE *file = NULL;
  char buffer[1024];
  int bytes_read;
  enum Error error = NO_ERROR;

  // Get the user's input.
  printf("My dearest, enter your sweet nothings: ");
  input = malloc(1024);
  if (input == NULL) {
    error = MEMORY_ALLOC_FAILED;
    goto cleanup;
  }
  fgets(input, 1024, stdin);

  // Open the file for writing.
  file = fopen("love_letter.txt", "w");
  if (file == NULL) {
    error = FILE_OPEN_FAILED;
    goto cleanup;
  }

  // Write the user's input to the file.
  bytes_read = strlen(input);
  if (fwrite(input, bytes_read, 1, file) != 1) {
    error = FILE_WRITE_FAILED;
    goto cleanup;
  }

  // Close the file.
  if (fclose(file) == EOF) {
    error = FILE_WRITE_FAILED;
    goto cleanup;
  }

cleanup:
  // Free the memory we allocated.
  free(input);

  // Print the error message if there was one.
  if (error != NO_ERROR) {
    const ErrorInfo *err_info = &errors[error];
    printf("Alas, my love, we have encountered a difficulty: %s\n", err_info->message);
    return err_info->error;
  }

  // All's well that ends well.
  printf("Your words have been preserved for eternity, my love.\n");
  return NO_ERROR;
}