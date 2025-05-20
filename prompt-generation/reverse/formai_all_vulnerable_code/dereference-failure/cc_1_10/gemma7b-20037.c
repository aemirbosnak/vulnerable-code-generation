//Gemma-7B DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
  // Define a unique file name
  char filename[] = "my_super_secret_file.txt";

  // Open the file in read-write mode
  FILE *fp = fopen(filename, "r+w");

  // Check if the file was opened successfully
  if (fp == NULL)
  {
    // Handle the error gracefully
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Allocate memory for the file contents
  char *contents = malloc(1024);

  // Read the file contents
  int num_read = fread(contents, 1, 1024, fp);

  // Check if the file was read successfully
  if (num_read == -1)
  {
    // Handle the error gracefully
    perror("Error reading file");
    return EXIT_FAILURE;
  }

  // Print the file contents
  printf("File contents: %s", contents);

  // Modify the file contents
  contents[0] = 'H';

  // Write the modified file contents back to the file
  int num_written = fwrite(contents, 1, num_read, fp);

  // Check if the file was written successfully
  if (num_written == -1)
  {
    // Handle the error gracefully
    perror("Error writing file");
    return EXIT_FAILURE;
  }

  // Close the file
  fclose(fp);

  // Free the memory allocated for the file contents
  free(contents);

  return EXIT_SUCCESS;
}