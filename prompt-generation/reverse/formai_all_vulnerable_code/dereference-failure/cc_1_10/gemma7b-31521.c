//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WATERMARK_SIZE 256

typedef struct watermark_data {
  int size;
  char *data;
} watermark_data_t;

 watermark_data_t *create_watermark(int size) {
   watermark_data_t *wm_data = malloc(sizeof(watermark_data_t));
  wm_data->size = size;
  wm_data->data = malloc(size);
  return wm_data;
}

void embed_watermark( watermark_data_t *wm_data, char *image, int image_size) {
  for (int i = 0; i < wm_data->size; i++) {
    int index = rand() % image_size;
    image[index] ^= wm_data->data[i];
  }
}

void extract_watermark( watermark_data_t *wm_data, char *image, int image_size) {
  for (int i = 0; i < wm_data->size; i++) {
    int index = rand() % image_size;
    if (image[index] ^ wm_data->data[i] == 0) {
      wm_data->data[i] = 1;
    } else {
      wm_data->data[i] = 0;
    }
  }
}

int main() {
  // Create a watermark
  watermark_data_t *wm_data = create_watermark(64);
  wm_data->data[0] = 1;
  wm_data->data[1] = 1;
  wm_data->data[2] = 1;

  // Embed the watermark into an image
  char *image = malloc(1024);
  image[0] = 255;
  image[1] = 255;
  embed_watermark(wm_data, image, 1024);

  // Extract the watermark from the image
  extract_watermark(wm_data, image, 1024);

  // Check if the watermark has been extracted
  for (int i = 0; i < wm_data->size; i++) {
    if (wm_data->data[i] != 1) {
      printf("Watermark not extracted!\n");
      return 1;
    }
  }

  printf("Watermark extracted successfully!\n");
  return 0;
}