//GEMINI-pro DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Open the file for reading.
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  // Get the file size.
  struct stat statbuf;
  if (fstat(fd, &statbuf) == -1) {
    perror("fstat");
    exit(EXIT_FAILURE);
  }

  // Allocate a buffer to hold the file contents.
  char *buf = malloc(statbuf.st_size);
  if (buf == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  // Read the file contents into the buffer.
  ssize_t bytes_read = read(fd, buf, statbuf.st_size);
  if (bytes_read == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  // Close the file.
  if (close(fd) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }

  // Parse the file contents for lines that start with "Error".
  char *line_start = buf;
  while (line_start != NULL) {
    char *line_end = strchr(line_start, '\n');
    if (line_end == NULL) {
      line_end = buf + statbuf.st_size;
    }

    // If the line starts with "Error", print it to the standard output.
    if (strncmp(line_start, "Error", 5) == 0) {
      fwrite(line_start, line_end - line_start, 1, stdout);
    }

    // Move to the next line.
    line_start = line_end + 1;
  }

  // Free the buffer.
  free(buf);

  return EXIT_SUCCESS;
}