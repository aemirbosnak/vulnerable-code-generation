//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the file
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  // Get the file size
  struct stat st;
  if (fstat(fd, &st) == -1) {
    perror("fstat");
    return EXIT_FAILURE;
  }

  // Allocate a buffer to read the file into
  char *buffer = malloc(st.st_size);
  if (buffer == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  // Read the file into the buffer
  if (read(fd, buffer, st.st_size) != st.st_size) {
    perror("read");
    return EXIT_FAILURE;
  }

  // Close the file
  if (close(fd) == -1) {
    perror("close");
    return EXIT_FAILURE;
  }

  // Calculate the RAM usage
  size_t ram_usage = 0;
  for (size_t i = 0; i < st.st_size; i++) {
    ram_usage += buffer[i];
  }

  // Print the RAM usage
  printf("RAM usage: %lu bytes\n", ram_usage);

  // Free the buffer
  free(buffer);

  return EXIT_SUCCESS;
}