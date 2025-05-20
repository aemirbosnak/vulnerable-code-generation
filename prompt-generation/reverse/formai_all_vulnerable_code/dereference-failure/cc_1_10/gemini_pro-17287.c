//GEMINI-pro DATASET v1.0 Category: System administration ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  // Check if the user has provided a file name.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Open the file for reading.
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  // Get the file size.
  struct stat buf;
  if (fstat(fd, &buf) == -1) {
    perror("fstat");
    exit(EXIT_FAILURE);
  }

  // Allocate a buffer to store the file contents.
  char *buffer = malloc(buf.st_size);
  if (buffer == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  // Read the file contents into the buffer.
  ssize_t bytes_read = read(fd, buffer, buf.st_size);
  if (bytes_read == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  // Close the file.
  if (close(fd) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }

  // Print the file contents to the standard output.
  printf("%s", buffer);

  // Free the buffer.
  free(buffer);

  return EXIT_SUCCESS;
}