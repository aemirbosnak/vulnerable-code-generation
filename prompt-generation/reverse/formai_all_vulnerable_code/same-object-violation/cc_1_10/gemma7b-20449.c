//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_LENGTH 256

typedef struct Watermark
{
  char *data;
  int length;
} Watermark;

Watermark watermark_create(int length)
{
  Watermark watermark;
  watermark.data = malloc(length);
  watermark.length = length;
  return watermark;
}

void watermark_add(Watermark watermark, char data)
{
  if (watermark.length > watermark.data)
  {
    return;
  }
  watermark.data[watermark.length++] = data;
}

int watermark_get(Watermark watermark)
{
  return watermark.length;
}

int main()
{
  Watermark watermark = watermark_create(MAX_WATERMARK_LENGTH);

  // Add watermarks
  watermark_add(watermark, 'A');
  watermark_add(watermark, 'B');
  watermark_add(watermark, 'C');

  // Get watermarks
  int num_watermarks = watermark_get(watermark);
  for (int i = 0; i < num_watermarks; i++)
  {
    printf("%c ", watermark.data[i]);
  }

  return 0;
}