//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define REPEAT_THRESHOLD 4

// Compression function
void compress(char *input, char *output) {
  int i, j, k, repeat;
  char c, prev_c;

  // Initialize repeat count
  repeat = 0;

  // Loop through input string
  for (i = 0; i < strlen(input); i++) {
    c = input[i];

    // Check for repeated characters
    if (c == prev_c) {
      // Increment repeat count
      repeat++;

      // If repeat count exceeds threshold, compress
      if (repeat > REPEAT_THRESHOLD) {
        // Compress repeated character
        output[j] = '!';
        j++;
        repeat = 0;
      }
    } else {
      // Reset repeat count
      repeat = 0;
    }

    // Store current character
    output[j] = c;
    j++;

    // Store previous character
    prev_c = c;
  }

  // Store final character
  output[j] = '\0';
}

int main() {
  char input[] = "The quick brown fox jumps over the lazy dog";
  char output[strlen(input)];

  // Compress input string
  compress(input, output);

  // Print compressed string
  printf("%s\n", output);

  return 0;
}