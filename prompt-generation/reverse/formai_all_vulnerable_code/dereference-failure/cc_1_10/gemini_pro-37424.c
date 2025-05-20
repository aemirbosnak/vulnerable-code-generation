//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: decentralized
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define PAGE_SIZE 4096

int main(int argc, char **argv) {
  int fd;
  char *buf;
  struct stat st;
  int i;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    exit(1);
  }

  if ((fd = open(argv[1], O_RDWR)) == -1) {
    perror("open");
    exit(1);
  }

  if (fstat(fd, &st) == -1) {
    perror("fstat");
    exit(1);
  }

  if ((buf = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }

  for (i = 0; i < st.st_size; i += PAGE_SIZE) {
    int j;

    for (j = 0; j < PAGE_SIZE; j += 4) {
      int a = buf[i + j];
      int b = buf[i + j + 1];
      int c = buf[i + j + 2];
      int d = buf[i + j + 3];

      buf[i + j] = d;
      buf[i + j + 1] = c;
      buf[i + j + 2] = b;
      buf[i + j + 3] = a;
    }
  }

  msync(buf, st.st_size, MS_SYNC);
  munmap(buf, st.st_size);
  close(fd);

  return 0;
}