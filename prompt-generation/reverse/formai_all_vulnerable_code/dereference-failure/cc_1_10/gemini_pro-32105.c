//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 32

typedef struct {
  unsigned char *data;
  size_t size;
} Buffer;

Buffer *read_file(const char *filename) {
  FILE *fp;
  Buffer *buffer;

  fp = fopen(filename, "rb");
  if (fp == NULL) {
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  buffer = malloc(sizeof(Buffer));
  buffer->data = malloc(size);
  buffer->size = size;

  fread(buffer->data, size, 1, fp);
  fclose(fp);

  return buffer;
}

void write_file(const char *filename, Buffer *buffer) {
  FILE *fp;

  fp = fopen(filename, "wb");
  if (fp == NULL) {
    return;
  }

  fwrite(buffer->data, buffer->size, 1, fp);
  fclose(fp);
}

Buffer *embed_watermark(Buffer *buffer, const char *watermark) {
  Buffer *new_buffer;
  size_t i, j;

  new_buffer = malloc(sizeof(Buffer));
  new_buffer->data = malloc(buffer->size + WATERMARK_SIZE);
  new_buffer->size = buffer->size + WATERMARK_SIZE;

  for (i = 0; i < buffer->size; i++) {
    new_buffer->data[i] = buffer->data[i];
  }

  for (j = 0; j < WATERMARK_SIZE; j++) {
    new_buffer->data[i + j] = watermark[j];
  }

  return new_buffer;
}

Buffer *extract_watermark(Buffer *buffer) {
  Buffer *watermark;

  watermark = malloc(sizeof(Buffer));
  watermark->data = malloc(WATERMARK_SIZE);
  watermark->size = WATERMARK_SIZE;

  memcpy(watermark->data, buffer->data + buffer->size - WATERMARK_SIZE, WATERMARK_SIZE);

  return watermark;
}

int main(int argc, char *argv[]) {
  Buffer *buffer, *watermarked_buffer, *watermark;

  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input file> <output file> <watermark>\n", argv[0]);
    return 1;
  }

  buffer = read_file(argv[1]);
  if (buffer == NULL) {
    fprintf(stderr, "Error reading input file\n");
    return 1;
  }

  watermarked_buffer = embed_watermark(buffer, argv[3]);
  write_file(argv[2], watermarked_buffer);

  watermark = extract_watermark(watermarked_buffer);
  printf("Watermark: %s\n", watermark->data);

  free(buffer);
  free(watermarked_buffer);
  free(watermark);

  return 0;
}