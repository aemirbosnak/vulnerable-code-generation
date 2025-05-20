//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  char buffer[MAX_BUFFER_SIZE];
  char compressed_buffer[MAX_BUFFER_SIZE];
  int buffer_size = 0;
  int compressed_size = 0;

  // Read input data from the user
  printf("Enter text: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Calculate the size of the input data
  buffer_size = strlen(buffer) + 1;

  // Compress the data
  compressed_size = compress(buffer, compressed_buffer, buffer_size);

  // Print the compressed data
  printf("Compressed text: ");
  printf("%s", compressed_buffer);

  // Calculate the compression ratio
  float compression_ratio = (float)buffer_size / (float)compressed_size;

  // Print the compression ratio
  printf("Compression ratio: %.2f", compression_ratio);

  return 0;
}

int compress(char *buffer, char *compressed_buffer, int buffer_size) {
  int i = 0;
  int j = 0;
  int repeat = 1;

  // Iterate over the input data
  for (i = 0; i < buffer_size - 1; i++) {
    // If the current character is the same as the previous character, increment the repeat count
    if (buffer[i] == buffer[i - 1]) {
      repeat++;
    } else {
      // If the repeat count is greater than 1, write the character and the repeat count to the compressed buffer
      if (repeat > 1) {
        compressed_buffer[j++] = buffer[i] - 1;
        compressed_buffer[j++] = repeat - 1;
      } else {
        // Otherwise, write the character to the compressed buffer
        compressed_buffer[j++] = buffer[i];
      }

      // Reset the repeat count to 1
      repeat = 1;
    }
  }

  // Write the remaining character and the repeat count to the compressed buffer
  if (repeat > 1) {
    compressed_buffer[j++] = buffer[buffer_size - 1] - 1;
    compressed_buffer[j++] = repeat - 1;
  } else {
    compressed_buffer[j++] = buffer[buffer_size - 1];
  }

  // Return the size of the compressed data
  return j;
}