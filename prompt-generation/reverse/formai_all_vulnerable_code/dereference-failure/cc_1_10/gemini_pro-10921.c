//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define META_SIZE 256

void usage() {
  printf("Usage: meta_extractor <filename>\n\n");
  printf("This program will extract metadata from the specified file and print it to the console.\n");
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    usage();
    return 1;
  }

  char *filename = argv[1];
  int fd = open(filename, O_RDONLY);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  struct stat st;
  if (fstat(fd, &st) < 0) {
    perror("fstat");
    return 1;
  }

  char *buf = (char*)malloc(META_SIZE);
  if (!buf) {
    perror("malloc");
    return 1;
  }

  memset(buf, 0, META_SIZE);
  if (lseek(fd, 0, SEEK_END) < 0) {
    perror("lseek");
    return 1;
  }

  int bytes_read = read(fd, buf, META_SIZE);
  if (bytes_read < 0) {
    perror("read");
    return 1;
  }

  close(fd);

  printf("File: %s\n", filename);
  printf("Size: %ld bytes\n", st.st_size);
  printf("Last modified: %s\n", ctime(&st.st_mtime));

  char *ptr = buf;
  while (*ptr) {
    printf("%s\n", ptr);
    ptr += strlen(ptr) + 1;
  }

  free(buf);
  return 0;
}