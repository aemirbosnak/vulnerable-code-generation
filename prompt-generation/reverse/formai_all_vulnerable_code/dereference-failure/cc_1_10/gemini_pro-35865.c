//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file and store its contents in a buffer
char *read_file(char *filename) {
  // Open the file in read-only mode
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate a buffer to store the file contents
  char *buffer = malloc(file_size + 1);
  if (buffer == NULL) {
    printf("Error allocating memory for buffer\n");
    fclose(file);
    return NULL;
  }

  // Read the file contents into the buffer
  fread(buffer, file_size, 1, file);
  fclose(file);

  // Null-terminate the buffer
  buffer[file_size] = '\0';

  // Return the buffer
  return buffer;
}

// Function to write a buffer to a file
void write_file(char *filename, char *buffer) {
  // Open the file in write-only mode
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return;
  }

  // Write the buffer to the file
  fwrite(buffer, strlen(buffer), 1, file);
  fclose(file);
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided a filename
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Read the file contents into a buffer
  char *buffer = read_file(argv[1]);
  if (buffer == NULL) {
    return 1;
  }

  // Search for the signature of a deleted file (OxE5)
  char *signature = strstr(buffer, "\xE5");
  if (signature == NULL) {
    printf("No deleted files found in %s\n", argv[1]);
    free(buffer);
    return 1;
  }

  // Calculate the length of the deleted file
  int length = 0;
  while (signature[length] != '\x00') {
    length++;
  }

  // Create a new buffer to store the deleted file
  char *deleted_file = malloc(length);
  if (deleted_file == NULL) {
    printf("Error allocating memory for deleted file\n");
    free(buffer);
    return 1;
  }

  // Copy the deleted file into the new buffer
  memcpy(deleted_file, signature, length);

  // Write the deleted file to a new file
  char *new_filename = malloc(strlen(argv[1]) + 5);
  strcpy(new_filename, argv[1]);
  strcat(new_filename, "_recovered");
  write_file(new_filename, deleted_file);

  // Free the buffers
  free(buffer);
  free(deleted_file);
  free(new_filename);

  // Print a success message
  printf("Deleted file recovered to %s\n", new_filename);

  return 0;
}