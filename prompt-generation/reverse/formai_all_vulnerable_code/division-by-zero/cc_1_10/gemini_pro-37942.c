//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <image file> <watermark>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "rb");
  if (!fp) {
    perror("fopen");
    return 1;
  }

  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  rewind(fp);

  unsigned char *image = malloc(file_size);
  if (!image) {
    perror("malloc");
    return 1;
  }

  fread(image, 1, file_size, fp);
  fclose(fp);

  long watermark_len = strlen(argv[2]);
  if (watermark_len > MAX_LEN) {
    fprintf(stderr, "Watermark too long (max %d chars)\n", MAX_LEN);
    return 1;
  }

  for (long i = 0; i < file_size; i++) {
    if (i % watermark_len == 0) {
      image[i] = argv[2][i % watermark_len];
    }
  }

  fp = fopen(argv[1], "wb");
  if (!fp) {
    perror("fopen");
    return 1;
  }

  fwrite(image, 1, file_size, fp);
  fclose(fp);

  free(image);

  return 0;
}