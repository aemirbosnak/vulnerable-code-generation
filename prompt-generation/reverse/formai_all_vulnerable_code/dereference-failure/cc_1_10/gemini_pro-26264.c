//GEMINI-pro DATASET v1.0 Category: File handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum size of the file name
#define MAX_FILE_NAME_SIZE 100

// Define the maximum size of the file content
#define MAX_FILE_CONTENT_SIZE 1000

// Define the number of files to be created
#define NUM_FILES 5

// Define the file extension
#define FILE_EXTENSION ".txt"

// Define the directory path
#define DIRECTORY_PATH "./files/"

// Define the file content
char file_content[] = "This is a test file.\nThis file was created by the program.\n";

// Define the random string function
char *random_string(int length) {
  char *string = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    string[i] = rand() % 26 + 'a';
  }
  string[length] = '\0';
  return string;
}

// Define the create file function
int create_file(char *file_name) {
  // Open the file in write mode
  FILE *file = fopen(file_name, "w");
  if (file == NULL) {
    return -1;
  }

  // Write the file content to the file
  fwrite(file_content, sizeof(char), strlen(file_content), file);

  // Close the file
  fclose(file);

  return 0;
}

// Define the main function
int main() {
  // Initialize the random seed
  srand(time(NULL));

  // Create the directory if it does not exist
  if (mkdir(DIRECTORY_PATH, 0777) != 0) {
    perror("mkdir");
    return -1;
  }

  // Create the files
  for (int i = 0; i < NUM_FILES; i++) {
    // Generate a random file name
    char file_name[MAX_FILE_NAME_SIZE];
    strcpy(file_name, DIRECTORY_PATH);
    strcat(file_name, random_string(10));
    strcat(file_name, FILE_EXTENSION);

    // Create the file
    if (create_file(file_name) != 0) {
      perror("create_file");
      return -1;
    }

    printf("Created file: %s\n", file_name);
  }

  return 0;
}