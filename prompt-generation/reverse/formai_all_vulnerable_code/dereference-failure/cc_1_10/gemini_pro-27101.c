//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define FILE_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <source file> <destination file> <sync interval (ms)>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int source_fd = open(argv[1], O_RDONLY);
  if (source_fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  int destination_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  if (destination_fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  int sync_interval = atoi(argv[3]);

  char buffer[FILE_SIZE];
  int bytes_read;
  int bytes_written;

  while ((bytes_read = read(source_fd, buffer, FILE_SIZE)) > 0) {
    bytes_written = write(destination_fd, buffer, bytes_read);
    if (bytes_written != bytes_read) {
      perror("write");
      return EXIT_FAILURE;
    }
    fsync(destination_fd);
    usleep(sync_interval * 1000);
  }

  if (bytes_read == -1) {
    perror("read");
    return EXIT_FAILURE;
  }

  close(source_fd);
  close(destination_fd);

  return EXIT_SUCCESS;
}