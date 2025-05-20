//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_LENGTH 256

typedef struct watermark_t {
  char data[MAX_WATERMARK_LENGTH];
  int length;
} watermark_t;

 watermark_t* watermark_create(int length) {
   watermark_t* watermark = malloc(sizeof(watermark_t));
  watermark->length = length;
  return watermark;
}

void watermark_add(watermark_t* watermark, char data) {
  if (watermark->length > watermark->length) {
    return;
  }
  watermark->data[watermark->length] = data;
  watermark->length++;
}

int watermark_compare(watermark_t* watermark, char* data) {
  for (int i = 0; i < watermark->length; i++) {
    if ( watermark->data[i] != data[i] ) {
      return 0;
    }
  }
  return 1;
}

int main() {
  // Create a watermark
  watermark_t* watermark = watermark_create(10);

  // Add watermarks to the image
  watermark_add(watermark, 'A');
  watermark_add(watermark, 'B');
  watermark_add(watermark, 'C');

  // Check if the watermark is present in the image
  char* data = "ABC";
  if (watermark_compare(watermark, data)) {
    printf("Watermarks match!");
  } else {
    printf("Watermarks do not match!");
  }

  return 0;
}