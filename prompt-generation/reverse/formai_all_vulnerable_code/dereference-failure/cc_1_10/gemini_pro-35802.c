//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>

// Define the metadata structure
typedef struct metadata_t {
  uint32_t magic;
  uint32_t version;
  uint64_t size;
} metadata_t;

// Define the magic number
#define METADATA_MAGIC 0xDEADBEEF

// Print the metadata
void print_metadata(metadata_t *metadata) {
  printf("Magic: 0x%08x\n", metadata->magic);
  printf("Version: %u\n", metadata->version);
  printf("Size: %lu\n", metadata->size);
}

int main(int argc, char **argv) {
  // Check if the user specified a file
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the file
  int fd = open(argv[1], O_RDONLY);
  if (fd < 0) {
    perror("open");
    return EXIT_FAILURE;
  }

  // Get the file size
  struct stat st;
  if (fstat(fd, &st) < 0) {
    perror("fstat");
    return EXIT_FAILURE;
  }

  // Memory map the file
  void *data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (data == MAP_FAILED) {
    perror("mmap");
    return EXIT_FAILURE;
  }

  // Get the metadata
  metadata_t *metadata = (metadata_t *)data;
  if (metadata->magic != METADATA_MAGIC) {
    fprintf(stderr, "Invalid metadata magic number\n");
    return EXIT_FAILURE;
  }

  // Print the metadata
  print_metadata(metadata);

  // Unmap the file
  if (munmap(data, st.st_size) < 0) {
    perror("munmap");
    return EXIT_FAILURE;
  }

  // Close the file
  if (close(fd) < 0) {
    perror("close");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}