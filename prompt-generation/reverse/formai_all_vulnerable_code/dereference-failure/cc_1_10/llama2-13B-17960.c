//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: excited
// 🔥 Compression Algorithms Extravaganza! 🔥

// Define the compression functions
void run_deflate(int *array, int size) {
  // Deflate the array using the LZ77 algorithm
  int i, j, k;
  int prev = -1;
  int curr = -1;
  int next = -1;
  int window = 4; // sliding window size
  int dictionary = 0; // dictionary size
  int compression = 0; // compression ratio

  for (i = 0; i < size; i++) {
    // Check for repeated characters
    if (array[i] == array[prev]) {
      // If repeated, form a match
      if (prev != -1) {
        // Add the match to the dictionary
        dictionary += 1;
        // Update the compression ratio
        compression += (array[i] == array[prev]) ? 1 : 0;
      }
      // Update the previous character
      prev = array[i];
    } else {
      // If not repeated, form a non-match
      prev = -1;
    }
    // Update the current character
    curr = array[i];
    // Update the next character
    next = -1;
  }
  // Add the final match to the dictionary
  dictionary += (prev != -1) ? 1 : 0;
  // Update the compression ratio
  compression += (prev != -1) ? 1 : 0;

  // Calculate the compressed size
  int compressed_size = (compression * 100) / (size * 8);

  // Print the results
  printf("Decompressed size: %d\n", size * 8);
  printf("Compressed size: %d\n", compressed_size);
  printf("Compression ratio: %f%%\n", (float)compression / (float)size * 100);
}

void run_gzip(int *array, int size) {
  // Gzip the array using the DEFLATE algorithm
  int i, j, k;
  int prev = -1;
  int curr = -1;
  int next = -1;
  int window = 4; // sliding window size
  int dictionary = 0; // dictionary size
  int compression = 0; // compression ratio

  for (i = 0; i < size; i++) {
    // Check for repeated characters
    if (array[i] == array[prev]) {
      // If repeated, form a match
      if (prev != -1) {
        // Add the match to the dictionary
        dictionary += 1;
        // Update the compression ratio
        compression += (array[i] == array[prev]) ? 1 : 0;
      }
      // Update the previous character
      prev = array[i];
    } else {
      // If not repeated, form a non-match
      prev = -1;
    }
    // Update the current character
    curr = array[i];
    // Update the next character
    next = -1;
  }
  // Add the final match to the dictionary
  dictionary += (prev != -1) ? 1 : 0;
  // Update the compression ratio
  compression += (prev != -1) ? 1 : 0;

  // Calculate the compressed size
  int compressed_size = (compression * 100) / (size * 8);

  // Print the results
  printf("Decompressed size: %d\n", size * 8);
  printf("Compressed size: %d\n", compressed_size);
  printf("Compression ratio: %f%%\n", (float)compression / (float)size * 100);
}

int main() {
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(array) / sizeof(array[0]);

  // Run the compression algorithms
  run_deflate(array, size);
  run_gzip(array, size);

  return 0;
}