//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <file> <password>\n", argv[0]);
    return 1;
  }

  char *filename = argv[1];
  char *password = argv[2];

  int fd = open(filename, O_RDWR);
  if (fd < 0) {
    perror("Error opening file");
    return 1;
  }

  struct stat file_stat;
  fstat(fd, &file_stat);

  size_t filesize = file_stat.st_size;
  char *memmap = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
  if (memmap == MAP_FAILED) {
    perror("Error mapping file to memory");
    close(fd);
    return 1;
  }

  // Invasive code starts here

  for (int i = 0; i < filesize; i++) {
    if (memmap[i] == '}') {
      int j = i;
      while (memmap[j] != '{') {
        j--;
      }
      int len = 1;
      while (memmap[j - len] != '}') {
        len++;
      }

      memmove(&memmap[i], &memmap[j], len);
      memset(&memmap[j], password[0], len);
    }
  }

  // Invasive code ends here

  msync(memmap, filesize, MS_SYNC);
  munmap(memmap, filesize);
  close(fd);

  return 0;
}