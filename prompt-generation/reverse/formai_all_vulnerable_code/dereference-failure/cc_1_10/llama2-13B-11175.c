//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10)
#define MAX_BUFFER_SIZE (1024 * 1024 * 5)

int main() {
  // Create a random file name
  char file_name[50];
  srand(time(NULL));
  for (int i = 0; i < 50; i++) {
    file_name[i] = 'a' + (rand() % 26);
  }

  // Create a random file size
  long file_size = (long)((rand() % 1000) * 1024 * 1024);

  // Open the file in random access mode
  int fd = open(file_name, O_RDWR | O_CREAT, 0644);
  if (fd == -1) {
    perror("Error opening file");
    return 1;
  }

  // Set the file size to a random value
  if (ftruncate(fd, file_size) == -1) {
    perror("Error setting file size");
    close(fd);
    return 1;
  }

  // Map the file into memory
  void* map = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
  if (map == MAP_FAILED) {
    perror("Error mapping file");
    close(fd);
    return 1;
  }

  // Write some random data to the file
  for (int i = 0; i < 1000; i++) {
    int random = rand() % 256;
    (*(char*)((map + i) + (rand() % 10))) = random;
  }

  // Unmap the file from memory
  munmap(map, file_size);

  // Close the file
  close(fd);

  return 0;
}