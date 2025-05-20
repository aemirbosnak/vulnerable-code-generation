//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024
#define REPEAT_THRESH 3

void compress(char *input, int len) {
  int repeat_count = 0;
  char *output = NULL;

  // Step 1: Find repeats
  for (int i = 0; i < len; i++) {
    if (input[i] == input[i + 1]) {
      repeat_count++;
      if (repeat_count >= REPEAT_THRESH) {
        output = &input[i];
        break;
      }
    } else {
      repeat_count = 0;
    }
  }

  // Step 2: Compress repeats
  if (output) {
    for (int i = 0; i < repeat_count; i++) {
      output[i] = input[i];
    }
    output[repeat_count] = '\0';
  }

  // Step 3: Compress remaining characters
  for (int i = repeat_count + 1; i < len; i++) {
    if (input[i] != '\0') {
      output[i - repeat_count] = input[i];
    }
  }

  // Step 4: Output compressed data
  printf("Compressed data: %s\n", output);
}

int main() {
  char input[] = "Hello, world! How are you?";
  int len = strlen(input);

  compress(input, len);

  return 0;
}