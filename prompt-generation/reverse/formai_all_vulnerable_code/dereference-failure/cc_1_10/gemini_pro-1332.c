//GEMINI-pro DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to write a string to a file
int write_to_file(char *filename, char *string) {
  // Open the file in write mode
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    return 1;  // Error opening the file
  }

  // Write the string to the file
  int bytes_written = fwrite(string, 1, strlen(string), file);
  if (bytes_written != strlen(string)) {
    fclose(file);
    return 2;  // Error writing to the file
  }

  // Close the file
  fclose(file);

  return 0;  // Success
}

// Function to read a string from a file
char *read_from_file(char *filename) {
  // Open the file in read mode
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;  // Error opening the file
  }

  // Get the size of the file
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory for the string
  char *string = malloc(size + 1);
  if (string == NULL) {
    fclose(file);
    return NULL;  // Error allocating memory
  }

  // Read the string from the file
  int bytes_read = fread(string, 1, size, file);
  if (bytes_read != size) {
    free(string);
    fclose(file);
    return NULL;  // Error reading from the file
  }

  // Add a null terminator to the end of the string
  string[size] = '\0';

  // Close the file
  fclose(file);

  return string;  // Success
}

int main() {
  // Write a string to a file
  char *filename = "test.txt";
  char *string = "Hello, world!";
  if (write_to_file(filename, string) != 0) {
    printf("Error writing to file!\n");
    return 1;
  }

  // Read the string from the file
  char *string2 = read_from_file(filename);
  if (string2 == NULL) {
    printf("Error reading from file!\n");
    return 1;
  }

  // Print the string
  printf("%s\n", string2);

  // Free the memory allocated for the string
  free(string2);

  return 0;
}