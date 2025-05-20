//Gemma-7B DATASET v1.0 Category: File handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

int main() {
  // Define file name
  char filename[256] = "my_file.txt";

  // Open file in read-write mode
  FILE *fp = fopen(filename, "r+w");

  // Check if file is open
  if (fp == NULL) {
    printf("Error opening file: %s", filename);
    exit(1);
  }

  // Allocate memory for file data
  char *file_data = malloc(MAX_FILE_SIZE);

  // Read file data
  int file_size = fread(file_data, 1, MAX_FILE_SIZE, fp);

  // Check if file data was read
  if (file_size == 0) {
    printf("Error reading file: %s", filename);
    exit(1);
  }

  // Modify file data
  file_data[0] = 'H';

  // Write file data back to file
  int write_size = fwrite(file_data, 1, file_size, fp);

  // Check if file data was written
  if (write_size != file_size) {
    printf("Error writing file: %s", filename);
    exit(1);
  }

  // Close file
  fclose(fp);

  // Free memory
  free(file_data);

  // Print file data
  FILE *fp2 = fopen(filename, "r");
  char buffer[MAX_FILE_SIZE];
  int read_size = fread(buffer, 1, MAX_FILE_SIZE, fp2);
  printf("File data: %s", buffer);
  fclose(fp2);

  return 0;
}