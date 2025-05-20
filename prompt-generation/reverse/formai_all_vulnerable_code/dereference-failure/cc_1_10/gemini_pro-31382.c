//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handle_error(int errnum) {
  switch (errnum) {
  case ENOENT:
    printf("File not found.\n");
    break;
  case EACCES:
    printf("Permission denied.\n");
    break;
  case EINTR:
    printf("Operation interrupted.\n");
    break;
  case EINVAL:
    printf("Invalid argument.\n");
    break;
  default:
    printf("Unknown error.\n");
  }
}

int main() {
  int errnum;
  FILE *file;

  // Try to open a file that doesn't exist
  file = fopen("nonexistentfile.txt", "r");
  if (file == NULL) {
    errnum = errno;
    handle_error(errnum);
    return 1;
  }

  // Try to read from the file
  char buffer[1024];
  int bytes_read;
  bytes_read = fread(buffer, 1, 1024, file);
  if (bytes_read < 0) {
    errnum = errno;
    handle_error(errnum);
    fclose(file);
    return 1;
  }

  // Close the file
  if (fclose(file) != 0) {
    errnum = errno;
    handle_error(errnum);
    return 1;
  }

  return 0;
}