//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 8

typedef struct {
  unsigned char *data;
  size_t size;
} Data;

typedef struct {
  unsigned char *watermark;
  size_t size;
} Watermark;

Data *read_data(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  Data *data = malloc(sizeof(Data));
  data->data = malloc(size);
  data->size = size;
  fread(data->data, 1, size, fp);
  fclose(fp);

  return data;
}

void write_data(const char *filename, Data *data) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    return;
  }

  fwrite(data->data, 1, data->size, fp);
  fclose(fp);
}

Watermark *read_watermark(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  Watermark *watermark = malloc(sizeof(Watermark));
  watermark->watermark = malloc(size);
  watermark->size = size;
  fread(watermark->watermark, 1, size, fp);
  fclose(fp);

  return watermark;
}

void embed_watermark(Data *data, Watermark *watermark) {
  int bits_per_byte = 8 / MAX_BITS;
  for (size_t i = 0; i < watermark->size; i++) {
    for (int j = 0; j < bits_per_byte; j++) {
      unsigned char bit = (watermark->watermark[i] >> (j * MAX_BITS)) & (MAX_BITS - 1);
      data->data[i] = (data->data[i] & ~(MAX_BITS - 1)) | (bit << j);
    }
  }
}

Watermark *extract_watermark(Data *data, size_t watermark_size) {
  int bits_per_byte = 8 / MAX_BITS;
  Watermark *watermark = malloc(sizeof(Watermark));
  watermark->watermark = malloc(watermark_size);
  watermark->size = watermark_size;
  for (size_t i = 0; i < watermark_size; i++) {
    for (int j = 0; j < bits_per_byte; j++) {
      unsigned char bit = (data->data[i] >> (j * MAX_BITS)) & (MAX_BITS - 1);
      watermark->watermark[i] |= (bit << (j * MAX_BITS));
    }
  }
  return watermark;
}

int main(int argc, char *argv[]) {
  if (argc < 5) {
    fprintf(stderr, "Usage: %s <input_file> <output_file> <watermark_file> <watermark_size>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *input_file = argv[1];
  char *output_file = argv[2];
  char *watermark_file = argv[3];
  size_t watermark_size = atoi(argv[4]);

  Data *data = read_data(input_file);
  if (!data) {
    return EXIT_FAILURE;
  }

  Watermark *watermark = read_watermark(watermark_file);
  if (!watermark) {
    return EXIT_FAILURE;
  }

  if (watermark_size > data->size) {
    fprintf(stderr, "Watermark size cannot be greater than data size\n");
    return EXIT_FAILURE;
  }

  embed_watermark(data, watermark);
  write_data(output_file, data);
  free(data->data);
  free(data);
  free(watermark->watermark);
  free(watermark);

  return EXIT_SUCCESS;
}