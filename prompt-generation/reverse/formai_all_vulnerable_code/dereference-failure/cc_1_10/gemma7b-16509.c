//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define MAX_WATERMARK_LENGTH 256

typedef struct watermark_t {
  char *data;
  int length;
} watermark_t;

void watermark_init(watermark_t *w, int length) {
  w->data = malloc(length);
  w->length = length;
}

void watermark_add(watermark_t *w, char *data, int data_length) {
  if (w->length < data_length) {
    printf("Error: watermark length too small.\n");
    return;
  }

  memcpy(w->data, data, data_length);
  w->length = data_length;
}

void watermark_extract(watermark_t *w, char **data) {
  if (w->length > 0) {
    *data = malloc(w->length);
    memcpy(*data, w->data, w->length);
  } else {
    *data = NULL;
  }
}

int main() {
   watermark_t w;
  watermark_init(&w, MAX_WATERMARK_LENGTH);

  char *data = "This is the watermarked data.";
  watermark_add(&w, data, strlen(data));

  char *extracted_data;
  watermark_extract(&w, &extracted_data);

  if (extracted_data) {
    printf("Extracted data: %s\n", extracted_data);
  } else {
    printf("No extracted data.\n");
  }

  return 0;
}