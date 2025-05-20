//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char *argv[]) {
  if (argc!= 3) {
    fprintf(stderr, "Usage: %s <file> <offset>\n", argv[0]);
    exit(1);
  }

  char *filename = argv[1];
  long offset = strtol(argv[2], NULL, 10);
  if (offset < 0 || offset > LONG_MAX) {
    fprintf(stderr, "Invalid offset: %ld\n", offset);
    exit(1);
  }

  int fd = open(filename, O_RDONLY);
  if (fd == -1) {
    fprintf(stderr, "Error opening %s: %s\n", filename, strerror(errno));
    exit(1);
  }

  struct stat st;
  if (fstat(fd, &st) == -1) {
    fprintf(stderr, "Error statting %s: %s\n", filename, strerror(errno));
    exit(1);
  }

  long filesize = st.st_size;
  if (offset > filesize) {
    fprintf(stderr, "Offset out of range: %ld > %ld\n", offset, filesize);
    exit(1);
  }

  char buffer[1024];
  long bytes_read = 0;
  long bytes_written = 0;
  while (bytes_read < offset) {
    bytes_read += read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
      fprintf(stderr, "Error reading from %s: %s\n", filename, strerror(errno));
      exit(1);
    }
  }

  if (offset + sizeof(buffer) > filesize) {
    fprintf(stderr, "Offset out of range: %ld > %ld\n", offset + sizeof(buffer), filesize);
    exit(1);
  }

  write(STDOUT_FILENO, buffer, sizeof(buffer));

  close(fd);
  exit(0);
}