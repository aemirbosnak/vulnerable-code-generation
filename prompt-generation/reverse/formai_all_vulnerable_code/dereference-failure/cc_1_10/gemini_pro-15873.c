//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Hidden message
const char *msg = "Remember the old world?";

// Convert an integer to a binary string.
char *int2bin(uint32_t n) {
  char *s = malloc(33);
  int i;
  s[32] = '\0';
  for (i = 31; i >= 0; i--) {
    s[i] = (n & 1) ? '1' : '0';
    n >>= 1;
  }
  return s;
}

// Embed the hidden message into the image.
void embed(const char *image, const char *msg) {
  FILE *f = fopen(image, "rb+");
  if (!f) {
    perror("fopen");
    return;
  }

  // Read the image into a buffer.
  fseek(f, 0, SEEK_END);
  size_t size = ftell(f);
  rewind(f);
  uint8_t *buf = malloc(size);
  fread(buf, 1, size, f);

  // Embed the message in the least significant bits of the image.
  int i, j, k;
  for (i = 0, j = 0; i < strlen(msg); i++, j += 8) {
    char *bin = int2bin(msg[i]);
    for (k = 0; k < 8; k++) {
      buf[j + k] = (buf[j + k] & 0xfe) | (bin[k] - '0');
    }
    free(bin);
  }

  // Write the modified image back to the file.
  fseek(f, 0, SEEK_SET);
  fwrite(buf, 1, size, f);
  fclose(f);
}

// Extract the hidden message from the image.
void extract(const char *image) {
  FILE *f = fopen(image, "rb");
  if (!f) {
    perror("fopen");
    return;
  }

  // Read the image into a buffer.
  fseek(f, 0, SEEK_END);
  size_t size = ftell(f);
  rewind(f);
  uint8_t *buf = malloc(size);
  fread(buf, 1, size, f);
  fclose(f);

  // Extract the message from the least significant bits of the image.
  char *msg = malloc(size / 8 + 1);
  int i, j, k;
  for (i = 0, j = 0; i < size / 8; i++, j += 8) {
    char bin[9];
    for (k = 0; k < 8; k++) {
      bin[k] = (buf[j + k] & 1) + '0';
    }
    bin[8] = '\0';
    msg[i] = strtol(bin, NULL, 2);
  }
  msg[i] = '\0';

  // Print the message.
  printf("The hidden message is: %s\n", msg);
  free(msg);
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <image> <embed/extract>\n", argv[0]);
    return 1;
  }

  if (!strcmp(argv[2], "embed")) {
    embed(argv[1], msg);
  } else if (!strcmp(argv[2], "extract")) {
    extract(argv[1]);
  } else {
    fprintf(stderr, "Unknown operation: %s\n", argv[2]);
    return 1;
  }

  return 0;
}