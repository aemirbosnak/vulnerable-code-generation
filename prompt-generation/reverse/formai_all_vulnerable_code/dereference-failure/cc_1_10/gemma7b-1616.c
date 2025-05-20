//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_SIZE 256

typedef struct watermark_t {
  int size;
  unsigned char *data;
} watermark_t;

void watermark_init(watermark_t *wm, int size) {
  wm->size = size;
  wm->data = malloc(size);
}

void watermark_add(watermark_t *wm, unsigned char *data, int data_size) {
  int i, j, k;
  for (i = 0; i < data_size && i < wm->size; i++) {
    for (j = 0; j < wm->size && j < data_size; j++) {
      k = (i + j) % wm->size;
      wm->data[k] ^= data[j];
    }
  }
}

int watermark_detect(watermark_t *wm, unsigned char *data, int data_size) {
  int i, j, k;
  for (i = 0; i < data_size && i < wm->size; i++) {
    for (j = 0; j < wm->size && j < data_size; j++) {
      k = (i + j) % wm->size;
      if (wm->data[k] != data[j]) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
   watermark_t wm;
  watermark_init(&wm, MAX_WATERMARK_SIZE);

  unsigned char data[] = "This is the secret message.";
  int data_size = sizeof(data) - 1;

  watermark_add(&wm, data, data_size);

  unsigned char data_copy[] = "This is the secret message also.";
  int data_copy_size = sizeof(data_copy) - 1;

  if (watermark_detect(&wm, data_copy, data_copy_size)) {
    printf("Watermarked data is detected.\n");
  } else {
    printf("Watermarked data is not detected.\n");
  }

  return 0;
}