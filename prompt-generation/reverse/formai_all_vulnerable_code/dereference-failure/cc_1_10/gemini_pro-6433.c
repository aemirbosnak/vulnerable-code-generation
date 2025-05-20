//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
  // Open a file for reading.
  FILE *file = fopen("test.txt", "r");
  if (file == NULL) {
    // Check if the file could not be opened because it does not exist.
    if (errno == ENOENT) {
      printf("File not found.\n");
    } else {
      // Otherwise, print a generic error message.
      perror("fopen");
      exit(EXIT_FAILURE);
    }
  // Close the file.
  } else {
    fclose(file);
  }

  // Allocate memory for a buffer.
  char *buffer = malloc(1024);
  if (buffer == NULL) {
    // Check if memory could not be allocated because the system is out of memory.
    if (errno == ENOMEM) {
      printf("Out of memory.\n");
    } else {
      // Otherwise, print a generic error message.
      perror("malloc");
      exit(EXIT_FAILURE);
    }
  // Free the memory.
  } else {
    free(buffer);
  }

  // Read from the file.
  size_t bytes_read = fread(buffer, 1, 1024, file);
  if (bytes_read == 0) {
    // Check if the end of file was reached.
    if (feof(file)) {
      printf("End of file reached.\n");
    } else {
      // Otherwise, print a generic error message.
      perror("fread");
      exit(EXIT_FAILURE);
    }
  // Close the file.
  } else {
    fclose(file);
  }

  // Write to the file.
  size_t bytes_written = fwrite(buffer, 1, bytes_read, file);
  if (bytes_written != bytes_read) {
    // Check if the write operation failed because the disk is full.
    if (errno == ENOSPC) {
      printf("Disk full.\n");
    } else {
      // Otherwise, print a generic error message.
      perror("fwrite");
      exit(EXIT_FAILURE);
    }
  // Close the file.
  } else {
    fclose(file);
  }

  return EXIT_SUCCESS;
}