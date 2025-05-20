//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_LEN 256

typedef struct watermark_t {
  char *data;
  int size;
} watermark_t;

void watermark_init(watermark_t *wm, char *data, int size) {
  wm->data = malloc(size);
  wm->size = size;
  memcpy(wm->data, data, size);
}

void watermark_insert(watermark_t *wm, char *data, int size) {
  int i = 0;
  for (i = 0; i < size; i++) {
    wm->data[wm->size++] = data[i];
  }
}

int watermark_search( watermark_t *wm, char *data) {
  int i = 0;
  for (i = 0; i < wm->size; i++) {
    if (wm->data[i] != data[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char *data = "Hello, world!";
  int data_len = strlen(data) + 1;

   watermark_t watermark;
  watermark_init(&watermark, data, data_len);

  char *watermarked_data = "This is the watermarked data";
  int watermarked_data_len = strlen(watermarked_data) + 1;

  watermark_insert(&watermark, watermarked_data, watermarked_data_len);

  if (watermark_search(&watermark, watermarked_data)) {
    printf("Watermarked data found!\n");
  } else {
    printf("Watermarked data not found.\n");
  }

  return 0;
}