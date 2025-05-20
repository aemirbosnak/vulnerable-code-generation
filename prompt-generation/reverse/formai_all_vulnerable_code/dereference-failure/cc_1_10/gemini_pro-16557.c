//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

// Define the size of the shared memory segment
#define SHM_SIZE 1024

// Define the name of the shared memory segment
#define SHM_NAME "/my_shm"

int main() {
  // Open the shared memory segment
  int shm_fd = shm_open(SHM_NAME, O_RDWR | O_CREAT, 0666);
  if (shm_fd == -1) {
    perror("shm_open");
    exit(EXIT_FAILURE);
  }

  // Resize the shared memory segment
  if (ftruncate(shm_fd, SHM_SIZE) == -1) {
    perror("ftruncate");
    exit(EXIT_FAILURE);
  }

  // Map the shared memory segment to the address space of the process
  void *shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
  if (shm_ptr == MAP_FAILED) {
    perror("mmap");
    exit(EXIT_FAILURE);
  }

  // Write to the shared memory segment
  strcpy(shm_ptr, "Hello, world!");

  // Unmap the shared memory segment from the address space of the process
  if (munmap(shm_ptr, SHM_SIZE) == -1) {
    perror("munmap");
    exit(EXIT_FAILURE);
  }

  // Close the shared memory segment
  if (close(shm_fd) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}