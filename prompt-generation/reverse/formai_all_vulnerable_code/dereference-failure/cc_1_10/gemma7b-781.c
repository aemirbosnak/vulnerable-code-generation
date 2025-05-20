//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_LENGTH 256

typedef struct watermark_t {
  char data[MAX_WATERMARK_LENGTH];
  int length;
} watermark_t;

 watermark_t* watermark_create(int length)
{
  watermark_t* watermark = malloc(sizeof(watermark_t));
  watermark->length = length;
  memset(watermark->data, 0, MAX_WATERMARK_LENGTH);
  return watermark;
}

void watermark_add(watermark_t* watermark, char* data, int data_length)
{
  int i = 0;
  for (i = 0; i < data_length && i < watermark->length; i++) {
    watermark->data[i] = data[i];
  }
  watermark->length = data_length;
}

int watermark_verify(watermark_t* watermark, char* data, int data_length)
{
  int i = 0;
  for (i = 0; i < watermark->length && i < data_length; i++) {
    if (watermark->data[i] != data[i]) {
      return 0;
    }
  }
  return 1;
}

int main()
{
  char* data = "This is the secret message";
  int data_length = strlen(data);

  watermark_t* watermark = watermark_create(data_length);
  watermark_add(watermark, data, data_length);

  char* watermark_data = "This is the hidden watermark";
  int watermark_length = strlen(watermark_data);

  if (watermark_verify(watermark, watermark_data, watermark_length)) {
    printf("The watermark is valid.\n");
  } else {
    printf("The watermark is not valid.\n");
  }

  return 0;
}