//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define PAGE_SIZE 4096

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  struct stat st;
  if (fstat(fd, &st) == -1) {
    perror("fstat");
    return EXIT_FAILURE;
  }

  void *addr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (addr == MAP_FAILED) {
    perror("mmap");
    return EXIT_FAILURE;
  }

  close(fd);

  char *buf = (char *)addr;
  size_t len = st.st_size;

  while (len > 0) {
    size_t n = fread(buf, 1, PAGE_SIZE, stdin);
    if (n == 0) {
      break;
    }

    buf += n;
    len -= n;
  }

  munmap(addr, st.st_size);

  return EXIT_SUCCESS;
}