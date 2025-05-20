//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    return 1;
  }

  struct stat file_info;
  if (stat(argv[1], &file_info) == -1) {
    perror("stat");
    return 1;
  }

  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  char *buffer = malloc(file_info.st_size);
  if (buffer == NULL) {
    perror("malloc");
    return 1;
  }

  ssize_t num_bytes = read(fd, buffer, file_info.st_size);
  if (num_bytes == -1) {
    perror("read");
    return 1;
  }

  close(fd);

  printf("File %s has %ld bytes:\n", argv[1], file_info.st_size);

  char *metadata = buffer;
  while (metadata < buffer + num_bytes) {
    if (*metadata == '\0') {
      metadata++;
      continue;
    }

    char *key = metadata;
    while (*metadata != ':') {
      metadata++;
    }

    *metadata = '\0';
    metadata++;

    char *value = metadata;
    while (*metadata != '\n') {
      metadata++;
    }

    *metadata = '\0';
    metadata++;

    printf("  %s: %s\n", key, value);
  }

  free(buffer);
  return 0;
}