//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_SIZE 1024

typedef struct watermark_data {
  char *data;
  int size;
  int capacity;
} watermark_data;

void watermark_init(watermark_data *data) {
  data->data = malloc(MAX_WATERMARK_SIZE);
  data->size = 0;
  data->capacity = MAX_WATERMARK_SIZE;
}

void watermark_add(watermark_data *data, char *watermark) {
  int watermark_length = strlen(watermark);
  if (data->size + watermark_length > data->capacity) {
    return;
  }

  memcpy(data->data + data->size, watermark, watermark_length);
  data->size += watermark_length;
}

void watermark_print(watermark_data *data) {
  printf("Watermarks:\n");
  for (int i = 0; i < data->size; i++) {
    printf("%c ", data->data[i]);
  }
  printf("\n");
}

int main() {
  watermark_data watermark_data;
  watermark_init(&watermark_data);

  char *watermarks[] = {"This is the first watermark.", "This is the second watermark.", "This is the third watermark."};

  for (int i = 0; i < 3; i++) {
    watermark_add(&watermark_data, watermarks[i]);
  }

  watermark_print(&watermark_data);

  return 0;
}