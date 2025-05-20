//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_SIZE 1024

typedef struct watermark_t {
  char *data;
  int size;
} watermark_t;

 watermark_t *create_watermark(int size) {
  watermark_t *wm = malloc(sizeof(watermark_t));
  wm->data = malloc(size);
  wm->size = size;
  return wm;
}

void embed_watermark(watermark_t *wm, unsigned char *image, int image_size) {
  int i, j, k;
  for (i = 0; i < wm->size; i++) {
    for (j = 0; j < image_size; j++) {
      k = rand() % MAX_WATERMARK_SIZE;
      image[j] ^= wm->data[k];
    }
  }
}

void extract_watermark(watermark_t *wm, unsigned char *image, int image_size) {
  int i, j, k;
  for (i = 0; i < wm->size; i++) {
    for (j = 0; j < image_size; j++) {
      k = rand() % MAX_WATERMARK_SIZE;
      image[j] ^= wm->data[k];
    }
  }
}

int main() {
  unsigned char *image = malloc(1024);
  memset(image, 0, 1024);

   watermark_t *wm = create_watermark(512);
  wm->data = "Secret message";

  embed_watermark(wm, image, 1024);

  extract_watermark(wm, image, 1024);

  printf("%s", wm->data);

  free(image);
  free(wm);

  return 0;
}