//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_LENGTH 256

typedef struct watermark_data {
  char *data;
  int length;
  int strength;
} watermark_data;

 watermark_data* watermark_create(int length, int strength) {
  watermark_data *wm = ( watermark_data *)malloc(sizeof(watermark_data));
  wm->data = (char *)malloc(length * sizeof(char));
  wm->length = length;
  wm->strength = strength;
  return wm;
}

int watermark_insert( watermark_data *wm, char *water_mark) {
  int i = 0;
  for (i = 0; i < wm->length && water_mark[i] != '\0'; i++) {
    wm->data[i] = water_mark[i] ^ wm->strength;
  }
  return 0;
}

int watermark_extract( watermark_data *wm, char **extracted_water_mark) {
  int i = 0;
  *extracted_water_mark = (char *)malloc((wm->length + 1) * sizeof(char));
  for (i = 0; i < wm->length && wm->data[i] != '\0'; i++) {
    (*extracted_water_mark)[i] = wm->data[i] ^ wm->strength;
  }
  (*extracted_water_mark)[wm->length] = '\0';
  return 0;
}

int main() {
  // Create a watermark
  watermark_data *wm = watermark_create(10, 5);
  wm->data[0] = 'A';
  wm->data[1] = 'B';
  wm->data[2] = 'C';

  // Insert the watermark into a file
  FILE *fp = fopen("test.txt", "w");
  fprintf(fp, "This is a file with a watermark.");
  fclose(fp);

  // Add the watermark to the file
   watermark_insert(wm, "SECRET WATERMARK");

  // Extract the watermark from the file
  char *extracted_water_mark = NULL;
  watermark_extract(wm, &extracted_water_mark);

  // Print the extracted watermark
  printf("Extracted watermark: %s", extracted_water_mark);

  return 0;
}