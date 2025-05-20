//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WATERMARK_SIZE 1024

typedef struct watermark_t {
  char *data;
  int size;
} watermark_t;

void watermark_init(watermark_t *w, char *data, int size) {
  w->data = malloc(size);
  w->size = size;
  memcpy(w->data, data, size);
}

void watermark_insert(watermark_t *w, char *data, int size) {
  if (w->size - w->size % WATERMARK_SIZE < size) {
    return;
  }

  int i, j;
  for (i = 0; i < size; i++) {
    for (j = 0; j < WATERMARK_SIZE; j++) {
      if (w->data[j] == data[i]) {
        w->data[j] ^= 0x12;
      }
    }
  }
}

int watermark_detect(watermark_t *w, char *data, int size) {
  int i, j, count = 0;
  for (i = 0; i < size; i++) {
    for (j = 0; j < WATERMARK_SIZE; j++) {
      if (w->data[j] == data[i]) {
        w->data[j] ^= 0x12;
        count++;
      }
    }
  }

  return count;
}

int main() {
  char *data = "This is the original data";
  int data_size = strlen(data) + 1;

  watermark_t w;
  watermark_init(&w, data, data_size);

  char *watermarked_data = "This is the watermarked data";
  int watermarked_size = strlen(watermarked_data) + 1;

   watermark_insert(&w, watermarked_data, watermarked_size);

  int count = watermark_detect(&w, watermarked_data, watermarked_size);

  printf("Number of watermarks detected: %d\n", count);

  return 0;
}