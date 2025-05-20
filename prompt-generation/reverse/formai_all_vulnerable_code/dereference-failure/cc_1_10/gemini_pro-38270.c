//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recover data from a file
char* recoverData(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: Unable to open file %s\n", filename);
    return NULL;
  }

  // Read the file contents into a buffer
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  rewind(fp);
  char *buffer = malloc(fsize + 1);
  fread(buffer, fsize, 1, fp);
  fclose(fp);

  // Find the start of the data
  char *start = strstr(buffer, "BEGIN_DATA");
  if (start == NULL) {
    printf("Error: Unable to find start of data in file %s\n", filename);
    free(buffer);
    return NULL;
  }

  // Find the end of the data
  char *end = strstr(start, "END_DATA");
  if (end == NULL) {
    printf("Error: Unable to find end of data in file %s\n", filename);
    free(buffer);
    return NULL;
  }

  // Extract the data
  int data_size = end - start - strlen("BEGIN_DATA");
  char *data = malloc(data_size + 1);
  memcpy(data, start + strlen("BEGIN_DATA"), data_size);
  data[data_size] = '\0';

  // Close the file
  free(buffer);

  // Return the data
  return data;
}

// Main function
int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Recover the data from the file
  char *data = recoverData(argv[1]);
  if (data == NULL) {
    printf("Error: Unable to recover data from file %s\n", argv[1]);
    return 1;
  }

  // Print the data
  printf("Recovered data from file %s:\n%s\n", argv[1], data);

  // Free the data
  free(data);

  return 0;
}