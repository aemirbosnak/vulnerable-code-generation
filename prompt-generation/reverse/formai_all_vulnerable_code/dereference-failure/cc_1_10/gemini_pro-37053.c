//GEMINI-pro DATASET v1.0 Category: System administration ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Open the source file
  int fd_src = open(argv[1], O_RDONLY);
  if (fd_src == -1) {
    fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Get the size of the source file
  struct stat stat_src;
  if (fstat(fd_src, &stat_src) == -1) {
    fprintf(stderr, "Error getting size of source file: %s\n", strerror(errno));
    close(fd_src);
    exit(EXIT_FAILURE);
  }

  // Allocate a buffer to hold the data from the source file
  char *buf = malloc(stat_src.st_size);
  if (buf == NULL) {
    fprintf(stderr, "Error allocating buffer: %s\n", strerror(errno));
    close(fd_src);
    exit(EXIT_FAILURE);
  }

  // Read the data from the source file into the buffer
  ssize_t bytes_read = read(fd_src, buf, stat_src.st_size);
  if (bytes_read == -1) {
    fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
    free(buf);
    close(fd_src);
    exit(EXIT_FAILURE);
  }

  // Close the source file
  close(fd_src);

  // Open the destination file
  int fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd_dst == -1) {
    fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
    free(buf);
    exit(EXIT_FAILURE);
  }

  // Write the data from the buffer to the destination file
  ssize_t bytes_written = write(fd_dst, buf, bytes_read);
  if (bytes_written == -1) {
    fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
    free(buf);
    close(fd_dst);
    exit(EXIT_FAILURE);
  }

  // Close the destination file
  close(fd_dst);

  // Free the buffer
  free(buf);

  return EXIT_SUCCESS;
}