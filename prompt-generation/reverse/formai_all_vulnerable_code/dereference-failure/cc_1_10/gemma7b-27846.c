//Gemma-7B DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handleError(int err, char **errorMessage) {
  errorMessage = malloc(err * sizeof(char));
  errorMessage[0] = '\0';
  switch (err) {
    case 1:
      strcpy(errorMessage, "Invalid input.");
      break;
    case 2:
      strcpy(errorMessage, "File not found.");
      break;
    case 3:
      strcpy(errorMessage, "Memory allocation failed.");
      break;
    default:
      strcpy(errorMessage, "Unknown error.");
      break;
  }
  printf("Error: %s\n", errorMessage);
  free(errorMessage);
  exit(1);
}

int main() {
  char **errorMessage = NULL;
  int result = 0;

  // Attempt to open a non-existent file
  FILE *file = fopen("does_not_exist.txt", "r");
  if (file == NULL) {
    handleError(2, errorMessage);
  }

  // Read data from the file (that doesn't exist)
  char data[1024];
  size_t readBytes = fread(data, 1, 1024, file);
  if (readBytes == 0) {
    handleError(1, errorMessage);
  }

  // Print the data
  printf("Data: %s\n", data);

  // Close the file
  fclose(file);

  return 0;
}