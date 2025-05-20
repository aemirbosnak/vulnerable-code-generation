//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our own error codes.
#define ERROR_INVALID_ARGUMENT 1
#define ERROR_OUT_OF_MEMORY 2
#define ERROR_FILE_NOT_FOUND 3

// Define our own error handling function.
void handle_error(int error_code) {
  switch (error_code) {
    case ERROR_INVALID_ARGUMENT:
      printf("Error: Invalid argument.\n");
      break;
    case ERROR_OUT_OF_MEMORY:
      printf("Error: Out of memory.\n");
      break;
    case ERROR_FILE_NOT_FOUND:
      printf("Error: File not found.\n");
      break;
    default:
      printf("Error: Unknown error.\n");
  }

  // Exit the program with the appropriate error code.
  exit(error_code);
}

// Define our main function.
int main(int argc, char *argv[]) {
  // Check if the user provided the correct number of arguments.
  if (argc != 2) {
    handle_error(ERROR_INVALID_ARGUMENT);
  }

  // Open the file specified by the user.
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    handle_error(ERROR_FILE_NOT_FOUND);
  }

  // Read the file contents into a buffer.
  char buffer[1024];
  size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
  if (bytes_read == 0) {
    handle_error(ERROR_OUT_OF_MEMORY);
  }

  // Close the file.
  fclose(file);

  // Print the file contents to the console.
  printf("%s", buffer);

  return 0;
}