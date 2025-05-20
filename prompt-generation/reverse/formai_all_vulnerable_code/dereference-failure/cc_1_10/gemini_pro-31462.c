//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  char sourceFile[100], targetFile[100];
  FILE *source, *target;

  // Prompt the user for the source file name
  printf("Enter the source file name: ");
  scanf("%s", sourceFile);

  // Prompt the user for the target file name
  printf("Enter the target file name: ");
  scanf("%s", targetFile);

  // Open the source file for reading
  source = fopen(sourceFile, "r");

  // Check if the source file was opened successfully
  if (source == NULL) {
    printf("Error opening the source file: %s", sourceFile);
    return 1;
  }

  // Open the target file for writing
  target = fopen(targetFile, "w");

  // Check if the target file was opened successfully
  if (target == NULL) {
    printf("Error opening the target file: %s", targetFile);
    return 1;
  }

  // Copy the contents of the source file to the target file
  char buffer[1024];
  while (fread(buffer, 1, sizeof(buffer), source) != 0) {
    fwrite(buffer, 1, sizeof(buffer), target);
  }

  // Close the source file
  fclose(source);

  // Close the target file
  fclose(target);

  // Print a success message
  printf("File backup complete!");

  return 0;
}