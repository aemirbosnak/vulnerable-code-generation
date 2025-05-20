//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <source file> <destination file> <block size>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const char *source_file = argv[1];
  const char *destination_file = argv[2];
  int block_size = atoi(argv[3]);

  int source_fd = open(source_file, O_RDONLY);
  if (source_fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  int destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (destination_fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  char *buffer = malloc(block_size);
  if (buffer == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  while (1) {
    ssize_t bytes_read = read(source_fd, buffer, block_size);
    if (bytes_read == -1) {
      perror("read");
      return EXIT_FAILURE;
    }

    if (bytes_read == 0) {
      break;
    }

    ssize_t bytes_written = write(destination_fd, buffer, bytes_read);
    if (bytes_written == -1) {
      perror("write");
      return EXIT_FAILURE;
    }
  }

  free(buffer);
  close(source_fd);
  close(destination_fd);

  return EXIT_SUCCESS;
}