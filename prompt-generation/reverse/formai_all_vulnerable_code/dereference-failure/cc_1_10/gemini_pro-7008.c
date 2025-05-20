//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1024 * 1024 * 3
#define MAX_WATERMARK_SIZE 1024 * 1024

#define LSB_MASK 0x01

typedef struct {
  unsigned char *data;
  int width;
  int height;
  int channels;
} Image;

Image *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open file %s\n", filename);
    return NULL;
  }

  Image *image = malloc(sizeof(Image));
  if (image == NULL) {
    fprintf(stderr, "Error: could not allocate memory for image\n");
    fclose(fp);
    return NULL;
  }

  fread(&image->width, sizeof(int), 1, fp);
  fread(&image->height, sizeof(int), 1, fp);
  fread(&image->channels, sizeof(int), 1, fp);

  int data_size = image->width * image->height * image->channels;
  image->data = malloc(data_size);
  if (image->data == NULL) {
    fprintf(stderr, "Error: could not allocate memory for image data\n");
    fclose(fp);
    free(image);
    return NULL;
  }

  fread(image->data, data_size, 1, fp);
  fclose(fp);

  return image;
}

void save_image(const Image *image, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open file %s\n", filename);
    return;
  }

  fwrite(&image->width, sizeof(int), 1, fp);
  fwrite(&image->height, sizeof(int), 1, fp);
  fwrite(&image->channels, sizeof(int), 1, fp);

  int data_size = image->width * image->height * image->channels;
  fwrite(image->data, data_size, 1, fp);
  fclose(fp);
}

Image *create_watermark(const char *message) {
  int message_length = strlen(message);
  int watermark_size = message_length * 8;

  Image *watermark = malloc(sizeof(Image));
  if (watermark == NULL) {
    fprintf(stderr, "Error: could not allocate memory for watermark\n");
    return NULL;
  }

  watermark->width = watermark_size;
  watermark->height = 1;
  watermark->channels = 3;
  watermark->data = malloc(watermark_size * 3);
  if (watermark->data == NULL) {
    fprintf(stderr, "Error: could not allocate memory for watermark data\n");
    free(watermark);
    return NULL;
  }

  for (int i = 0; i < watermark_size * 3; i += 3) {
    int byte = message[i / 3];
    for (int j = 0; j < 8; j++) {
      int bit = (byte >> j) & LSB_MASK;
      watermark->data[i + j] = 0;
      watermark->data[i + j + 1] = 0;
      watermark->data[i + j + 2] = 255 * bit;
    }
  }

  return watermark;
}

void embed_watermark(Image *image, Image *watermark) {
  int watermark_size = watermark->width * watermark->height * watermark->channels;
  int data_size = image->width * image->height * image->channels;

  if (watermark_size > data_size) {
    fprintf(stderr, "Error: watermark is too large for image\n");
    return;
  }

  for (int i = 0; i < watermark_size; i++) {
    for (int j = 0; j < 8; j++) {
      int index = i * 8 + j;
      int bit = watermark->data[index] & LSB_MASK;
      image->data[index] = (image->data[index] & ~LSB_MASK) | bit;
    }
  }
}

Image *extract_watermark(const Image *image) {
  int watermark_size = image->width * image->height * image->channels / 8;

  Image *watermark = malloc(sizeof(Image));
  if (watermark == NULL) {
    fprintf(stderr, "Error: could not allocate memory for watermark\n");
    return NULL;
  }

  watermark->width = watermark_size;
  watermark->height = 1;
  watermark->channels = 3;
  watermark->data = malloc(watermark_size * 3);
  if (watermark->data == NULL) {
    fprintf(stderr, "Error: could not allocate memory for watermark data\n");
    free(watermark);
    return NULL;
  }

  for (int i = 0; i < watermark_size * 3; i += 3) {
    int byte = 0;
    for (int j = 0; j < 8; j++) {
      int index = i * 8 + j;
      int bit = image->data[index] & LSB_MASK;
      byte |= bit << j;
    }

    watermark->data[i] = 0;
    watermark->data[i + 1] = 0;
    watermark->data[i + 2] = byte;
  }

  return watermark;
}

int main(int argc, char **argv) {
  if (argc < 5) {
    fprintf(stderr, "Usage: %s <image_file> <watermark_message> <output_file> <embed/extract>\n", argv[0]);
    return 1;
  }

  const char *image_file = argv[1];
  const char *watermark_message = argv[2];
  const char *output_file = argv[3];
  const char *operation = argv[4];

  Image *image = NULL;
  Image *watermark = NULL;

  if (strcmp(operation, "embed") == 0) {
    image = load_image(image_file);
    if (image == NULL) {
      return 1;
    }

    watermark = create_watermark(watermark_message);
    if (watermark == NULL) {
      free(image);
      return 1;
    }

    embed_watermark(image, watermark);
    save_image(image, output_file);

    free(image);
    free(watermark);
  } else if (strcmp(operation, "extract") == 0) {
    image = load_image(image_file);
    if (image == NULL) {
      return 1;
    }

    watermark = extract_watermark(image);
    if (watermark == NULL) {
      free(image);
      return 1;
    }

    for (int i = 0; i < watermark->width; i++) {
      for (int j = 0; j < 3; j++) {
        if (watermark->data[i * 3 + j] != 0) {
          printf("%c", watermark->data[i * 3 + j]);
        }
      }
    }

    printf("\n");

    free(image);
    free(watermark);
  } else {
    fprintf(stderr, "Error: invalid operation\n");
    return 1;
  }

  return 0;
}