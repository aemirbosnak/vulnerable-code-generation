//FormAI DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define BUFFER_SIZE 256

int fd1, fd2;

void signal_handler(int signum) {
  printf("Signal %d received, closing file descriptors...\n", signum);
  close(fd1);
  close(fd2);
  exit(signum);
}

int main() {
  char buffer[BUFFER_SIZE];

  // Create two files to read from and write to
  fd1 = open("input.txt", O_RDONLY | O_CREAT | O_TRUNC);
  if (fd1 < 0) {
    perror("Error creating input.txt");
    exit(errno);
  }
  fd2 = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC);
  if (fd2 < 0) {
    perror("Error creating output.txt");
    exit(errno);
  }

  // Register signal handler
  signal(SIGINT, signal_handler);

  // Read from fd1 asynchronously
  while (1) {
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_read = read(fd1, buffer, BUFFER_SIZE-1);
    if (bytes_read < 0) {
      perror("Error reading from input.txt");
      exit(errno);
    } else if (bytes_read == 0) {
      printf("End of input.txt, closing file descriptors...\n");
      close(fd1);
      close(fd2);
      exit(0);
    }

    // Write to fd2 asynchronously
    buffer[bytes_read] = '\0';
    ssize_t bytes_written = write(fd2, buffer, strlen(buffer));
    if (bytes_written < 0) {
      perror("Error writing to output.txt");
      exit(errno);
    }
  }
}