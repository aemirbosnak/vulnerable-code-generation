//GEMINI-pro DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define BUF_SIZE 4096

void async_file_write(char *filename, char *data, size_t size) {
  int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd == -1) {
    perror("open");
    return;
  }

  // Set the file descriptor to non-blocking mode.
  if (fcntl(fd, F_SETFL, O_NONBLOCK) == -1) {
    perror("fcntl");
    close(fd);
    return;
  }

  // Write the data to the file.
  ssize_t bytes_written = write(fd, data, size);
  if (bytes_written == -1) {
    if (errno == EAGAIN || errno == EWOULDBLOCK) {
      // The file is full. Wait for the kernel to flush the buffers.
      sleep(1);

      // Try writing again.
      bytes_written = write(fd, data, size);
      if (bytes_written == -1) {
        perror("write");
        close(fd);
        return;
      }
    } else {
      perror("write");
      close(fd);
      return;
    }
  }

  // Close the file.
  close(fd);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s filename data\n", argv[0]);
    return 1;
  }

  async_file_write(argv[1], argv[2], strlen(argv[2]));

  return 0;
}