//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Mystic Mimic's heart: counting repeated sequences
int mimic_count_repetition(const unsigned char *data, int len) {
  int count = 0;
  int i, j;
  for (i = 0; i < len; i++) {
    for (j = i + 1; j < len; j++) {
      if (data[i] != data[j]) break;
    }
    count += j - i;
  }
  return count;
}

// The camouflage process: compressing data
unsigned char *mimic_compress(const unsigned char *data, int len, int *out_len) {
  *out_len = len + mimic_count_repetition(data, len);
  unsigned char *compressed = malloc(*out_len);
  int i, j, k;

  for (i = 0, k = 0; i < len; i++) {
    compressed[k++] = data[i];
    for (j = i + 1; j < len; j++) {
      if (data[i] != data[j]) break;
    }
    if (j - i > 1) {
      compressed[k++] = (j - i) - 1;
    }
    i = j - 1;
  }

  return compressed;
}

// Unveiling the secret: decompressing data
unsigned char *mimic_decompress(const unsigned char *data, int len) {
  unsigned char *decompressed = malloc(len);
  int i, j, k;

  for (i = 0, k = 0; i < len; i++) {
    if (i + 1 < len && data[i + 1] > 0) {
      for (j = 0; j < data[i + 1] + 1; j++) {
        decompressed[k++] = data[i];
      }
      i++;
    } else {
      decompressed[k++] = data[i];
    }
  }

  return decompressed;
}

int main() {
  const char *text = "abracadabra";
  int len = strlen(text);

  // Compress the text
  int compressed_len;
  unsigned char *compressed = mimic_compress((unsigned char *)text, len, &compressed_len);

  // Print the compressed text
  printf("Compressed text: ");
  for (int i = 0; i < compressed_len; i++) {
    printf("%c", compressed[i]);
  }
  printf("\n");

  // Decompress the text
  unsigned char *decompressed = mimic_decompress(compressed, compressed_len);

  // Print the decompressed text
  printf("Decompressed text: %s\n", decompressed);

  // Free up allocated memory
  free(compressed);
  free(decompressed);

  return 0;
}