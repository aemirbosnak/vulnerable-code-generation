//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recover data from a file
char *recover_data(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Get the file size
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  rewind(fp);

  // Allocate memory for the data
  char *data = malloc(size);
  if (data == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return NULL;
  }

  // Read the data from the file
  fread(data, 1, size, fp);
  fclose(fp);

  // Return the data
  return data;
}

// Function to write data to a file
int write_data(char *filename, char *data, long size) {
  // Open the file
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror("Error opening file");
    return -1;
  }

  // Write the data to the file
  fwrite(data, 1, size, fp);
  fclose(fp);

  // Return 0 on success
  return 0;
}

// Main function
int main() {
  // Recover data from the file
  char *data = recover_data("data.txt");
  if (data == NULL) {
    return -1;
  }

  // Write the data to a new file
  int status = write_data("recovered_data.txt", data, strlen(data));
  if (status != 0) {
    perror("Error writing data to file");
    free(data);
    return -1;
  }

  // Free the memory
  free(data);

  // Return 0 on success
  return 0;
}