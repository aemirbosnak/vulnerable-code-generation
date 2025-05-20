//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_LENGTH 1024

typedef struct watermark_t {
  char *data;
  int length;
} watermark_t;

void watermark_init(watermark_t *w, char *data, int length) {
  w->data = malloc(length);
  w->length = length;
  memcpy(w->data, data, length);
}

void watermark_insert(watermark_t *w, char *data, int length) {
  if (w->length + length > MAX_WATERMARK_LENGTH) {
    return;
  }
  w->data = realloc(w->data, w->length + length);
  memcpy(w->data + w->length, data, length);
  w->length += length;
}

int watermark_search(watermark_t *w, char *data) {
  int i = 0;
  for (i = 0; i < w->length && strcmp(w->data + i, data) != 0; i++) {}
  return i;
}

int main() {
   watermark_t watermark;
  char *data = "This is a secret message";
  int data_length = strlen(data) + 1;

  watermark_init(&watermark, data, data_length);

  char *additional_data = "This is additional data";
  int additional_data_length = strlen(additional_data) + 1;

  watermark_insert(&watermark, additional_data, additional_data_length);

  char *search_data = "This is the secret message";

  int search_result = watermark_search(&watermark, search_data);

  if (search_result != -1) {
    printf("Secret message found at index %d\n", search_result);
  } else {
    printf("Secret message not found\n");
  }

  return 0;
}