//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define BUFFSIZE 4096

typedef struct {
  char *name;
  time_t mtime;
  size_t size;
} FileInfo;

int compare_files(FileInfo *f1, FileInfo *f2) {
  if (f1->mtime != f2->mtime) {
    return f1->mtime < f2->mtime ? -1 : 1;
  } else if (f1->size != f2->size) {
    return f1->size < f2->size ? -1 : 1;
  } else {
    return 0;
  }
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *source = argv[1];
  char *destination = argv[2];

  struct stat source_stat;
  if (stat(source, &source_stat) == -1) {
    perror("stat");
    return EXIT_FAILURE;
  }

  struct stat destination_stat;
  if (stat(destination, &destination_stat) == -1) {
    if (errno == ENOENT) {
      // Destination does not exist, create it.
      if (mkdir(destination, 0755) == -1) {
        perror("mkdir");
        return EXIT_FAILURE;
      }
    } else {
      perror("stat");
      return EXIT_FAILURE;
    }
  }

  int source_fd = open(source, O_RDONLY);
  if (source_fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  int destination_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (destination_fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  char buffer[BUFFSIZE];
  ssize_t bytes_read;
  while ((bytes_read = read(source_fd, buffer, BUFFSIZE)) > 0) {
    if (write(destination_fd, buffer, bytes_read) == -1) {
      perror("write");
      return EXIT_FAILURE;
    }
  }

  if (bytes_read == -1) {
    perror("read");
    return EXIT_FAILURE;
  }

  if (close(source_fd) == -1) {
    perror("close");
    return EXIT_FAILURE;
  }

  if (close(destination_fd) == -1) {
    perror("close");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}