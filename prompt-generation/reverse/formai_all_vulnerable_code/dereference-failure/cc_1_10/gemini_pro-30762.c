//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

// Define the size of the shared memory segment
#define SIZE 1024

// Define the name of the shared memory segment
#define NAME "my_shared_memory"

int main() {
  // Create a shared memory segment
  int fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);
  if (fd == -1) {
    perror("shm_open");
    exit(1);
  }

  // Resize the shared memory segment to the desired size
  if (ftruncate(fd, SIZE) == -1) {
    perror("ftruncate");
    exit(1);
  }

  // Map the shared memory segment to the address space of the process
  void *ptr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (ptr == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }

  // Write some data to the shared memory segment
  strcpy(ptr, "Hello, world!");

  // Unmap the shared memory segment from the address space of the process
  if (munmap(ptr, SIZE) == -1) {
    perror("munmap");
    exit(1);
  }

  // Close the file descriptor for the shared memory segment
  if (close(fd) == -1) {
    perror("close");
    exit(1);
  }

  return 0;
}