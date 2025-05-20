//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HAPPY_COMPRESSION 10 // compression factor (10 = 10% compression)

// happy compression algorithm
void happyCompress(char *input, char *output) {
  int i, j, k, l;
  char c, d, e, f;
  int happy = 0;

  // step 1: count the number of repeated characters
  for (i = 0; input[i] != '\0'; i++) {
    if (input[i] == ' ') continue; // ignore spaces
    happy += 1;
  }

  // step 2: find the first repeated character
  for (i = 0; input[i] != '\0'; i++) {
    if (input[i] == ' ') continue; // ignore spaces
    for (j = i + 1; input[j] != '\0'; j++) {
      if (input[j] == input[i]) {
        happy += 2; // count double occurrences
        break;
      }
    }
  }

  // step 3: compress the repeated characters
  for (i = 0; input[i] != '\0'; i++) {
    if (input[i] == ' ') continue; // ignore spaces
    c = input[i]; // current character
    d = input[i + 1]; // next character
    e = input[i + 2]; // next next character
    f = input[i + 3]; // next next next character

    // if the current character is repeated, compress it
    if (d == c && e == c && f == c) {
      // compress the repeated character
      output[happy] = c;
      happy++;
      i += 2; // skip over the repeated character
      continue;
    }

    // if the current character is not repeated, move on to the next one
    output[happy] = c;
    happy++;
  }

  // step 4: pad the output with random characters
  for (; happy < HAPPY_COMPRESSION; happy++) {
    output[happy] = 'a' + (rand() % 26); // generate a random character
  }
}

int main() {
  char input[] = "The quick brown fox jumps over the lazy dog";
  char output[HAPPY_COMPRESSION];

  happyCompress(input, output);

  printf("Original: %s\n", input);
  printf("Compressed: %s\n", output);

  return 0;
}