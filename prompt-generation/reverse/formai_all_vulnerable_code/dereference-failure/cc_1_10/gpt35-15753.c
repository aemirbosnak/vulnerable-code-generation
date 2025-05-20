//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 1048576 // 1MB

// function to scan a file for any viruses
void scanFile(char* filename) {
  char virusSignature[] = "virus"; // signature to check for virus
  char* buffer = (char*) malloc(MAX_FILE_SIZE); // buffer to read in file contents
  size_t bytesRead = 0; // number of bytes read from file
  FILE* file = fopen(filename, "rb"); // open file in binary mode

  if (file == NULL) { // check if file couldn't be opened
    printf("Error: could not open file %s\n", filename);
    return;
  }

  // read in file contents to buffer
  bytesRead = fread(buffer, 1, MAX_FILE_SIZE, file);
  fclose(file); // close the file

  if (bytesRead == 0) { // check if file is empty
    printf("Warning: file %s is empty\n", filename);
    return;
  }

  // check if virus signature is present in file contents
  if (strstr(buffer, virusSignature) != NULL) {
    printf("The file %s contains the virus signature!\n", filename);
  } else {
    printf("The file %s is clean\n", filename);
  }

  free(buffer); // free the dynamically allocated memory
}

int main() {
  char filename[MAX_FILENAME_LENGTH]; // variable to store filename input by user

  printf("Welcome to our Unique C Antivirus Scanner!\n");

  while (1) { // loop until user inputs "exit"
    printf("\nEnter the filename you want to scan (or 'exit' to quit): ");
    scanf("%s", filename);

    if (strcmp(filename, "exit") == 0) { // check if user wants to quit
      printf("\nThank you for using our Unique C Antivirus Scanner!\n");
      break; // exit the loop
    }

    // call the scanFile function to scan the file
    scanFile(filename);
  }

  return 0;
}