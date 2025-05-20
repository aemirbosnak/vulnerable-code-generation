//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdint.h>

#define PAGE_SIZE 4096

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  struct stat st;
  if (fstat(fd, &st) == -1) {
    perror("fstat");
    return 1;
  }

  if (st.st_size % PAGE_SIZE != 0) {
    fprintf(stderr, "File size must be a multiple of the page size\n");
    return 1;
  }

  void *addr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (addr == MAP_FAILED) {
    perror("mmap");
    return 1;
  }

  uint64_t sum = 0;
  for (size_t i = 0; i < st.st_size; i++) {
    sum += ((uint8_t *)addr)[i];
  }

  printf("Sum: %lu\n", sum);

  if (munmap(addr, st.st_size) == -1) {
    perror("munmap");
    return 1;
  }

  if (close(fd) == -1) {
    perror("close");
    return 1;
  }

  return 0;
}