//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_SIZE 1024

typedef struct watermark_t {
  int size;
  unsigned char *data;
} watermark_t;

 watermark_t *create_watermark(int size) {
   watermark_t *wm = malloc(sizeof(watermark_t));
  wm->size = size;
  wm->data = malloc(size);
  return wm;
}

void embed_watermark( watermark_t *wm, unsigned char *image, int image_size) {
  int i, j;
  for (i = 0; i < wm->size; i++) {
    for (j = 0; j < image_size; j++) {
      image[j] = (image[j] + wm->data[i]) % 256;
    }
  }
}

void extract_watermark( watermark_t *wm, unsigned char *image, int image_size) {
  int i, j;
  for (i = 0; i < wm->size; i++) {
    for (j = 0; j < image_size; j++) {
      wm->data[i] = (image[j] - image[j] % 256) / wm->size;
    }
  }
}

int main() {
  unsigned char image[] = "image.jpg";
  int image_size = 1000000;

   watermark_t *wm = create_watermark(MAX_WATERMARK_SIZE);
  wm->data = "Secret message";

  embed_watermark(wm, image, image_size);

  extract_watermark(wm, image, image_size);

  printf("%s", wm->data);

  free(wm->data);
  free(wm);

  return 0;
}