//FormAI DATASET v1.0 Category: Data recovery tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BLOCK_SIZE 512

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <device>\n", argv[0]);
    return 1;
  }

  const char *device_path = argv[1];

  FILE *device = fopen(device_path, "rb");
  if (device == NULL) {
    perror("Error opening device");
    return 1;
  }

  size_t device_size = 0;
  fseek(device, 0L, SEEK_END);
  device_size = ftell(device);
  fseek(device, 0L, SEEK_SET);

  const size_t num_blocks = device_size / BLOCK_SIZE;

  char *recovered_data = (char *) malloc(device_size);
  if (recovered_data == NULL) {
    perror("Error allocating memory");
    return 1;
  }

  size_t block_index = 0;
  size_t byte_index = 0;
  char block_buf[BLOCK_SIZE];

  for (block_index = 0; block_index < num_blocks; block_index++) {
    if (fread(block_buf, BLOCK_SIZE, 1, device) != 1) break;

    for (byte_index = 0; byte_index < BLOCK_SIZE; byte_index++) {
      const size_t recovered_index = block_index * BLOCK_SIZE + byte_index;
      if (recovered_index >= device_size) break;
      recovered_data[recovered_index] = block_buf[byte_index];
    }
  }

  if (fclose(device) != 0) {
    perror("Error closing device");
    return 1;
  }

  printf("Successfully recovered %lu bytes of data from %s\n", device_size, device_path);

  // Do something with recovered_data...

  free(recovered_data);

  return 0;
}