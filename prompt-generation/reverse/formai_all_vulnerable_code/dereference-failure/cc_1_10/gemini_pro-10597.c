//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: puzzling
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

// Definitions
#define MAX_FILE_SIZE 1024 * 1024 // 1MB
#define VIRUS_SIGNATURE "EVIL"    // The evil virus signature

// Function prototypes
int scan_file(const char *filename);
int check_virus(const char *data, size_t size);

// Main entry point
int main(int argc, char **argv) {
  // Check if we have a filename
  if (argc < 2) {
    printf("Usage: ./antivirus <filename>\n");
    return 1;
  }

  // Scan the file
  int result = scan_file(argv[1]);

  // Print the result
  if (result == 0) {
    printf("File is clean.\n");
  } else {
    printf("File is infected! (%d bytes of evil)\n", result);
  }

  return 0;
}

// Scans a file for the virus signature
int scan_file(const char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return -1;
  }

  // Get the file size
  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  // Read the file into a buffer
  char *data = malloc(size);
  if (data == NULL) {
    fclose(fp);
    printf("Error allocating memory.\n");
    return -1;
  }
  fread(data, 1, size, fp);

  // Close the file
  fclose(fp);

  // Check for the virus signature
  int result = check_virus(data, size);

  // Free the buffer
  free(data);

  return result;
}

// Checks for the virus signature in a buffer
int check_virus(const char *data, size_t size) {
  // Iterate through the buffer
  int offset = 0;
  while (offset < size) {
    // Check if the signature is present
    if (memcmp(data + offset, VIRUS_SIGNATURE, strlen(VIRUS_SIGNATURE)) == 0) {
      // Found the signature!
      return offset;
    }

    // Move to the next byte
    offset++;
  }

  // Signature not found
  return 0;
}