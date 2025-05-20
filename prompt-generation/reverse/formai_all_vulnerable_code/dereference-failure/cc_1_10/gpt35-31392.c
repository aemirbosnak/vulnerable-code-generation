//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "MYVIRUS"

int scan_file(char *filename);

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("No file provided for scanning.\n");
    return 1;
  }

  int result = scan_file(argv[1]);

  if (result == 0) {
    printf("File is clean!\n");
  } else {
    printf("Threat detected!\n");
  }

  return 0;
}

int scan_file(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("Error opening file %s.\n", filename);
    return -1;
  }

  // Determine the size of the file
  fseek(file, 0, SEEK_END);
  int file_size = ftell(file);
  rewind(file);

  // Allocate memory for the file content buffer
  char *buffer = (char *)malloc(file_size + 1);
  buffer[file_size] = '\0';

  // Read the file into the buffer
  fread(buffer, file_size, 1, file);

  // Close the file
  fclose(file);

  // Scan the file for virus signature
  if (strstr(buffer, VIRUS_SIGNATURE) != NULL) {
    printf("Virus signature detected in file %s.\n", filename);
    return 1;
  }

  // Free the memory allocated for the buffer
  free(buffer);

  return 0;
}